#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include "publishertreeview.h"
#include "generaldatawidget.h"
#include "referencedialog.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    GeneralDataWidget* generalDataWidget() {return dataWidget;}
    PublisherTreeView* publisherTreeView() {return treeView;}
    ~MainWindow();

public slots:
    QMenu* getTreeViewMenu() {return treeViewMenu;}

private slots:
    void newFile();
    void saveFile();
    void openFile();

private:
    void createActions();
    void createMenus();
    void createToolBars();
    void createStatusBar();

    // Menus
    QMenu *fileMenu;
    QMenu *treeViewMenu;

    // Toolbars
    QToolBar *mainToolBar;

    // Central area
    QSplitter *centralWidget;
    PublisherTreeView *treeView;
    GeneralDataWidget *dataWidget;

    // Other widgets
    ReferenceDialog *referenceDialog;

    // Actions
    // General actions
    QAction *newAction;
    QAction *openAction;
    QAction *saveAction;
    QAction *saveAsAction;
    QAction *exitAction;
    // TreeView actions
    QAction *addCategoryAction;
    // Reference management actions
    QAction *openReferenceDialogAction;
};

#endif // MAINWINDOW_H
