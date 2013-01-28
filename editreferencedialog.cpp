#include "editreferencedialog.h"

EditReferenceDialog::EditReferenceDialog(QWidget *parent) :
    QDialog(parent)
{
    m_filePathLabel = new QLabel(trUtf8("Emplacement : "));
    m_selectFileButton = new QPushButton(QIcon(":/img/folder.png"), "");
    connect(m_selectFileButton, SIGNAL(clicked()), this, SLOT(selectFile()));
    m_filePathLineEdit = new QLineEdit;
    m_filePathLineEdit->setReadOnly(true);

    m_titleLabel = new QLabel(trUtf8("Titre : "));
    m_titleLineEdit = new QLineEdit(trUtf8("Titre du document"));

    m_descriptionLabel = new QLabel(trUtf8("Description : "));
    m_descriptionTextEdit = new QTextEdit(trUtf8("Description du document"));

    m_buttonBox = new QDialogButtonBox(QDialogButtonBox::Save | QDialogButtonBox::Cancel);
    connect(m_buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(m_buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    m_layout = new QVBoxLayout;
    QHBoxLayout *fileLayout = new QHBoxLayout;
    fileLayout->addWidget(m_filePathLineEdit);
    fileLayout->addWidget(m_selectFileButton);
    m_layout->addWidget(m_filePathLabel);
    m_layout->addLayout(fileLayout);
    m_layout->addWidget(m_titleLabel);
    m_layout->addWidget(m_titleLineEdit);
    m_layout->addWidget(m_descriptionLabel);
    m_layout->addWidget(m_descriptionTextEdit);
    m_layout->addWidget(m_buttonBox);

    this->setLayout(m_layout);
}

void EditReferenceDialog::selectFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Selectionner un document"),
                                                    "/home",
                                                    tr("Tous les documents (*.pdf *.doc *.docx *.xml"));
    if(fileName != "")
    {
        m_filePathLineEdit->setText(fileName);
    }
}

void EditReferenceDialog::accept()
{
    if(!m_filePathLineEdit->text().isEmpty())
        QDialog::accept();
    else
        QMessageBox::warning(this, trUtf8("Aucun document"), trUtf8("Aucun document sélectionné"), QMessageBox::Ok);
}
