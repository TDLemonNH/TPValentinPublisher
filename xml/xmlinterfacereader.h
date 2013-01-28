#ifndef XMLINTERFACEREADER_H
#define XMLINTERFACEREADER_H

#include <QXmlStreamReader>
#include "mainwindow.h"

class XMLInterfaceReader
{
public:
    XMLInterfaceReader(MainWindow *mainWindow);
    bool readFile(QIODevice *device);

private:
    bool loadGeneralDataWidget();
    void readLineEditItem();
    void readImageItem();
    void readDateItem();

    bool loadTreeView();
    void readTreeItems();
    void readCategory(QTreeWidgetItem *item);
    QTreeWidgetItem* createChildItem(QTreeWidgetItem *item);

private:
    QXmlStreamReader m_xml;
    MainWindow *m_mainWindow;
    PublisherTreeView *treeWidget;
};

#endif // XMLINTERFACEREADER_H
