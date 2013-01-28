#ifndef REFERENCEDIALOG_H
#define REFERENCEDIALOG_H

#include <QtGui>
#include "referencetreewidget.h"

class ReferenceDialog : public QWidget
{
    Q_OBJECT
public:
    ReferenceDialog(QWidget *parent = 0);
    
signals:
    
public slots:
    void showAndHide();

private slots:
    void addReference();
    void editReference();
    void deleteReference();

private:
    ReferenceTreeWidget *m_treeWidget;
    QLabel *m_title;
    QLabel *m_description;
    QLabel *m_filePath;

    QDialogButtonBox *m_buttonBox;
    QPushButton *m_addButton;
    QPushButton *m_editButton;
    QPushButton *m_deleteButton;

    QGridLayout *m_mainLayout;
    QVBoxLayout *m_rightLayout;
};

#endif // REFERENCEDIALOG_H
