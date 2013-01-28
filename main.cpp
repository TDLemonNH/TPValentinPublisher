#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
        w.resize(800, 600);
        w.show();

    QTranslator qtTranslator;
         qtTranslator.load("qt_fr_FR",
                 QLibraryInfo::location(QLibraryInfo::TranslationsPath));
         a.installTranslator(&qtTranslator);
    
    return a.exec();
}
