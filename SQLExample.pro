TARGET = SQLExample

TEMPLATE = app
QT = core network sql
CONFIG += console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        controllers/monitoringdatasetcontroller.cpp \
        dbconnection.cpp \
        global.cpp \
        main.cpp \
        requestmapper.cpp


include(httpserver/httpserver.pri)

OTHER_FILES += etc/*

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    controllers/monitoringdatasetcontroller.h \
    dbconnection.h \
    global.h \
    requestmapper.h
