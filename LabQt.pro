QT       += core gui
QT       += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    app.cpp \
    createaccount.cpp \
    data.cpp \
    entry.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    newentrydialog.cpp

HEADERS += \
    app.h \
    createaccount.h \
    data.h \
    entry.h \
    loginwindow.h \
    mainwindow.h \
    newentrydialog.h

FORMS += \
    createaccount.ui \
    loginwindow.ui \
    mainwindow.ui \
    newentrydialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
