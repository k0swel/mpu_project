CONFIG += c++17 cmdline static
QT = core sql network

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
        $$PWD/src/mytcpserver.cpp \
        $$PWD/src/math_class.cpp

INCLUDEPATH += "$$PWD/libraries/SMTPEmail/include" "$$PWD/include"
LIBS += -L$$PWD/libraries/SMTPEmail/build -lSmtpMime

HEADERS += \
    $$PWD/include/client_object.h \
    $$PWD/include/dbsingleton.h \
    $$PWD/include/functions_for_server.h \
    $$PWD/include/mytcpserver.h \
    $$PWD/include/math_class.h

OBJECTS_DIR = $$PWD/build/obj
MOC_DIR = $$PWD/build/moc
UI_DIR = $$PWD/build/ui



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
