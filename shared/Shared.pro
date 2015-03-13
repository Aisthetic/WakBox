#---------------------------
# QT include
#---------------------------

QT += core sql network
QT -= gui

#---------------------------
# basic configuration
#---------------------------

TEMPLATE = lib
CONFIG += staticlib

TARGET = shared

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
QMAKE_CXXFLAGS_WARN_ON -= -w34100 -w34189 #MSCV
QMAKE_CXXFLAGS += -isystem $${WAKBOX_TOP_DIR}/dep/cryptopp #MinGW

#----------------------------
# project file
#----------------------------

#SOURCES += $$PWD/*.cpp
HEADERS += $$PWD/*.h

include(Configuration/Configuration.pri)
include(Cryptography/Cryptography.pri)
include(Databases/Databases.pri)
include(Logs/Logs.pri)
include(Network/Network.pri)
include(Packets/Packets.pri)
include(Utils/Utils.pri)
