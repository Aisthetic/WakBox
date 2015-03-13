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
