#-------------------------------------------------
#
# Project created by QtCreator 2020-09-16T11:11:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtClass
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    login.cpp \
    student.cpp \
    uandp.cpp \
    admin_admin.cpp \
    admin.cpp \
    admin_student.cpp \
    admin_teacher.cpp \
    admin_find.cpp \
    add_student.cpp \
    change_student.cpp \
    change_teacher.cpp \
    add_teacher.cpp

HEADERS += \
    login.h \
    student.h \
    uandp.h \
    admin_admin.h \
    admin.h \
    admin_student.h \
    admin_teacher.h \
    admin_find.h \
    add_student.h \
    change_student.h \
    headers.h \
    change_teacher.h \
    add_teacher.h

FORMS += \
    login.ui \
    student.ui \
    admin_admin.ui \
    admin.ui \
    admin_student.ui \
    admin_teacher.ui \
    admin_find.ui \
    add_student.ui \
    change_student.ui \
    change_teacher.ui \
    add_teacher.ui

RC_FILE += \
     logo.rc

RESOURCES += \
    image.qrc
QT += sql
CONFIG += \
        C++11
