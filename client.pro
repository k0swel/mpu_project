QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TARGET = client

CONFIG -=debug_and_release
CONFIG += release

DESTDIR = $$PWD/build

OBJECTS_DIR = ./build/obj
UI_DIR = ./build/ui
MOC_DIR = ./build/moc
RCC_DIR = ./build/rcc

INCLUDEPATH = "$$PWD/include"

SOURCES += \
    $$PWD/src/auth_form.cpp \
    $$PWD/src/client.cpp \
    $$PWD/src/client_main_window.cpp \
    $$PWD/src/clients_func.cpp \
    $$PWD/src/main.cpp \
    $$PWD/src/notification.cpp \
    $$PWD/src/reg_form.cpp \
    $$PWD/src/reset_password.cpp

HEADERS += \
    $$PWD/include/auth_form.h \
    $$PWD/include/client.h \
    $$PWD/include/client_main_window.h \
    $$PWD/include/clients_func.h \
    $$PWD/include/notification.h \
    $$PWD/include/reg_form.h \
    $$PWD/include/reset_password.h

FORMS += \
    $$PWD/ui/auth_form.ui \
    $$PWD/ui/client_main_window.ui \
    $$PWD/ui/notification.ui \
    $$PWD/ui/reg_form.ui \
    $$PWD/ui/reset_password.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    $$PWD/resources/recources.qrc
