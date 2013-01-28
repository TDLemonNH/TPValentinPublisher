#ifndef REFERENCETREEWIDGET_H
#define REFERENCETREEWIDGET_H

#include <QtGui>
#include "categorydialog.h"

class ReferenceTreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    ReferenceTreeWidget(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent *event);
    
public slots:
    void addSubCategory();
    
};

#endif // REFERENCETREEWIDGET_H
