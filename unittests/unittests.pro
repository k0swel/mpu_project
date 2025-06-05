QT += testlib network sql
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase release
CONFIG -= app_bundle debug_and_release

TEMPLATE = app
TARGET = unittests
DESTDIR = $$PWD/build
SOURCES +=  tst_chto2.cpp \
 ../server/src/math_class.cpp \

HEADERS += ../server/include/math_class.h
INCLUDEPATH += ../server/include
