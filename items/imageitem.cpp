#include "imageitem.h"

ImageItem::ImageItem(QString name, QWidget *parent) :
    DynamicField(parent)
{
    QString label = name + " :";
    m_label = new QLabel(label, this);

    m_selectFileButton = new QPushButton(this);
    m_selectFileButton->setIcon(QIcon(":/img/folder.png"));
    connect(m_selectFileButton, SIGNAL(clicked()), this, SLOT(selectFile()));

    m_fileLineEdit = new QLineEdit(this);
    m_fileLineEdit->setReadOnly(true);

    m_pixmap = new QPixmap();
    m_pixmapLabel = new QLabel(trUtf8("Aucune image sélectionnée"), this);
    m_pixmapLabel->setAlignment(Qt::AlignCenter);

    m_layout = new QGridLayout();
    m_layout->addWidget(m_label, 0, 0);
    m_layout->addWidget(m_fileLineEdit, 0, 1);
    m_layout->addWidget(m_selectFileButton, 0, 2);
    m_layout->addWidget(m_pixmapLabel, 1, 0, 1, 2);

    this->addCentralLayout(m_layout);
}
void ImageItem::selectFile()
{
    qDebug() << "Select image file";
    QString fileName = QFileDialog::getOpenFileName(this, tr("Choisir une image"),
                                                    "/home",
                                                    tr("Images (*.png *.jpg *.jpeg *.bmp)"));

    if(fileName != "")
    {
        m_fileLineEdit->setText(fileName);

        m_pixmap->load(fileName);
        m_pixmapLabel->setPixmap(*m_pixmap);
    }
}
