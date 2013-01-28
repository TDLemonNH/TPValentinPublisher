#include "referencetreewidget.h"

ReferenceTreeWidget::ReferenceTreeWidget(QWidget *parent) :
    QTreeWidget(parent)
{
    this->setAnimated(true);
    this->setSelectionMode(QAbstractItemView::SingleSelection);
    this->setColumnCount(4);
    this->setRootIsDecorated(false);
    this->setHeaderHidden(false);
}

void ReferenceTreeWidget::mousePressEvent(QMouseEvent *event)
{
    this->setCurrentItem(0);
    QTreeWidget::mousePressEvent(event);
}

void ReferenceTreeWidget::addSubCategory()
{
    qDebug() << "Adding subcategory";
    CategoryDialog dialog(this);
    if(dialog.exec() == 1 && dialog.content() != "")
    {
        QTreeWidgetItem *item = new QTreeWidgetItem(1000);
        item->setText(0, dialog.content());

        if(currentItem() && currentItem()->type() == 1000)
            currentItem()->addChild(item);
        else
            addTopLevelItem(item);
    }
}
