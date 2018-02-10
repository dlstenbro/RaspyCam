#include "camworker.h"

CamWorker::CamWorker()
{

}

CamWorker::~CamWorker()
{

}

void CamWorker::process()
{
    while(true)
    {
        cam.startCapture();
        emit updateView(ASM::cvMatToQPixmap(cam.getFrame()));
    }
}

void CamWorker::stopWork()
{
    cam.stopCapture();
    emit finished();
}

