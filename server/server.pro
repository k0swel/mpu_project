QT = core sql network
CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TARGET = server

DESTDIR = $$PWD/build

CONFIG -= debug_and_release
CONFIG += release

SOURCES += \
        $$PWD/src/client_object.cpp \
        $$PWD/src/dbsingleton.cpp \
        $$PWD/src/functions_for_server.cpp \
        $$PWD/src/main.cpp \
        $$PWD/src/mytcpserver.cpp

INCLUDEPATH += "PWD$$/libraries/SMTPEmail/include" "PWD$$/include"
LIBS += "$$PWD/libraries/SMTPEmail/build/libSmtpMime.a"

HEADERS += \
    $$PWD/include/client_object.h \
    $$PWD/include/dbsingleton.h \
    $$PWD/include/functions_for_server.h \
    $$PWD/include/mytcpserver.h \
    $$PWD/libraries/SMTPEmail/include/SmtpMime

OBJECTS_DIR = $$PWD/build/obj
MOC_DIR = $$PWD/build/moc
UI_DIR = $$PWD/build/ui



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
