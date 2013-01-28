#include "xmlinterfacereader.h"

XMLInterfaceReader::XMLInterfaceReader(MainWindow *mainWindow)
{
    m_mainWindow = mainWindow;
}

bool XMLInterfaceReader::readFile(QIODevice *device)
{
    m_xml.setDevice(device);

    m_xml.readNextStartElement();
    if(m_xml.name() != "ProjectData")
        return false;

    while(!m_xml.atEnd())
    {
        qDebug() << "Boucle " << m_xml.name();
        if(m_xml.readNextStartElement())
        {
            qDebug() << "In readFile reading " << m_xml.name();
            if(m_xml.name() == "GeneralDataWidget")
                loadGeneralDataWidget();
            else if(m_xml.name() == "DocumentStructure")
                loadTreeView();
            else
            {
                qDebug() << "Skipped " << m_xml.name() << " in readFile";
                m_xml.skipCurrentElement();
            }
        }
    }

    qDebug() << "Loading file done";

    return true;
}

bool XMLInterfaceReader::loadGeneralDataWidget()
{
    // Clear current interface and build the new one from file
    if(m_xml.name() == "GeneralDataWidget")
    {
        // We are dealing with the right type of xml file, we can clear the current interface
        QList<DynamicField *> *list = m_mainWindow->generalDataWidget()->widgetList();
        while(!list->isEmpty())
            m_mainWindow->generalDataWidget()->deleteWidget(list->first());
    }

    while(m_xml.readNextStartElement())
    {
        qDebug() << "In loadGeneral reading " << m_xml.name();
        if(m_xml.name() == "LineEditItem")
        {
            readLineEditItem();
            m_xml.skipCurrentElement();
        }
        else if(m_xml.name() == "ImageItem")
        {
            readImageItem();
            m_xml.skipCurrentElement();
        }
        else if(m_xml.name() == "DateItem")
        {
            readDateItem();
            m_xml.skipCurrentElement();
        }
        else
        {
            qDebug() << "Skipped " << m_xml.name() << " in loadGeneralDataWidget";
            m_xml.skipCurrentElement();
        }
    }

    return true;
}

void XMLInterfaceReader::readLineEditItem()
{
    LineEditItem *item = new LineEditItem(m_xml.attributes().value("name").toString());
    item->setContent(m_xml.attributes().value("content").toString());
    m_mainWindow->generalDataWidget()->addDynamicField(item);
}

void XMLInterfaceReader::readImageItem()
{
    ImageItem *item = new ImageItem(m_xml.attributes().value("name").toString());
    item->setImagePath(m_xml.attributes().value("imagePath").toString());
    m_mainWindow->generalDataWidget()->addDynamicField(item);
}

void XMLInterfaceReader::readDateItem()
{
    DateItem *item = new DateItem(m_xml.attributes().value("name").toString());
    item->setDate(QDate::fromString(m_xml.attributes().value("date").toString(), "dd/MM/yyyy"));
    item->setCurrentDateAuto(m_xml.attributes().value("currentDateAuto").toString().toInt());
    m_mainWindow->generalDataWidget()->addDynamicField(item);
}

bool XMLInterfaceReader::loadTreeView()
{
    treeWidget = m_mainWindow->publisherTreeView();

    if(m_xml.name() == "DocumentStructure")
    {
        // We are dealing with the right type of xml file, we can clear the tree widget
        treeWidget->clear();
        qDebug() << "Clearing treewidget";
    }

    readTreeItems();

    qDebug() << "Reading items done";
    return true;
}

void XMLInterfaceReader::readTreeItems()
{
    qDebug() << "Reading tree items" << " current " << m_xml.name();
    while (m_xml.readNextStartElement()) {
         if (m_xml.name() == "category")
             readCategory(0);
         else {
             qDebug() << "Skipped " << m_xml.name() << " in readTreeItems";
             m_xml.skipCurrentElement();
         }
     }
}

void XMLInterfaceReader::readCategory(QTreeWidgetItem *item)
{
    qDebug() << "Reading category";
    QTreeWidgetItem *category = createChildItem(item);
    category->setText(0, m_xml.attributes().value("content").toString());
    category->setText(1, m_xml.name().toString());
    qDebug() << "category created";

    while (m_xml.readNextStartElement()) {
         if (m_xml.name() == "category")
             readCategory(category);
         else {
             qDebug() << "Skipped " << m_xml.name() << " in readCategory";
             m_xml.skipCurrentElement();
         }
     }
}

QTreeWidgetItem* XMLInterfaceReader::createChildItem(QTreeWidgetItem *item)
{
    QTreeWidgetItem *childItem;
    if (item) {
        childItem = new QTreeWidgetItem(item);
    } else {
        childItem = new QTreeWidgetItem(treeWidget);
    }
    return childItem;
}
