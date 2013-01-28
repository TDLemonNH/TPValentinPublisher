#ifndef DATEITEM_H
#define DATEITEM_H

#include <QtGui>
#include "dynamicfield.h"

class DateItem : public DynamicField
{
    Q_OBJECT
public:
    explicit DateItem(QString name, QWidget *parent = 0);
    QString name() {QString name = m_label->text(); name.chop(2); return name;}
    QString date() {return m_dateEdit->date().toString("dd/MM/yyyy");}
    QString currentDateAuto();
    void setDate(QDate date) {m_dateEdit->setDate(date);}
    void setCurrentDateAuto(bool value) {if(value){m_currentDate->click();}}
    
signals:
    
public slots:
    void dateAuto();

private:
    QGridLayout *m_layout;
    QDateEdit *m_dateEdit;
    QLabel *m_label;
    QCheckBox *m_currentDate;

    bool m_dateAuto;
    QDate m_savedDate;

};

#endif // DATEITEM_H
