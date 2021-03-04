#ifndef KGEEWLIBS_H
#define KGEEWLIBS_H

#include "KGEEWLIBS_global.h"

#include <QThread>
#include <QMultiMap>

#include <decaf/lang/Thread.h>
#include <decaf/lang/Runnable.h>
#include <decaf/util/concurrent/CountDownLatch.h>
#include <activemq/core/ActiveMQConnectionFactory.h>
#include <activemq/core/ActiveMQConnection.h>
#include <activemq/transport/DefaultTransportListener.h>
#include <activemq/library/ActiveMQCPP.h>
#include <decaf/lang/Integer.h>
#include <activemq/util/Config.h>
#include <decaf/util/Date.h>
#include <cms/Connection.h>
#include <cms/Session.h>
#include <cms/TextMessage.h>
#include <cms/BytesMessage.h>
#include <cms/MapMessage.h>
#include <cms/ExceptionListener.h>
#include <cms/MessageListener.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include <QXmlStreamReader>
#include <QXmlStreamAttributes>

using namespace activemq;
using namespace activemq::core;
using namespace activemq::transport;
using namespace decaf::lang;
using namespace decaf::util;
using namespace decaf::util::concurrent;
using namespace cms;
using namespace std;


class RecvQSCD20Message : public QThread
{
    Q_OBJECT
public:
    RecvQSCD20Message(QWidget *parent = nullptr);
    ~RecvQSCD20Message();

public:
    void setup(QString, QString, QString, QString, bool, bool, QString, QString);

private:
    Connection *connection;
    Session *session;
    Destination *destination;
    MessageConsumer *consumer;
    bool isKISS;
    QString type;   // G or B or T

    QMultiMap<int, _QSCD_FOR_MULTIMAP> mmap;

    void cleanUp();
    void run();

signals:
    void sendQSCDtoMain(QMultiMap<int, _QSCD_FOR_MULTIMAP>);
};






class RecvQSCD100Message : public QThread
{
    Q_OBJECT
public:
    RecvQSCD100Message(QWidget *parent = nullptr);
    ~RecvQSCD100Message();

public:
    void setup(QString, QString, QString, QString, bool, bool);

private:
    Connection *connection;
    Session *session;
    Destination *destination;
    MessageConsumer *consumer;

    QMultiMap<int, _QSCD_FOR_MULTIMAP> mmap;

    void cleanUp();
    void run();

signals:
    void sendQSCDtoMain(QMultiMap<int, _QSCD_FOR_MULTIMAP>);
};





class RecvEEWMessage : public QThread
{
    Q_OBJECT
public:
    RecvEEWMessage(QWidget *parent = 0);
    ~RecvEEWMessage();

public:
    void setup(QString, QString, QString, QString, bool, bool);

private:
    Connection *connection;
    Session *session;
    Destination *destination;
    MessageConsumer *consumer;
    QString ip;

    void cleanUp();
    void run();

signals:
    void _rvEEWInfo(_EEWINFO);
};


#endif // KGEEWLIBS_H
