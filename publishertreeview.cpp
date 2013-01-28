#include "publishertreeview.h"
#include "mainwindow.h"

PublisherTreeView::PublisherTreeView(QWidget *parent) :
    QTreeWidget(parent)
{
    this->setAnimated(true);
    this->setSelectionMode(QAbstractItemView::SingleSelection);

    this->setColumnCount(2);
    this->setRootIsDecorated(false);
    // TO HIDE
    this->setHeaderHidden(false);
    this->setColumnHidden(1, false);
}

void PublisherTreeView::mousePressEvent(QMouseEvent *event)
{
    this->setCurrentItem(0);
    QTreeWidget::mousePressEvent(event);
}

void PublisherTreeView::addSubCategory()
{
    qDebug() << "Adding subcategory";
    CategoryDialog dialog(this);
    if(dialog.exec() == 1 && dialog.content() != "")
    {
        QTreeWidgetItem *item = new QTreeWidgetItem;
        item->setText(0, dialog.content());
        item->setText(1, trUtf8("category"));

        if(currentItem())
            currentItem()->addChild(item);
        else
            addTopLevelItem(item);
    }
}

void PublisherTreeView::contextMenuEvent(QContextMenuEvent *event)
{
    qDebug() << "Showing context menu for tree view";
    MainWindow *ptr = dynamic_cast<MainWindow*>(this->parent()->parent());
    if(ptr)
        ptr->getTreeViewMenu()->exec(mapToGlobal(event->pos()));
}
