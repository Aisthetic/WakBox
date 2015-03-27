TEMPLATE = subdirs
CONFIG += ordered

#compilation order
SUBDIRS = shared \
          authserver \
          worldserver


worldserver.file = worldserver/WorldServer.pro
authserver.file = authserver/AuthServer.pro
shared.file = shared/Shared.pro

worldserver.depends = shared
authserver.depends = shared

