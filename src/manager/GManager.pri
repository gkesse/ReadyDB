include("C:\Users\TiaGerard\Downloads\QtAwesome\QtAwesome-master\QtAwesome-master\QtAwesome\QtAwesome.pri")
include(view/GView.pri)

INCLUDEPATH += \
    $$PWD

HEADERS += \
    $$PWD/GPicto.h \
    $$PWD/GSplashScreen.h \
    $$PWD/GStyle.h \
    $$PWD/GDatabaseAccess.h \
    $$PWD/GJson.h \
    $$PWD/GTypeDef.h \
    $$PWD/GDatabaseAccessSQLite.h \
    $$PWD/GDatabaseAccessMySQL.h \
    $$PWD/GConfig.h \
    $$PWD/GGlobal.h

SOURCES += \
    $$PWD/GPicto.cpp \
    $$PWD/GSplashScreen.cpp \
    $$PWD/GStyle.cpp \
    $$PWD/GDatabaseAccess.cpp \
    $$PWD/GJson.cpp \
    $$PWD/GDatabaseAccessSQLite.cpp \
    $$PWD/GDatabaseAccessMySQL.cpp \
    $$PWD/GConfig.cpp \
    $$PWD/GGlobal.cpp

