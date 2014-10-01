#-------------------------------------------------
#
# Project created by QtCreator 2014-07-13T16:47:24
#
#-------------------------------------------------

QT       += core gui network webkitwidgets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testTabUI
TEMPLATE = app

QMAKE_CFLAGS_DEBUG +=  --std=c99
QMAKE_CFLAGS_RELEASE +=  --std=c99

SOURCES += main.cpp\
        mainwindow.cpp \
        classtabone.cpp \
        classtabtwo.cpp \
        tool.cpp \
        classtablemodelone.cpp\
        gumbo/attribute.c \
        gumbo/char_ref.c \
        gumbo/error.c \
        gumbo/parser.c \
        gumbo/string_buffer.c \
        gumbo/string_piece.c \
        gumbo/tag.c \
        gumbo/tokenizer.c \
        gumbo/utf8.c \
        gumbo/util.c \
        gumbo/vector.c \
    classtabthree.cpp \
    webviewwindow.cpp \
    classtabfour.cpp \
    classtabfive.cpp \
    beanandservice.cpp \
    classtabsix.cpp



HEADERS  += mainwindow.h \
        tool.h \
        classtabone.h \
        classtabtwo.h \
        classtablemodelone.h\
        gumbo/attribute.h \
        gumbo/char_ref.h \
        gumbo/error.h \
        gumbo/gumbo.h \
        gumbo/insertion_mode.h \
        gumbo/parser.h \
        gumbo/string_buffer.h \
        gumbo/string_piece.h \
        gumbo/token_type.h \
        gumbo/tokenizer.h \
        gumbo/tokenizer_states.h \
        gumbo/utf8.h \
        gumbo/util.h \
        gumbo/vector.h \
    classtabthree.h \
    webviewwindow.h \
    classtabfour.h \
    classtabfive.h \
    beanandservice.h \
    classtabsix.h

FORMS    += mainwindow.ui \
    classtabone.ui \
    classtabtwo.ui \
    classtabthree.ui \
    webviewwindow.ui \
    classtabfour.ui \
    classtabfive.ui \
    classtabsix.ui

OTHER_FILES += \
    璇存槑.txt \
    stock.db \
    工程说明.txt
