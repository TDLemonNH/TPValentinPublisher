#ifndef GENERALDATAWIDGET_H
#define GENERALDATAWIDGET_H

#include <QWidget>
#include <QList>
#include "items/lineedititem.h"
#include "items/imageitem.h"
#include "items/dateitem.h"

class GeneralDataWidget : public QScrollArea
{
    Q_OBJECT
public:
    explicit GeneralDataWidget(QWidget *parent = 0);
    QList<DynamicField *>* widgetList() {return m_widgetList;}
    
signals:
    
public slots:
    void addMenuTriggered(QAction *action);
    void addDynamicField(DynamicField *widget);
    void addTextField();
    void addImageField();
    void addDateField();
    void addCheckBoxField();
    void showDeleteButtons();
    void deleteWidget(DynamicField *widget);

private:
    QList<DynamicField *> *m_widgetList;
    QVBoxLayout *m_layout;
    QToolButton *m_addButton;
    QPushButton *m_deleteButton;
    QMenu *m_newFieldMenu;

    bool m_showDeleteButtons;
    
};

#endif // GENERALDATAWIDGET_H
