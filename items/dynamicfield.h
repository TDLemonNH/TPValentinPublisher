#ifndef DYNAMICFIELD_H
#define DYNAMICFIELD_H

#include <QtGui>

class DynamicField : public QWidget
{
    Q_OBJECT
public:
    explicit DynamicField(QWidget *parent = 0);
    
signals:
    void deleteMe(DynamicField *toDelete);
    
public slots:
    void showDeleteButton();
    void hideDeleteButton();
    void deleteMe();

protected:
    void addCentralLayout(QLayout *layout);

private:
    QPushButton *m_deleteButton;
    QHBoxLayout *m_layout;
    QLineEdit *m_refLineEdit;
    
};

#endif // DYNAMICFIELD_H
