#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QImage>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;

    window.show();

    return app.exec();
}
