#ifndef PUBLISHERTREEVIEW_H
#define PUBLISHERTREEVIEW_H

#include <QtGui>
#include "categorydialog.h"

class PublisherTreeView : public QTreeWidget
{
    Q_OBJECT
public:
    explicit PublisherTreeView(QWidget *parent = 0);
    
signals:
    void itemSelected();

protected:
    void mousePressEvent(QMouseEvent *event);
    
public slots:
    void addSubCategory();

protected:
    void contextMenuEvent(QContextMenuEvent *event);
    
};

#endif // PUBLISHERTREEVIEW_H
