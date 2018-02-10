#include <iostream>

#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    QThread* thread = new QThread;
    CamWorker* worker = new CamWorker();

    QObject::connect( worker, SIGNAL( updateView(QPixmap) ), this, SLOT( showData(QPixmap)) );

    if(sigText == "Start")
    {
        worker->moveToThread(thread);
        //connect(worker, SIGNAL (error(QString)), this, SLOT (errorString(QString)));
        connect(thread, SIGNAL (started()), worker, SLOT (process()));
        connect(worker, SIGNAL (finished()), thread, SLOT (quit()));
        connect(worker, SIGNAL (finished()), worker, SLOT (deleteLater()));
        connect(thread, SIGNAL (finished()), thread, SLOT (deleteLater()));
        thread->start();

    }

    if(sigText == "Stop")
    {
        /*
            QMessageBox msgBox;
            msgBox.setWindowTitle("MessageBox Title");
            msgBox.setText("You clicked "+ ((QPushButton*)sender())->text());
            msgBox.exec();
        */
        worker->stopWork();
    }


}

void MainWindow::showData(QPixmap image)
{

    ui->label_img->setPixmap(image);
    ui->label_img->show();

}
