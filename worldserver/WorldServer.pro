#---------------------------
# QT include
#---------------------------

QT += core network sql
QT -= gui

#---------------------------
# basic configuration
#---------------------------

TARGET = worldserver
CONFIG += console
CONFIG -= app_bundle

CONFIG += c++11 #enable c++11

TEMPLATE = app

win32 {
    RC_FILE = WorldServer.rc
}


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

#----------
#cryptopp
#----------

unix {
   LIBS += -L"$${UNIX_CRYPTOPP_DIR}" -lcryptopp
}
win32 {
    #cryptopp folder select
    CRYPTOPP_ARCH_DIR = "x32"

    #building with win and msvc on x64
    win32-msvc*:contains(QMAKE_TARGET.arch, x86_64):{
        CRYPTOPP_ARCH_DIR = "x64"
    }

    #MSVC
    win32-msvc*: {
        CONFIG( debug, debug|release ) {
            LIBS += -L"$${WIN_CRYPTOPP_DIR}" -l"$${WIN_CRYPTOPP_DIR}/$${CRYPTOPP_ARCH_DIR}/cryptlib_d" #debug lib
        }
        else {
            LIBS += -L"$${WIN_CRYPTOPP_DIR}"  -l"$${WIN_CRYPTOPP_DIR}/$${CRYPTOPP_ARCH_DIR}/cryptlib" #release lib
        }
    }

    #MinGW
    win32-g++: {
        CONFIG( debug, debug|release ) {
            LIBS += $${WIN_CRYPTOPP_DIR}/$${CRYPTOPP_ARCH_DIR}/libcryptopp_d.a
            LIBS += $${WIN_CRYPTOPP_DIR}/$${CRYPTOPP_ARCH_DIR}/cryptopp_d.dll
        }
        else {
            LIBS += $${WIN_CRYPTOPP_DIR}/$${CRYPTOPP_ARCH_DIR}/libcryptopp.a
            LIBS += $${WIN_CRYPTOPP_DIR}/$${CRYPTOPP_ARCH_DIR}/cryptopp.dll
        }
    }

    INCLUDEPATH += $${WIN_CRYPTOPP_DIR}
}

#disable this warning - too much on cryptopp
win32-msvc*: QMAKE_CXXFLAGS_WARN_ON -= -w34100 -w34189 #MSVC
win32-g++: QMAKE_CXXFLAGS += -isystem $${WIN_CRYPTOPP_DIR} #MinGW

#-------------


#shared
win32-msvc*: LIBS += -L../shared -l"$${DESTDIR}/shared" #MSVC shared lib
win32-g++: LIBS += $${DESTDIR}/libshared.a #MinGW shared lib

#----------------------------
# include file
#----------------------------

INCLUDEPATH += . ../dep ../shared ../worldserver ../worldserver/Game
DEPENDPATH += . ../dep  ../shared ../worldserver ../worldserver/Game

#---------------------------
# project file
#---------------------------

INCLUDEPATH += $$PWD

SOURCES += main.cpp \
    WorldServer.cpp

HEADERS += WorldServer.h

include(../dep/Dep.pri)
include(Game/Game.pri)
include(Scripts/Scripts.pri)
