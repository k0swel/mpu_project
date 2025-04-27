TEMPLATE = subdirs


SUBDIRS = SMTPEmail server

server.subdir = $$PWD/server
SMTPEmail.subdir = $$PWD/server/libraries/SMTPEmail
server.depends = SMTPEmail
