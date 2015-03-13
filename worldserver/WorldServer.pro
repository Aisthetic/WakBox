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

CONFIG( debug, debug|release ) {
    DESTDIR = $${WAKBOX_TOP_DIR}/build/debug
}
else {
    DESTDIR = $${WAKBOX_TOP_DIR}/build/release
}


OBJECTS_DIR = $${WAKBOX_TOP_DIR}/build/.obj/$$TARGET
MOC_DIR = $${WAKBOX_TOP_DIR}/build/.moc/$$TARGET
RCC_DIR = $${WAKBOX_TOP_DIR}/build/.qrc/$$TARGET
UI_DIR = $${WAKBOX_TOP_DIR}/build/.ui/$$TARGET

#---------------------------
# library
#---------------------------

#cryptopp
unix {
   LIBS += -L"/usr/lib/libcryptopp" -lcryptopp
}
win32 {
    CONFIG( debug, debug|release ) {
        LIBS += -L"$${WAKBOX_TOP_DIR}/dep/cryptopp" -lcryptlib_d #debug lib
    }
    else {
        LIBS += -L"$${WAKBOX_TOP_DIR}/dep/cryptopp" -lcryptlib #release lib
    }

  INCLUDEPATH += $${WAKBOX_TOP_DIR}/dep/cryptopp
}

#disable this warning - too much on cryptopp
QMAKE_CXXFLAGS_WARN_ON -= -w34100 -w34189 #MSVC
QMAKE_CXXFLAGS += -isystem $${WAKBOX_TOP_DIR}/dep/cryptopp #MinGW

#shared
LIBS += -L../shared -l"$${DESTDIR}/shared"

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
