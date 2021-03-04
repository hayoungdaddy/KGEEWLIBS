#ifndef KGEEWLIBS_GLOBAL_H
#define KGEEWLIBS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(KGEEWLIBS_LIBRARY)
#  define KGEEWLIBS_EXPORT Q_DECL_EXPORT
#else
#  define KGEEWLIBS_EXPORT Q_DECL_IMPORT
#endif


#include <QString>
#include <QDebug>
#include <QDateTime>
#include <QFile>


#define SECNODS_FOR_ALIGN_QSCD 10
#define NUM_FOR_QSCD_BLOCK 100
#define EVENT_DURATION 120
#define MAX_NUM_STATION 1000

#define KEEP_SMALL_DATA_DURATION 300
#define KEEP_LARGE_DATA_DURATION 86400

#define MAX_SMALL_NUM_EEW 100
#define MAX_LARGE_NUM_EEW 2000

// scnl
#define STA_LEN 10
#define CHAN_LEN 5
#define NET_LEN 4
#define LOC_LEN 4


// south korea map
#include <proj_api.h>
#define XWIDTH              834896.18
#define YHEIGHT             656784.99
#define XORIGIN             13859276.60
#define YORIGIN             3673543.20
#define SMALL_MAP_WIDTH     814
#define SMALL_MAP_HEIGHT    768
#define LARGE_MAP_WIDTH     1085
#define LARGE_MAP_HEIGHT    1024

#define LANDXYCNT_VERSION_1 127822


// _CONFIGURE
typedef struct _configure
{
    QString configFileName;
    QString logDir;
    QString eventDir;
    QString processName;
    QString staType;

    int websocketPort;

    QString db_ip, db_name, db_user, db_passwd;
    QString eew_amq_ip, eew_amq_port, eew_amq_user, eew_amq_passwd, eew_amq_topic;
    QString qscd20_mpss_amq_ip, qscd20_mpss_amq_port, qscd20_mpss_amq_user, qscd20_mpss_amq_passwd, qscd20_mpss_amq_topic;
    QString qscd20_kiss_amq_ip, qscd20_kiss_amq_port, qscd20_kiss_amq_user, qscd20_kiss_amq_passwd, qscd20_kiss_amq_topic;
    QString qscd100_amq_ip, qscd100_amq_port, qscd100_amq_user, qscd100_amq_passwd, qscd100_amq_topic;
} _CONFIGURE;

// _STATION
typedef struct _station
{
    char netSta[STA_LEN];
    float lat;
    float lon;
    int lmapX;
    int lmapY;
    int smapX;
    int smapY;
    int inUse;
    int maxPgaTime[5];
    float maxPga[5];
    int pgaTime;
    float pga[5];
} _STATION;

//_EEWINFO, _BINARY_EEWLIST_PACKET
enum nudMessageType {NEW, UPDATE, DELETE};
enum MessageCategory {LIVE, TEST};

typedef struct _eewinfo
{
    int eew_evid;
    int version;
    enum MessageCategory message_category;
    enum nudMessageType message_type;
    float magnitude;
    float latitude;
    float longitude;
    float depth;
    int origintime;
    int number_stations;
    int lmapX;
    int lmapY;
    int smapX;
    int smapY;
    char location[100];
    char lddate[12];
} _EEWINFO;

typedef struct _binary_small_eewlist_packet {
    int numEEW;
    _EEWINFO eewInfos[MAX_SMALL_NUM_EEW];
} _BINARY_SMALL_EEWLIST_PACKET;

typedef struct _binary_large_eewlist_packet {
    int numEEW;
    _EEWINFO eewInfos[MAX_LARGE_NUM_EEW];
} _BINARY_LARGE_EEWLIST_PACKET;


//_QSCD20_PACKET, _QSCD100_PACKET
typedef struct _qscd20_packet
{
    int crc32 ;         // 4byte CRC Number
    char QFlag ;        // 1byte Quality Flag
    char DType ;        // 1byte Data Type
    char Reserved ;        // 1byte Unused
    char SSSSS[5] ;     // 5byte Station Code
    int time ;          // 4byte Data Time(EpochTime)
    float ZWMin ;     // 4byte U-D Windowed Minimum
    float ZWMax ;     // 4byte U-D Windowed Maximum
    float ZWAvg ;     // 4byte U-D Windowed Average
    float NWMin ;     // 4byte N-S Windowed Minimum
    float NWMax ;     // 4byte N-S Windowed Maximum
    float NWAvg ;     // 4byte N-S Windowed Average
    float EWMin ;     // 4byte E-W Windowed Minimum
    float EWMax ;     // 4byte E-W Windowed Maximum
    float EWAvg ;     // 4byte E-W Windowed Average
    float ZTMin ;     // 4byte U-D True Minimum
    float ZTMax ;     // 4byte U-D True Maximum
    float NTMin ;     // 4byte N-S True Minimum
    float NTMax ;     // 4byte N-S True Maximum
    float ETMin ;     // 4byte E-W True Minimum
    float ETMax ;     // 4byte E-W True Maximum
    float ZMax ;      // 4byte E-W Maximum
    float NMax ;      // 4byte N-S Maximum
    float EMax ;      // 4byte U-D Maximum
    float HPGA ;        // 4byte Horizontal PGA
    float TPGA ;        // 4byte Total PGA
    float ZSI ;       // 4byte U-D SI
    float NSI ;       // 4byte E-W SI
    float ESI ;       // 4byte N-S SI
    float HSI ;       // 4byte Horizontal SI
    float Correl ;    // 4byte Correlation
    char CN1;           // 1byte Channel Number 1
    char CN2;           // 1byte Channel Number 2
    char LO[2];     // 2byte Unused
} _QSCD20_PACKET ;


// _QSCD100_PACKET
typedef struct _qscd100_packet
{
    int version;
    char msg_type;

    char sta[STA_LEN];
    char chan[CHAN_LEN];
    char net[NET_LEN];
    char loc[LOC_LEN];

    float lat;
    float lon;

    time_t time;

    _QSCD20_PACKET qscd;
    char dummy[50];

} _QSCD100_PACKET;

// _QSCD_FOR_MULTIMAP
typedef struct _qscd_for_multimap
{
    QString netSta;
    float pga[5];
} _QSCD_FOR_MULTIMAP;

// _QSCD_FOR_BIN
typedef struct _qscd_for_bin
{
    int time;
    char netSta[STA_LEN];
    float pga[5];
} _QSCD_FOR_BIN;

// _BINARY_PGA_PACKET
typedef struct _binary_pga_packet
{
    int numStation;
    int dataTime;
    _STATION staList[MAX_NUM_STATION];
} _BINARY_PGA_PACKET;

// _POINT
typedef struct _point
{
    int landX;
    int landY;
    float mapZ;
    QList<_STATION> staList;
    QList<double> mapLUT;
} _POINT;

// _BINARY_POINT_PACKET
typedef struct _binary_point_packet
{
    int dataTime;
    float mapZ[LANDXYCNT_VERSION_1];
} _BINARY_POINT_PACKET;




// functions
static _CONFIGURE readCFG(QString configFileName)
{
    _CONFIGURE cfg;
    cfg.configFileName = configFileName;

    QFile file(cfg.configFileName);
    if(!file.exists())
    {
        qDebug() << "Failed configuration. Parameter file doesn't exists.";
        exit(1);
    }
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        QString line, _line;

        while(!stream.atEnd())
        {
            line = stream.readLine();
            _line = line.simplified();

            if(_line.startsWith(" ") || _line.startsWith("#"))
                continue;
            else if(_line.startsWith("LOG_DIR"))
                cfg.logDir = _line.section("=", 1, 1);
            else if(_line.startsWith("EVENT_DIR"))
                cfg.eventDir = _line.section("=", 1, 1);
            else if(_line.startsWith("PROCESS_NAME"))
                cfg.processName = _line.section("=", 1, 1);
            else if(_line.startsWith("STATION_TYPE"))
                cfg.staType = _line.section("=", 1, 1);
            else if(_line.startsWith("WEBSOCKET_PORT"))
                cfg.websocketPort = _line.section("=", 1, 1).toInt();

            else if(_line.startsWith("DB_IP"))
                cfg.db_ip = _line.section("=", 1, 1);
            else if(_line.startsWith("DB_NAME"))
                cfg.db_name = _line.section("=", 1, 1);
            else if(_line.startsWith("DB_USERNAME"))
                cfg.db_user = _line.section("=", 1, 1);
            else if(_line.startsWith("DB_PASSWD"))
                cfg.db_passwd = _line.section("=", 1, 1);

            else if(_line.startsWith("EEW_AMQ_IP"))
                cfg.eew_amq_ip = _line.section("=", 1, 1);
            else if(_line.startsWith("EEW_AMQ_PORT"))
                cfg.eew_amq_port = _line.section("=", 1, 1);
            else if(_line.startsWith("EEW_AMQ_USERNAME"))
                cfg.eew_amq_user = _line.section("=", 1, 1);
            else if(_line.startsWith("EEW_AMQ_PASSWD"))
                cfg.eew_amq_passwd = _line.section("=", 1, 1);
            else if(_line.startsWith("EEW_AMQ_TOPIC"))
                cfg.eew_amq_topic = _line.section("=", 1, 1);

            else if(_line.startsWith("QSCD20_MPSS_AMQ_IP"))
                cfg.qscd20_mpss_amq_ip = _line.section("=", 1, 1);
            else if(_line.startsWith("QSCD20_MPSS_AMQ_PORT"))
                cfg.qscd20_mpss_amq_port = _line.section("=", 1, 1);
            else if(_line.startsWith("QSCD20_MPSS_AMQ_USERNAME"))
                cfg.qscd20_mpss_amq_user = _line.section("=", 1, 1);
            else if(_line.startsWith("QSCD20_MPSS_AMQ_PASSWD"))
                cfg.qscd20_mpss_amq_passwd = _line.section("=", 1, 1);
            else if(_line.startsWith("QSCD20_MPSS_AMQ_TOPIC"))
                cfg.qscd20_mpss_amq_topic = _line.section("=", 1, 1);

            else if(_line.startsWith("QSCD20_KISS_AMQ_IP"))
                cfg.qscd20_kiss_amq_ip = _line.section("=", 1, 1);
            else if(_line.startsWith("QSCD20_KISS_AMQ_PORT"))
                cfg.qscd20_kiss_amq_port = _line.section("=", 1, 1);
            else if(_line.startsWith("QSCD20_KISS_AMQ_USERNAME"))
                cfg.qscd20_kiss_amq_user = _line.section("=", 1, 1);
            else if(_line.startsWith("QSCD20_KISS_AMQ_PASSWD"))
                cfg.qscd20_kiss_amq_passwd = _line.section("=", 1, 1);
            else if(_line.startsWith("QSCD20_KISS_AMQ_TOPIC"))
                cfg.qscd20_kiss_amq_topic = _line.section("=", 1, 1);

            else if(_line.startsWith("QSCD100_AMQ_IP"))
                cfg.qscd100_amq_ip = _line.section("=", 1, 1);
            else if(_line.startsWith("QSCD100_AMQ_PORT"))
                cfg.qscd100_amq_port = _line.section("=", 1, 1);
            else if(_line.startsWith("QSCD100_AMQ_USERNAME"))
                cfg.qscd100_amq_user = _line.section("=", 1, 1);
            else if(_line.startsWith("QSCD100_AMQ_PASSWD"))
                cfg.qscd100_amq_passwd = _line.section("=", 1, 1);
            else if(_line.startsWith("QSCD100_AMQ_TOPIC"))
                cfg.qscd100_amq_topic = _line.section("=", 1, 1);
        }
        file.close();
    }

    return cfg;
}

static void writeLog(QString dir, QString fileName, QString str)
{
    QDateTime nowUTC = QDateTime::currentDateTimeUtc();

    QFile file(dir + "/" + fileName + "." + nowUTC.toString("yyyyMMdd") + ".log");
    if(file.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        QTextStream stream( &file );

        stream << nowUTC.toString("[UTC hh:mm:ss] ") << str << "\n";

        file.close();
    }
}

static int ll2xy4Small(projPJ src, projPJ target, float lon, float lat, int *rx, int *ry)
{
    double x, y;
    int rtn = 0 ;

    double mapx, mapy ;

    x = lon * DEG_TO_RAD ;
    y = lat * DEG_TO_RAD ;

    rtn = pj_transform(src, target, 1, 1, &x, &y, nullptr );

    mapx = x - XORIGIN ;
    mapx *=  SMALL_MAP_WIDTH ;
    mapx /= XWIDTH ;

    mapy = y - YORIGIN ;
    mapy *=  SMALL_MAP_HEIGHT ;
    mapy /= YHEIGHT ;
    mapy = SMALL_MAP_HEIGHT - mapy ;

    *rx = (int)mapx ;
    *ry = (int)mapy ;
}

static int ll2xy4Large(projPJ src, projPJ target, float lon, float lat, int *rx, int *ry)
{
    double x, y;
    int rtn = 0 ;

    double mapx, mapy ;

    x = lon * DEG_TO_RAD ;
    y = lat * DEG_TO_RAD ;

    rtn = pj_transform(src, target, 1, 1, &x, &y, nullptr );

    mapx = x - XORIGIN ;
    mapx *=  LARGE_MAP_WIDTH ;
    mapx /= XWIDTH ;

    mapy = y - YORIGIN ;
    mapy *=  LARGE_MAP_HEIGHT ;
    mapy /= YHEIGHT ;
    mapy = LARGE_MAP_HEIGHT - mapy ;

    *rx = (int)mapx ;
    *ry = (int)mapy ;
}

static QDateTime convertKST(QDateTime utc)
{
    QDateTime kst;
    kst = utc;
    kst = kst.addSecs( 9 * 3600 );
    return kst;
}

static void SwapFloat(float *data)
{
    char temp;

    union {
        char c[4];
    } dat;

    memcpy( &dat, data, sizeof(float) );
    temp     = dat.c[0];
    dat.c[0] = dat.c[3];
    dat.c[3] = temp;
    temp     = dat.c[1];
    dat.c[1] = dat.c[2];
    dat.c[2] = temp;
    memcpy( data, &dat, sizeof(float) );
    return;
}

static void SwapInt(int *data)
{
    char temp;

    union {
        char c[4];
    } dat;

    memcpy( &dat, data, sizeof(int) );
    temp     = dat.c[0];
    dat.c[0] = dat.c[3];
    dat.c[3] = temp;
    temp     = dat.c[1];
    dat.c[1] = dat.c[2];
    dat.c[2] = temp;
    memcpy( data, &dat, sizeof(int) );
    return;
}


#endif // KGEEWLIBS_GLOBAL_H
