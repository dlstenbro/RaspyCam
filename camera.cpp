#include "camera.h"

Camera::Camera()
{
    cv::VideoCapture camera(0);
    this->cap = camera;

    if(!this->cap.isOpened())
    {
        std::cout << "Could not load camera!" << std::endl;
    }

}

void Camera::startCapture()
{

    cv::Mat frame;
    this->cap >> frame;
    //cv::imshow("feed", frame);
    setFrame(frame);

}

void Camera::setFrame(cv::Mat frame)
{
    this->cf = frame;
}

cv::Mat Camera::getFrame()
{
    return this->cf;
}

void Camera::stopCapture()
{
    this->cap.release();
}
