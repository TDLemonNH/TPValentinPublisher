#ifndef XMLINTERFACEWRITER_H
#define XMLINTERFACEWRITER_H

#include <QXmlStreamWriter>
#include "mainwindow.h"

class XMLInterfaceWriter
{
public:
    XMLInterfaceWriter(MainWindow *mainWindow);
    bool writeFile(QIODevice *device);

private:
    bool saveGeneralDataWidget();
    void writeLineEditItem(LineEditItem *item);
    void writeImageItem(ImageItem *item);
    void writeDateItem(DateItem *item);

    bool saveTreeView();
    void writeItem(QTreeWidgetItem *item);

private:
    QXmlStreamWriter m_xml;
    MainWindow *m_mainWindow;
};

#endif // XMLINTERFACEWRITER_H
