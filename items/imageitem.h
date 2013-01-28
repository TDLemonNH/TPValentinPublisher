#ifndef IMAGEITEM_H
#define IMAGEITEM_H

#include <QtGui>
#include "dynamicfield.h"

class ImageItem : public DynamicField
{
    Q_OBJECT
public:
    ImageItem(QString name, QWidget *parent = 0);
    QString name() {QString name = m_label->text(); name.chop(2); return name;}
    QString imagePath() {return m_fileLineEdit->text();}
    void setImagePath(QString path) {m_fileLineEdit->setText(path);
                                     m_pixmap->load(path);
                                     m_pixmapLabel->setPixmap(*m_pixmap);}

public slots:
    void selectFile();

private:
    QGridLayout *m_layout;
    QLabel *m_label;
    QLineEdit *m_fileLineEdit;
    QPushButton *m_selectFileButton;
    QPixmap *m_pixmap;
    QLabel *m_pixmapLabel;
};

#endif // IMAGEITEM_H
