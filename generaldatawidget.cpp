#include "generaldatawidget.h"

GeneralDataWidget::GeneralDataWidget(QWidget *parent) :
    QScrollArea(parent)
{
    this->m_layout = new QVBoxLayout();
    m_showDeleteButtons = false;

    m_addButton = new QToolButton(this);
        m_addButton->setIcon(QIcon(":/img/add.png"));
        m_addButton->setText(trUtf8("Nouveau champ  "));
        m_addButton->setPopupMode(QToolButton::InstantPopup);
        m_addButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    m_deleteButton = new QPushButton(this);
        m_deleteButton->setIcon(QIcon(":/img/delete.png"));
        connect(m_deleteButton, SIGNAL(clicked()), this, SLOT(showDeleteButtons()));
    QHBoxLayout *buttonsLayout = new QHBoxLayout();
        buttonsLayout->addWidget(m_addButton);
        buttonsLayout->addWidget(m_deleteButton);
        buttonsLayout->setAlignment(Qt::AlignRight);
    m_layout->addStretch(1);
    m_layout->addLayout(buttonsLayout);
    m_layout->setSpacing(0);

    m_newFieldMenu = new QMenu(trUtf8("Nouveau champ"));
    m_newFieldMenu->addAction(trUtf8("Texte"));
    m_newFieldMenu->addAction(trUtf8("Image"));
    m_newFieldMenu->addAction(trUtf8("Date"));
    m_newFieldMenu->addAction(trUtf8("Case à cocher"));
    m_addButton->setMenu(m_newFieldMenu);
    connect(m_newFieldMenu, SIGNAL(triggered(QAction*)), this, SLOT(addMenuTriggered(QAction*)));

    QWidget *scrollWidget = new QWidget(this);
    scrollWidget->setLayout(m_layout);
    this->setWidget(scrollWidget);
    this->setWidgetResizable(true);
    this->setFrameShape(QFrame::NoFrame);

    m_widgetList = new QList<DynamicField *>();
}

void GeneralDataWidget::addMenuTriggered(QAction *action)
{
    if(action->text() == trUtf8("Texte"))
        this->addTextField();
    else if(action->text() == trUtf8("Image"))
        this->addImageField();
    else if(action->text() == trUtf8("Date"))
        this->addDateField();
    else if(action->text() == trUtf8("Case à cocher"))
        this->addCheckBoxField();
    else
        qDebug() << "Add menu triggered : unknown action " << action->text();
}

void GeneralDataWidget::addDynamicField(DynamicField *widget)
{
    if(m_showDeleteButtons)
        widget->showDeleteButton();
    m_widgetList->append(widget);

    int index = m_layout->count()-2;
    m_layout->insertWidget(index, widget); // -2 because of the add button and the spacer
    m_layout->setSizeConstraint(QLayout::SetMinAndMaxSize);

    connect(widget, SIGNAL(deleteMe(DynamicField*)), this, SLOT(deleteWidget(DynamicField*)));
}


void GeneralDataWidget::addTextField()
{
    bool ok;
    QString text = QInputDialog::getText(this, trUtf8("Créer un nouveau champ texte"), trUtf8("Nom du champ :"),
                                         QLineEdit::Normal, QString(), &ok);

    if(ok && !text.isEmpty())
        this->addDynamicField(new LineEditItem(text, this));
}

void GeneralDataWidget::addImageField()
{
    bool ok;
    QString text = QInputDialog::getText(this, trUtf8("Créer un nouveau champ image"), trUtf8("Nom du champ :"),
                                         QLineEdit::Normal, QString(), &ok);

    if(ok && !text.isEmpty())
        this->addDynamicField(new ImageItem(text, this));
}

void GeneralDataWidget::addDateField()
{
    bool ok;
    QString text = QInputDialog::getText(this, trUtf8("Créer un nouveau champ date"), trUtf8("Nom du champ :"),
                                         QLineEdit::Normal, QString(), &ok);

    if(ok && !text.isEmpty())
        this->addDynamicField(new DateItem(text, this));
}

void GeneralDataWidget::addCheckBoxField()
{
    qDebug() << "Add check box field";
}

void GeneralDataWidget::showDeleteButtons()
{
    m_showDeleteButtons = !m_showDeleteButtons;
    if(m_widgetList->count() > 0)
    {
        for(int i = 0; i<m_widgetList->count(); i++)
        {
            if(m_showDeleteButtons)
                m_widgetList->at(i)->showDeleteButton();
            else
                m_widgetList->at(i)->hideDeleteButton();
        }
    }
}

void GeneralDataWidget::deleteWidget(DynamicField *widget)
{
    qDebug() << "Deleting widget";
    m_widgetList->removeOne(widget);
    m_layout->removeWidget(widget);
    delete widget;
}

/*void GeneralDataWidget::saveLayoutToFile(QString fileName)
{
    qDebug() << "Saving to file : " << fileName;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Impossible d'ouvrir le fichier";
        QMessageBox::warning(this, trUtf8("Erreur"), trUtf8("Impossible d'ouvrir le fichier ").append(fileName),
                             QMessageBox::Ok);
    }
}*/
