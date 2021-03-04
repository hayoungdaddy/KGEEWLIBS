#include "kgeewlibs.h"

#include <QtConcurrent>


static QMultiMap<int, _QSCD_FOR_MULTIMAP> convertQSCD100PacketToMMap(char *msg)
{
    QMultiMap<int, _QSCD_FOR_MULTIMAP> mmap;
    _QSCD100_PACKET QSCD100Packet;
    memcpy(&QSCD100Packet, msg, sizeof(QSCD100Packet));
    char sta[STA_LEN];
    char net[NET_LEN];
    memset(sta,0x00,STA_LEN);
    memset(net,0x00,NET_LEN);
    strncpy(sta, QSCD100Packet.sta, STA_LEN);
    strncpy(net, QSCD100Packet.net, NET_LEN);

    _QSCD_FOR_MULTIMAP qfmm;
    qfmm.netSta = QString(net) + QString(sta);

    //SwapInt(&QSCD100Packet.qscd.time);    // epoch time (GMT)
    SwapFloat(&QSCD100Packet.qscd.ZMax);
    SwapFloat(&QSCD100Packet.qscd.NMax);
    SwapFloat(&QSCD100Packet.qscd.EMax);
    SwapFloat(&QSCD100Packet.qscd.HPGA);
    SwapFloat(&QSCD100Packet.qscd.TPGA);

    qfmm.pga[0] = QSCD100Packet.qscd.ZMax;
    qfmm.pga[1] = QSCD100Packet.qscd.NMax;
    qfmm.pga[2] = QSCD100Packet.qscd.EMax;
    qfmm.pga[3] = QSCD100Packet.qscd.HPGA;
    qfmm.pga[4] = QSCD100Packet.qscd.TPGA;

    mmap.insert(QSCD100Packet.time, qfmm);

    return mmap;
}


static QMultiMap<int, _QSCD_FOR_MULTIMAP> convertQSCD20BlockToMMap(char *msg, bool isKISS, QString type)
{
    QMultiMap<int, _QSCD_FOR_MULTIMAP> mmap;
    _QSCD20_PACKET QSCDBlock[NUM_FOR_QSCD_BLOCK];
    memcpy(&QSCDBlock[0], msg, sizeof(QSCDBlock));
    char sta[6];
    char net[3];
    memset(sta,0x00,6);
    memset(net,0x00,3);

    for(int i=0;i<NUM_FOR_QSCD_BLOCK;i++)
    {
        strncpy(sta, QSCDBlock[i].SSSSS, 5);
        strncpy(net, QSCDBlock[i].LO, 2);

        _QSCD_FOR_MULTIMAP qfmm;

        if(isKISS)
            qfmm.netSta = QString(net) + QString(sta);
        else
        {
            qfmm.netSta = QString(sta);
            if(!type.startsWith("ALL"))
            {
                if(!qfmm.netSta.right(1).startsWith(type.left(1)))
                    continue;
            }
        }

        SwapInt(&QSCDBlock[i].time);    // epoch time (GMT)
        SwapFloat(&QSCDBlock[i].ZMax);
        SwapFloat(&QSCDBlock[i].NMax);
        SwapFloat(&QSCDBlock[i].EMax);
        SwapFloat(&QSCDBlock[i].HPGA);
        SwapFloat(&QSCDBlock[i].TPGA);

        qfmm.pga[0] = QSCDBlock[i].ZMax;
        qfmm.pga[1] = QSCDBlock[i].NMax;
        qfmm.pga[2] = QSCDBlock[i].EMax;
        qfmm.pga[3] = QSCDBlock[i].HPGA;
        qfmm.pga[4] = QSCDBlock[i].TPGA;

        mmap.insert(QSCDBlock[i].time, qfmm);
    }

    return mmap;
}


// RecvQSCD20Message
RecvQSCD20Message::RecvQSCD20Message(QWidget *parent)
{
}

RecvQSCD20Message::~RecvQSCD20Message()
{
    cleanUp();
}

void RecvQSCD20Message::setup(QString qBrokerURI, QString qID, QString qPW,
                        QString qTopic, bool useTopic, bool clientAck, QString networkName, QString staType)
{
    auto_ptr<ConnectionFactory> connectionFactory(ConnectionFactory::createCMSConnectionFactory( qBrokerURI.toStdString() ) );

    if(qID == "" || qPW == "")
    {
        connection = connectionFactory->createConnection();
    }
    else
    {
        connection = connectionFactory->createConnection(qID.toStdString(), qPW.toStdString());
    }

    connection->start();

    if(networkName.startsWith("KISS"))
        isKISS = true;
    else
        isKISS = false;

    type = staType;

    // Create a Session
    session = connection->createSession( Session::AUTO_ACKNOWLEDGE );

    useTopic = true;

    // Create the destination (Topic or Queue)
    if( useTopic ) {
        destination = session->createTopic( qTopic.toStdString() );
    } else {
        destination = session->createQueue( qTopic.toStdString() );
    }
    consumer = session->createConsumer (destination);
}

void RecvQSCD20Message::run()
{
    while (this->isRunning())
    {
        if(this->isInterruptionRequested())
            this->quit();

        auto_ptr<Message> message( consumer->receive() );

        if( message.get() != NULL )
        {
            const BytesMessage* bytes_message = dynamic_cast< const BytesMessage* >( message.get() );
            char *msg = (char *)bytes_message->getBodyBytes();

            QFuture<QMultiMap<int, _QSCD_FOR_MULTIMAP>> future = QtConcurrent::run(convertQSCD20BlockToMMap, msg, isKISS, type);
            future.waitForFinished();
            emit sendQSCDtoMain(future.result());

            free(msg);
        }
    }
}

void RecvQSCD20Message::cleanUp()
{
    if (connection != 0)
        connection->close();

    delete destination;
    destination = 0;
    delete consumer;
    consumer = 0;
    delete session;
    session = 0;
    delete connection;
}




// RecvQSCD100Message
RecvQSCD100Message::RecvQSCD100Message(QWidget *parent)
{
}

RecvQSCD100Message::~RecvQSCD100Message()
{
    cleanUp();
}

void RecvQSCD100Message::setup(QString qBrokerURI, QString qID, QString qPW,
                        QString qTopic, bool useTopic, bool clientAck)
{
    auto_ptr<ConnectionFactory> connectionFactory(ConnectionFactory::createCMSConnectionFactory( qBrokerURI.toStdString() ) );

    if(qID == "" || qPW == "")
    {
        connection = connectionFactory->createConnection();
    }
    else
    {
        connection = connectionFactory->createConnection(qID.toStdString(), qPW.toStdString());
    }

    connection->start();

    // Create a Session
    session = connection->createSession( Session::AUTO_ACKNOWLEDGE );

    useTopic = true;

    // Create the destination (Topic or Queue)
    if( useTopic ) {
        destination = session->createTopic( qTopic.toStdString() );
    } else {
        destination = session->createQueue( qTopic.toStdString() );
    }
    consumer = session->createConsumer (destination);
}

void RecvQSCD100Message::run()
{
    while (this->isRunning())
    {
        if(this->isInterruptionRequested())
            this->quit();

        auto_ptr<Message> message( consumer->receive() );

        if( message.get() != NULL )
        {
            const BytesMessage* bytes_message = dynamic_cast< const BytesMessage* >( message.get() );
            char *msg = (char *)bytes_message->getBodyBytes();

            QFuture<QMultiMap<int, _QSCD_FOR_MULTIMAP>> future = QtConcurrent::run(convertQSCD100PacketToMMap, msg);
            future.waitForFinished();
            emit sendQSCDtoMain(future.result());

            free(msg);
        }
    }
}

void RecvQSCD100Message::cleanUp()
{
    if (connection != 0)
        connection->close();

    delete destination;
    destination = 0;
    delete consumer;
    consumer = 0;
    delete session;
    session = 0;
    delete connection;
}




// RecvEEWMessage
RecvEEWMessage::RecvEEWMessage(QWidget *parent)
{
}

RecvEEWMessage::~RecvEEWMessage()
{
    cleanUp();
}

void RecvEEWMessage::setup(QString qBrokerURI, QString qID, QString qPW, QString qTopic, bool useTopic, bool clientAck)
{
    auto_ptr<ConnectionFactory> connectionFactory(ConnectionFactory::createCMSConnectionFactory( qBrokerURI.toStdString() ));

    if(qID == "" || qPW == "")
        connection = connectionFactory->createConnection();
    else
        connection = connectionFactory->createConnection(qID.toStdString(), qPW.toStdString());

    connection->start();

    // Create a Session
    if( clientAck ) {
        session = connection->createSession( Session::CLIENT_ACKNOWLEDGE );
    } else {
        session = connection->createSession( Session::AUTO_ACKNOWLEDGE );
    }

    useTopic = true;

    // Create the destination (Topic or Queue)
    if( useTopic ) {
        destination = session->createTopic( qTopic.toStdString() );
    } else {
        destination = session->createQueue( qTopic.toStdString() );
    }

    consumer = session->createConsumer (destination);
}

void RecvEEWMessage::run()
{
    while (this->isRunning())
    {
        if(this->isInterruptionRequested())
            this->quit();

        auto_ptr<Message> message (consumer->receive() );
        if( message.get() != 0 )
        {
            const TextMessage *m = dynamic_cast< const TextMessage* >( message.get() );
            QString xmlbody = QString::fromStdString(m->getText());

            _EEWINFO _eewinfo;

            xmlbody = xmlbody.simplified();
            xmlbody.replace(QString("\n"), QString(""));

            QXmlStreamReader xml(xmlbody);
            while(!xml.atEnd() && !xml.hasError())
            {
                xml.readNext();
                if(xml.name() == "event_message")
                {
                    QXmlStreamAttributes attributes = xml.attributes();
                    if(attributes.value("category").toString().startsWith("live"))
                        _eewinfo.message_category = LIVE;
                    else
                        _eewinfo.message_category = TEST;

                    if(attributes.value("message_type").toString().startsWith("new"))
                        _eewinfo.message_type = NEW;
                    else if(attributes.value("message_type").toString().startsWith("update"))
                        _eewinfo.message_type = UPDATE;
                    else
                        _eewinfo.message_type = DELETE;

                    _eewinfo.version = attributes.value("version").toInt();
                }
                else if(xml.name() == "core_info")
                {
                    QXmlStreamAttributes attributes = xml.attributes();
                    if(attributes.hasAttribute("id"))
                        _eewinfo.eew_evid = attributes.value("id").toInt();
                }
                else if(xml.name() == "mag")
                {
                    xml.readNext();
                    QString temp = xml.text().toString();
                    if(!temp.startsWith(" "))
                        _eewinfo.magnitude = temp.toFloat();
                }
                else if(xml.name() == "lat")
                {
                    xml.readNext();
                    QString temp = xml.text().toString();
                    if(!temp.startsWith(" "))
                        _eewinfo.latitude = temp.toFloat();
                }
                else if(xml.name() == "lon")
                {
                    xml.readNext();
                    QString temp = xml.text().toString();
                    if(!temp.startsWith(" "))
                        _eewinfo.longitude = temp.toFloat();
                }
                else if(xml.name() == "depth")
                {
                    xml.readNext();
                    QString temp = xml.text().toString();
                    if(!temp.startsWith(" "))
                        _eewinfo.depth = temp.toFloat();
                }
                else if(xml.name() == "orig_time")
                {
                    xml.readNext();
                    QString temp = xml.text().toString();
                    if(!temp.startsWith(" "))
                    {
                        QDateTime dt = QDateTime::fromString(temp, "yyyy-MM-ddThh:mm:ss.zzzZ");
                        dt.setTimeSpec(Qt::UTC);
                        _eewinfo.origintime = dt.toTime_t();
                    }
                }
                else if(xml.name() == "num_stations")
                {
                    xml.readNext();
                    QString temp = xml.text().toString();
                    if(!temp.startsWith(" "))
                        _eewinfo.number_stations = temp.toInt();
                }
            }

            emit _rvEEWInfo(_eewinfo);
        }
    }
}

void RecvEEWMessage::cleanUp()
{
    if (connection != 0)
        connection->close();

    delete destination;
    destination = 0;
    delete consumer;
    consumer = 0;
    delete session;
    session = 0;
    delete connection;
}
