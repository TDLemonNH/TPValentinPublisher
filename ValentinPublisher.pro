QT       += core gui
QT       += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ValentinPublisher
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    publishertreeview.cpp \
    generaldatawidget.cpp \
    items/dateitem.cpp \
    items/lineedititem.cpp \
    items/imageitem.cpp \
    xml/xmlinterfacewriter.cpp \
    xml/xmlinterfacereader.cpp \
    items/dynamicfield.cpp \
    categorydialog.cpp \
    referencedialog.cpp \
    editreferencedialog.cpp \
    referencetreewidget.cpp

HEADERS  += mainwindow.h \
    publishertreeview.h \
    generaldatawidget.h \
    items/dateitem.h \
    items/lineedititem.h \
    items/imageitem.h \
    xml/xmlinterfacewriter.h \
    xml/xmlinterfacereader.h \
    items/dynamicfield.h \
    categorydialog.h \
    referencedialog.h \
    editreferencedialog.h \
    referencetreewidget.h

OTHER_FILES += \
    img/save.png \
    img/new.png \
    img/folder.png \
    img/exit.png \
    img/delete.png \
    img/copy.png \
    img/check.png \
    img/calendar.png \
    img/add.png

RESOURCES += \
    application.qrc
