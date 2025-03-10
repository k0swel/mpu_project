QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    auth_form.cpp \
    client.cpp \
    clients_func.cpp \
    main.cpp \
    MainWindow.cpp \
    reset_password.cpp

HEADERS += \
    MainWindow.h \
    auth_form.h \
    client.h \
    clients_func.h \
    reset_password.h

FORMS += \
    MainWindow.ui \
    auth_form.ui \
    reset_password.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
