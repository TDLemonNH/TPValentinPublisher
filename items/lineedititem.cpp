#include "lineedititem.h"

LineEditItem::LineEditItem(QString name, QWidget *parent) :
    DynamicField(parent)
{
    QString label = name + " :";
    this->m_label = new QLabel(label, this);
    this->m_dataLineEdit = new QLineEdit(this);

    this->m_layout = new QGridLayout();
    m_layout->addWidget(m_label, 0, 0);
    m_layout->addWidget(m_dataLineEdit, 0, 1);

    this->addCentralLayout(m_layout);
}
