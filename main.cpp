#include "mainwindow.h"
#include "components/playarea/playarea.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    PlayArea *pa = new PlayArea;
    w.setCentralWidget(pa);
    w.show();
    return a.exec();
}
