QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_chto2.cpp\
 ../mpu_project-Server/server/src/functions_for_server.cpp
HEADERS += ../mpu_project-Server/server/include/functions_for_server.h
