QT -= gui
QT += concurrent

TEMPLATE = lib
DEFINES += KGEEWLIBS_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    kgeewlibs.cpp

HEADERS += \
    KGEEWLIBS_global.h \
    kgeewlibs.h \
    landXY_VERSION_1.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

QMAKE_CFLAGS += "-DACCEPT_USE_OF_DEPRECATED_PROJ_API_H"
QMAKE_CXXFLAGS += "-DACCEPT_USE_OF_DEPRECATED_PROJ_API_H"

LIBS += -lproj -lactivemq-cpp
INCLUDEPATH += /usr/local/include/activemq-cpp-3.9.5
INCLUDEPATH += /usr/local/apr/include/apr-1/
