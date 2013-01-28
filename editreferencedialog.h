#ifndef EDITREFERENCEDIALOG_H
#define EDITREFERENCEDIALOG_H

#include <QtGui>

class EditReferenceDialog : public QDialog
{
    Q_OBJECT
public:
    EditReferenceDialog(QWidget *parent = 0);
    QString filePath() {return m_filePathLineEdit->text();}
    QString title() {return m_titleLineEdit->text();}
    QString description() {return m_descriptionTextEdit->toPlainText();}
    
signals:
    
public slots:
    void selectFile();

protected:
    void accept();

private:
    QLabel *m_filePathLabel;
    QPushButton *m_selectFileButton;
    QLineEdit *m_filePathLineEdit;

    QLabel *m_titleLabel;
    QLineEdit *m_titleLineEdit;

    QLabel *m_descriptionLabel;
    QTextEdit *m_descriptionTextEdit;

    QDialogButtonBox *m_buttonBox;

    QVBoxLayout *m_layout;
};

#endif // EDITREFERENCEDIALOG_H
