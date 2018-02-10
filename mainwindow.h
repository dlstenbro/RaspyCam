#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <camworker.h>

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QMessageBox>
#include <QThread>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
   void buttonClickEvent();

public slots:
   void showData(QPixmap image);

signals:
    void finished();
    void error(QString err);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
