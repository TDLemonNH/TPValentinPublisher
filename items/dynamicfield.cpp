#include "dynamicfield.h"

DynamicField::DynamicField(QWidget *parent) :
    QWidget(parent)
{
    m_deleteButton = new QPushButton(this);
    m_deleteButton->setIcon(QIcon(":/img/delete.png"));
    m_deleteButton->hide();
    connect(m_deleteButton, SIGNAL(clicked()), this, SLOT(deleteMe()));

    m_refLineEdit = new QLineEdit(this);
    m_refLineEdit->hide();

    m_layout = new QHBoxLayout(this);

    this->setLayout(m_layout);
}


void DynamicField::addCentralLayout(QLayout *layout)
{
    m_layout->insertLayout(0, layout, 1);
}


void DynamicField::showDeleteButton()
{
    m_layout->addWidget(m_deleteButton);
    m_layout->setAlignment(m_deleteButton, Qt::AlignBottom);
    m_deleteButton->show();
}

void DynamicField::hideDeleteButton()
{
    m_layout->removeWidget(m_deleteButton);
    m_deleteButton->hide();
}

void DynamicField::deleteMe()
{
    emit deleteMe(this);
}
