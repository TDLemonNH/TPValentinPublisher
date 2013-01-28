#ifndef CATEGORYDIALOG_H
#define CATEGORYDIALOG_H

#include <QtGui>
// Test

class CategoryDialog : public QDialog
{
    Q_OBJECT

public:
    CategoryDialog(QWidget *parent = 0);
    QString content() {return lineEdit->text();}
    
signals:

private:
    QLabel *label;
    QLineEdit *lineEdit;
    QDialogButtonBox *buttonBox;
    QGridLayout *layout;
    
};

#endif // CATEGORYDIALOG_H
