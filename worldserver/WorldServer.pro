#---------------------------
# QT include
#---------------------------

QT       += core network sql
QT       -= gui


#---------------------------
# basic configuration
#---------------------------

TARGET = worldserver
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

#---------------------------
#  build configuration
#---------------------------

release : DESTDIR = $${WAKBOX_TOP_DIR}/build/release
debug : DESTDIR = $${WAKBOX_TOP_DIR}/build/debug

OBJECTS_DIR = $${WAKBOX_TOP_DIR}/build/.obj/$$TARGET
MOC_DIR = $${WAKBOX_TOP_DIR}/build/.moc/$$TARGET
RCC_DIR = $${WAKBOX_TOP_DIR}/build/.qrc/$$TARGET
UI_DIR = $${WAKBOX_TOP_DIR}/build/.ui/$$TARGET

#---------------------------
# library
#---------------------------

#openssl
unix {
   PKGCONFIG += openssl
}

win32 {
    LIBS += -LC:/OpenSSL-Win32/lib -lubsec
    LIBS += -LC:/OpenSSL-Win32/lib -lssleay32
    LIBS += -LC:/OpenSSL-Win32/lib -llibeay32
    INCLUDEPATH += C:/OpenSSL-Win32/include
}

#shared
LIBS += -L../shared -l"$$DESTDIR/shared"

#----------------------------
# include file
#----------------------------

INCLUDEPATH += . ../dep ../shared ../worldserver ../worldserver/Game
DEPENDPATH += . ../dep  ../shared ../worldserver ../worldserver/Game

#---------------------------
# project file
#---------------------------

SOURCES += main.cpp \
    WorldServer.cpp

HEADERS += WorldServer.h

include(../dep/Dep.pri)
include(Game/Game.pri)
include(Scripts/Scripts.pri)
