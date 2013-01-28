#include "dateitem.h"

DateItem::DateItem(QString name, QWidget *parent) :
    DynamicField(parent)
{
    QString label = name + " :";
    m_label = new QLabel(label, this);

    m_dateEdit = new QDateEdit(this);
    m_dateEdit->setDate(QDate::currentDate());

    m_currentDate = new QCheckBox(trUtf8("Automatique"), this);
    connect(m_currentDate, SIGNAL(clicked()), this, SLOT(dateAuto()));
    m_dateAuto = false;

    m_layout = new QGridLayout();
    m_layout->addWidget(m_label, 0, 0);
    m_layout->addWidget(m_dateEdit, 0, 1);
    m_layout->addWidget(m_currentDate, 0, 2);
    m_layout->setColumnStretch(0, 0);
    m_layout->setColumnStretch(1, 1);
    m_layout->setColumnStretch(2, 0);

    this->addCentralLayout(m_layout);
}

QString DateItem::currentDateAuto()
{
    if(m_currentDate->isChecked())
        return QString("1");
    else
        return QString("0");
}

void DateItem::dateAuto()
{
    m_dateAuto = !m_dateAuto;
    m_dateEdit->setEnabled(!m_dateAuto);
    if(m_dateAuto)
    {
        m_savedDate = m_dateEdit->date();
        m_dateEdit->setDate(QDate::currentDate());
    }
    else
        m_dateEdit->setDate(m_savedDate);
}

