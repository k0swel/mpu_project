#-------------------------------------------------
#
# Project created by QtCreator 2011-08-11T20:59:25
#
#-------------------------------------------------

CONFIG	+= c++11

QT = core network

VERSION = 2.0.0
VER_MAJ = 2
VER_MIN = 0
VER_PAT = 0

TARGET = SmtpMime
TEMPLATE = lib
CONFIG -= debug_and_release
CONFIG += staticlib release

DEFINES += SMTP_MIME_LIBRARY
DESTDIR = $$PWD/build

INCLUDEPATH = $$PWD/include

OBJECTS_DIR = $$PWD/build/object_files
MOC_DIR = $$PWD/build/moc

SOURCES += \
    $$PWD/src/emailaddress.cpp \
    $$PWD/src/mimeattachment.cpp \
    $$PWD/src/mimebytearrayattachment.cpp \
    $$PWD/src/mimefile.cpp \
    $$PWD/src/mimehtml.cpp \
    $$PWD/src/mimeinlinefile.cpp \
    $$PWD/src/mimemessage.cpp \
    $$PWD/src/mimepart.cpp \
    $$PWD/src/mimetext.cpp \
    $$PWD/src/smtpclient.cpp \
    $$PWD/src/quotedprintable.cpp \
    $$PWD/src/mimemultipart.cpp \
    $$PWD/src/mimecontentencoder.cpp \
    $$PWD/src/mimebase64encoder.cpp \
    $$PWD/src/mimeqpencoder.cpp \
    $$PWD/src/mimeqpformatter.cpp \
    $$PWD/src/mimebase64formatter.cpp \
    $$PWD/src/mimecontentformatter.cpp

HEADERS  += \
    $$PWD/include/emailaddress.h \
    $$PWD/include/mimeattachment.h \
    $$PWD/include/mimebytearrayattachment.h \
    $$PWD/include/mimefile.h \
    $$PWD/include/mimehtml.h \
    $$PWD/include/mimeinlinefile.h \
    $$PWD/include/mimemessage.h \
    $$PWD/include/mimepart.h \
    $$PWD/include/mimetext.h \
    $$PWD/include/smtpclient.h \
    $$PWD/include/SmtpMime \
    $$PWD/include/quotedprintable.h \
    $$PWD/include/mimemultipart.h \
    $$PWD/include/smtpmime_global.h \
    $$PWD/include/mimecontentencoder.h \
    $$PWD/include/mimebase64encoder.h \
    $$PWD/include/mimeqpencoder.h \
    $$PWD/include/mimeqpformatter.h \
    $$PWD/include/mimebase64formatter.h \
    $$PWD/include/mimecontentformatter.h
