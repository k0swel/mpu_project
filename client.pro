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
    client_main_window.cpp \
    clients_func.cpp \
    main.cpp \
    reg_form.cpp \
    reset_password.cpp

HEADERS += \
    auth_form.h \
    client.h \
    client_main_window.h \
    clients_func.h \
    reg_form.h \
    reset_password.h

FORMS += \
    auth_form.ui \
    client_main_window.ui \
    reg_form.ui \
    reset_password.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
