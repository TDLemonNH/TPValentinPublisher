#ifndef LINEEDITITEM_H
#define LINEEDITITEM_H

#include <QtGui>
#include "dynamicfield.h"

class LineEditItem : public DynamicField
{
    Q_OBJECT
public:
    explicit LineEditItem(QString name, QWidget *parent = 0);
    QString name() {QString name = m_label->text(); name.chop(2); return name;}
    QString content() {return m_dataLineEdit->text();}
    void setContent(QString content) {m_dataLineEdit->setText(content);}
    
signals:
    
public slots:

private:
    QGridLayout *m_layout;
    QLineEdit *m_dataLineEdit;
    QLabel *m_label;
    
};

#endif // LINEEDITITEM_H
