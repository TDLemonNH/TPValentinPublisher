#include "xmlinterfacewriter.h"

XMLInterfaceWriter::XMLInterfaceWriter(MainWindow *mainWindow)
{
    m_mainWindow = mainWindow;
    m_xml.setAutoFormatting(true);
}

bool XMLInterfaceWriter::writeFile(QIODevice *device)
{
    m_xml.setDevice(device);

    m_xml.writeStartDocument();
    m_xml.writeStartElement("ProjectData");
    saveGeneralDataWidget();
    saveTreeView();
    m_xml.writeEndElement();
    m_xml.writeEndDocument();

    return true;
}

bool XMLInterfaceWriter::saveGeneralDataWidget()
{
    m_xml.writeStartElement("GeneralDataWidget");

    QList<DynamicField *> *widgetList = m_mainWindow->generalDataWidget()->widgetList();

    for(int i = 0; i<widgetList->count(); i++)
    {
        if(LineEditItem *ptr = dynamic_cast<LineEditItem*>(widgetList->at(i)))
            writeLineEditItem(ptr);
        if(ImageItem *ptr = dynamic_cast<ImageItem*>(widgetList->at(i)))
            writeImageItem(ptr);
        if(DateItem *ptr = dynamic_cast<DateItem*>(widgetList->at(i)))
            writeDateItem(ptr);
    }

    m_xml.writeEndElement();

    return true;
}

bool XMLInterfaceWriter::saveTreeView()
{
    m_xml.writeStartElement("DocumentStructure");

    PublisherTreeView *treeView = m_mainWindow->publisherTreeView();

    for(int i = 0; i<treeView->topLevelItemCount(); i++)
        writeItem(treeView->topLevelItem(i));

    m_xml.writeEndElement();

    return true;
}

void XMLInterfaceWriter::writeItem(QTreeWidgetItem *item)
{
    PublisherTreeView *treeView = m_mainWindow->publisherTreeView();

    m_xml.writeStartElement(item->text(1));
    m_xml.writeAttribute("content", item->text(0));

    for(int i = 0; i<item->childCount(); i++)
    {
        writeItem(item->child(i));
    }

    m_xml.writeEndElement();
}

void XMLInterfaceWriter::writeLineEditItem(LineEditItem *item)
{
    m_xml.writeStartElement("LineEditItem");
    m_xml.writeAttribute("name", item->name());
    m_xml.writeAttribute("content", item->content());
    m_xml.writeEndElement();
}

void XMLInterfaceWriter::writeImageItem(ImageItem *item)
{
    m_xml.writeStartElement("ImageItem");
    m_xml.writeAttribute("name", item->name());
    m_xml.writeAttribute("imagePath", item->imagePath());
    m_xml.writeEndElement();
}

void XMLInterfaceWriter::writeDateItem(DateItem *item)
{
    m_xml.writeStartElement("DateItem");
    m_xml.writeAttribute("name", item->name());
    m_xml.writeAttribute("date", item->date());
    m_xml.writeAttribute("currentDateAuto", item->currentDateAuto());
    m_xml.writeEndElement();
}


