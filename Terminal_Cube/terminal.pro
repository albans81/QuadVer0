greaterThan(QT_MAJOR_VERSION, 4) {
    QT       += widgets serialport
} else {
    include($$QTSERIALPORT_PROJECT_ROOT/src/serialport/qt4support/serialport.prf)
}

QT       += core gui widgets

TARGET = terminal
TEMPLATE = app

QT += opengl

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    settingsdialog.cpp \
    console.cpp \
    mainwidget.cpp \
    geometryengine.cpp

HEADERS += \
    mainwindow.h \
    settingsdialog.h \
    console.h \
    mainwidget.h \
    geometryengine.h

FORMS += \
    mainwindow.ui \
    settingsdialog.ui

RESOURCES += \
    terminal.qrc \
    textures.qrc \
    shaders.qrc
