#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <QApplication>
#include <viewframe.h>
#include <opencv2/video/video.hpp>
#include <omp.h>

using namespace std;

int main(int argc,char** argv)
{

//    cv::VideoCapture cap1(0);
//    cv::VideoCapture cap2(1);

    cv::Mat left;
    cv::Mat right;


//    while (true) {
//        double first = omp_get_wtime();
//        cap1 >> left;
//        cap2 >> right;
//        double next = omp_get_wtime();
//        std::cout << next - first << std::endl;
//    }

        QApplication *app = new QApplication(argc,argv);
        ImageConvertor* imageConvertor = new ImageConvertor();
        ViewFrame *viewFrame = new ViewFrame(0,0);
        viewFrame->show();

        return app->exec();
//    return 0;
}

