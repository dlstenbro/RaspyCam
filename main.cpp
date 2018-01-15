#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QImage>
#include <opencv2/opencv.hpp>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    cv::Mat inputImage = cv::imread("/home/daniel/Downloads/test.png");
    cv::imshow("Image", inputImage);

    return a.exec();
}
