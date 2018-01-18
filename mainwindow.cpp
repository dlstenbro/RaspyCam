#include <iostream>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "asmopencv.h"
#include "camera.h"

#include <QLabel>
#include <QPixmap>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(buttonClickEvent()));
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(buttonClickEvent()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::buttonClickEvent()
{

    QString sigText = ((QPushButton*)sender())->text();

    if(sigText == "Start")
    {
        //QMessageBox msgBox;
        //msgBox.setWindowTitle("MessageBox Title");
        //msgBox.setText("You clicked "+ ((QPushButton*)sender())->text());
        MainWindow::imgData();
        //msgBox.exec();
    }
    else if(sigText == "Stop")
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("MessageBox Title");

        msgBox.setText("You clicked "+ ((QPushButton*)sender())->text());
        msgBox.exec();
    }


}

void MainWindow::imgData()
{

    Camera camera;      // init camera object
    camera.startCapture();
    QPixmap image = ASM::cvMatToQPixmap(camera.getFrame());
    ui->label_img->setPixmap(image);
    ui->label_img->show();
}
