CONFIG += static
TEMPLATE = subdirs


SUBDIRS = SMTPEmail server unittests

server.subdir = $$PWD/server
SMTPEmail.subdir = $$PWD/server/libraries/SMTPEmail
unittests.subdir = $$PWD/unittests
server.depends = SMTPEmail
chto2.depends = server
