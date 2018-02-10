#ifndef CAMWORKER_H
#define CAMWORKER_H

#include <QObject>
#include <QThread>
#include <camera.h>
#include <opencv2/opencv.hpp>
#include "asmopencv.h"

class CamWorker : public QObject
{
    Q_OBJECT
    public:
        CamWorker();
        ~CamWorker();
        void stopWork();

    public slots:
        void process();

    signals:
        void finished();
        void error(QString err);
        inline void updateView(QPixmap image);

    private:
        // add your variables here
        Camera cam;
};

#endif // CAMWORKER_H
