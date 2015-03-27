#---------------------------
# QT include
#---------------------------

QT += core network sql
QT -= gui

#---------------------------
# basic configuration
#---------------------------

TARGET = authserver #target app name
CONFIG += console #is a console
CONFIG -= app_bundle #not need the app bundle

CONFIG += c++11 #enable c++11

TEMPLATE = app #app template

win32 {
    RC_FILE = AuthServer.rc
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
# library and dep
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
            LIBS += -L"$${WIN_CRYPTOPP_DIR}/$${CRYPTOPP_ARCH_DIR}" -lcryptlib_d #debug lib
        }
        else {
            LIBS += -L"$${WIN_CRYPTOPP_DIR}/$${CRYPTOPP_ARCH_DIR}"  -lcryptlib #release lib
        }
    }

    #MinGW
    win32-g++: {
        CONFIG( debug, debug|release ) {
            LIBS += -L"$${WIN_CRYPTOPP_DIR}/$${CRYPTOPP_ARCH_DIR}" -lcryptopp_d
            LIBS += $${WIN_CRYPTOPP_DIR}/$${CRYPTOPP_ARCH_DIR}/cryptopp_d.dll
        }
        else {
            LIBS += -L"$${WIN_CRYPTOPP_DIR}/$${CRYPTOPP_ARCH_DIR}" -lcryptopp
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
win32-msvc*: LIBS += -L"$${DESTDIR}" -lshared #MSVC shared lib
win32-g++: LIBS += -L"$${DESTDIR}" -lshared #MinGW shared lib

#----------------------------
# include file
#----------------------------

INCLUDEPATH += . ../shared
DEPENDPATH  += . ../shared

#---------------------------
# project file
#---------------------------

INCLUDEPATH += $$PWD

SOURCES += main.cpp \
    AuthServer.cpp \
    AuthSession.cpp \
    AuthMain.cpp

HEADERS += AuthServer.h \
    AuthSession.h \
    AuthMain.h
