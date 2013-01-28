#include "categorydialog.h"

CategoryDialog::CategoryDialog(QWidget *parent) :
    QDialog(parent)
{
    label = new QLabel(trUtf8("Nom : "));
    lineEdit = new QLineEdit;
    lineEdit->setMinimumWidth(300);
    label->setBuddy(lineEdit);

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Save | QDialogButtonBox::Cancel);
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    layout = new QGridLayout;
    layout->addWidget(label, 0, 0);
    layout->addWidget(lineEdit, 0, 1);
    layout->addWidget(buttonBox, 1, 0, 1, 2);

    this->setLayout(layout);
}

