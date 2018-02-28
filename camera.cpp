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
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );

/*
    std::cout << (now->tm_year + 1900) << '-'
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday
         << " "
         << now->tm_hour
         << now->tm_min
         << now->tm_sec
         <<std::endl;
*/
    cv::Mat frame;
    this->cap >> frame;

    int yearText = (now->tm_year + 1900);
    int monthText = (now->tm_mon+1);
    int dayText = now->tm_mday;

    std::string convertedTime = std::to_string(yearText) +
            "/" + std::to_string(monthText) +
            "/" + std::to_string(dayText) +
            " " + std::to_string(now->tm_hour) +
            ":" + std::to_string(now->tm_min) +
            ":" + std::to_string(now->tm_sec);

    cv::putText(frame,convertedTime,cvPoint(30,30),cv::FONT_HERSHEY_DUPLEX, 0.8, cvScalar(0,250,0), 1, CV_AA);
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
