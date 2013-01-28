#include "mainwindow.h"
#include "xml/xmlinterfacewriter.h"
#include "xml/xmlinterfacereader.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->treeView = new PublisherTreeView(this);
    this->dataWidget = new GeneralDataWidget(this);
    this->referenceDialog = new ReferenceDialog();
    referenceDialog->resize(650, 500);
    referenceDialog->hide();

    this->createActions();
    this->createMenus();
    this->createToolBars();
    this->createStatusBar();

    this->setWindowTitle(trUtf8("TP Valentin Publisher"));

    // Central widget setup

    this->centralWidget = new QSplitter();
    centralWidget->addWidget(treeView);
    centralWidget->setStretchFactor(0, 1);
    centralWidget->addWidget(dataWidget);
    centralWidget->setStretchFactor(1, 3);
    this->setCentralWidget(centralWidget);
}

// Slots

void MainWindow::newFile()
{
    qDebug() << "Create a new file !";
}

void MainWindow::saveFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Enregistrer"));

    if(fileName != "")
    {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, trUtf8("Erreur"), trUtf8("Impossible d'ouvrir le fichier %1 : %2").arg(fileName).arg(file.errorString()),
                                 QMessageBox::Ok);
        }

        XMLInterfaceWriter writer(this);
        if(writer.writeFile(&file))
            this->statusBar()->showMessage(trUtf8("Document enregistré"), 2000);
    }
}

void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Ouvrir..."));

    if(fileName != "")
    {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, trUtf8("Erreur"), trUtf8("Impossible d'ouvrir le fichier %1 : %2").arg(fileName).arg(file.errorString()),
                                 QMessageBox::Ok);
        }

        XMLInterfaceReader reader(this);
        if(reader.readFile(&file))
            this->statusBar()->showMessage(trUtf8("Document ouvert"), 2000);
    }
}

// Application initialization functions

void MainWindow::createActions()
{
    this->newAction = new QAction(QIcon(":/img/new.png"), trUtf8("&Nouveau"), this);
    newAction->setShortcut(QKeySequence::New);
    newAction->setStatusTip(trUtf8("Créer un nouveau document"));
    connect(newAction, SIGNAL(triggered()), this, SLOT(newFile()));

    this->saveAction = new QAction(QIcon(":/img/save.png"), trUtf8("&Enregistrer"), this);
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setStatusTip(trUtf8("Sauvegarder le document en cours d'édition"));
    connect(saveAction, SIGNAL(triggered()), this, SLOT(saveFile()));

    this->openAction = new QAction(QIcon(":/img/folder.png"), trUtf8("&Ouvrir..."), this);
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(trUtf8("Ouvrir un document"));
    connect(openAction, SIGNAL(triggered()), this, SLOT(openFile()));

    this->addCategoryAction = new QAction(QIcon(":/img/add.png"), trUtf8("Ajouter une partie"), this);
    addCategoryAction->setStatusTip(trUtf8("Ajouter une partie au document"));
    connect(addCategoryAction, SIGNAL(triggered()), treeView, SLOT(addSubCategory()));

    this->openReferenceDialogAction = new QAction(trUtf8("Références"), this);
    openReferenceDialogAction->setStatusTip(trUtf8("Ouvrir le gestionnaire de références"));
    connect(openReferenceDialogAction, SIGNAL(triggered()), referenceDialog, SLOT(showAndHide()));
}

void MainWindow::createMenus()
{
    this->fileMenu = this->menuBar()->addMenu(trUtf8("&Fichier"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(openAction);

    this->treeViewMenu = this->menuBar()->addMenu(trUtf8("&Structure"));
    treeViewMenu->addAction(addCategoryAction);
}

void MainWindow::createToolBars()
{
    this->mainToolBar = this->addToolBar(trUtf8("Barre principale"));
    mainToolBar->addAction(newAction);
    mainToolBar->addAction(saveAction);
    mainToolBar->addAction(openAction);

    mainToolBar->addSeparator();

    mainToolBar->addAction(addCategoryAction);

    mainToolBar->addSeparator();

    mainToolBar->addAction(openReferenceDialogAction);
}

void MainWindow::createStatusBar()
{
    statusBar()->showMessage(trUtf8("Prêt"));
}

MainWindow::~MainWindow()
{
}
