#ifndef CAMERA_H
#define CAMERA_H

#include <opencv2/opencv.hpp>
#include <QObject>
#include <ctime>

class Camera
{

    public:

        // variables
        cv::VideoCapture cap;
        cv::Mat cf;

        // functions
        Camera();
        void startCapture();
        void stopCapture();
        cv::Mat getFrame();

    private:

        // variables

        // functions
        void setFrame(cv::Mat frame);
};

#endif // CAMERA_H
