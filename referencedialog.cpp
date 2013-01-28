#include "referencedialog.h"
#include "editreferencedialog.h"

ReferenceDialog::ReferenceDialog(QWidget *parent) :
    QWidget(parent)
{
    this->setWindowTitle(trUtf8("Editeur de références"));

    m_treeWidget = new ReferenceTreeWidget;
    m_treeWidget->setAnimated(true);
    m_treeWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    m_treeWidget->setColumnCount(3);
    m_treeWidget->setRootIsDecorated(false);
    m_treeWidget->setHeaderHidden(true);

    m_title = new QLabel(trUtf8("Aucun fichier selectionné"));
    m_description = new QLabel(trUtf8("Aucun fichier selectionné"));
    m_filePath = new QLabel(trUtf8("Aucun fichier selectionné"));

    m_addButton = new QPushButton(trUtf8("Ajouter"));
    connect(m_addButton, SIGNAL(clicked()), this, SLOT(addReference()));
    m_editButton = new QPushButton(trUtf8("Editer"));
    connect(m_editButton, SIGNAL(clicked()), this, SLOT(editReference()));
    m_deleteButton = new QPushButton(trUtf8("Supprimer"));
    connect(m_deleteButton, SIGNAL(clicked()), this, SLOT(deleteReference()));

    m_buttonBox = new QDialogButtonBox(Qt::Horizontal);
    m_buttonBox->addButton(m_addButton, QDialogButtonBox::ActionRole);
    m_buttonBox->addButton(m_editButton, QDialogButtonBox::ActionRole);
    m_buttonBox->addButton(m_deleteButton, QDialogButtonBox::ActionRole);

    m_rightLayout = new QVBoxLayout;
    m_rightLayout->addWidget(m_title);
    m_rightLayout->addWidget(m_description);
    m_rightLayout->addWidget(m_filePath);
    m_rightLayout->addStretch(1);
    m_rightLayout->addWidget(m_buttonBox, Qt::AlignBottom);

    m_mainLayout = new QGridLayout;
    m_mainLayout->addWidget(m_treeWidget, 0, 0);
    m_mainLayout->addLayout(m_rightLayout, 0, 1);

    this->setLayout(m_mainLayout);
}

void ReferenceDialog::showAndHide()
{
    if(isVisible())
        hide();
    else
        show();
}

void ReferenceDialog::addReference()
{
    qDebug() << "Adding a reference";
    EditReferenceDialog dialog(this);
    dialog.resize(500, 300);

    if(dialog.exec())
    {
        QTreeWidgetItem *item = new QTreeWidgetItem(m_treeWidget);
        item->setText(0, dialog.title());
        item->setText(1, dialog.description());
        item->setText(2, dialog.filePath());
    }
}

void ReferenceDialog::editReference()
{
    qDebug() << "Editing a reference";
    EditReferenceDialog dialog(this);
    dialog.resize(500, 300);

    if(dialog.exec())
    {

    }
}

void ReferenceDialog::deleteReference()
{
    qDebug() << "Deleting a reference";
}
