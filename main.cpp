#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <QApplication>
#include <viewframe.h>

using namespace std;

int main(int argc,char** argv)
{
    QApplication *app = new QApplication(argc,argv);
//    ImageConvertor* imageConvertor = new ImageConvertor();
    ViewFrame *viewFrame = new ViewFrame(0,0);
    viewFrame->show();

    return app->exec();
}

