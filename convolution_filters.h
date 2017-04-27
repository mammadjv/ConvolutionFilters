#ifndef CONVOLUTION_FILTERS_H
#define CONVOLUTION_FILTERS_H

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <QObject>
#include <QString>

class Convolution_filters : public QObject
{
    Q_OBJECT
public:
    Convolution_filters();
    cv::Mat conv(cv::Mat *mat,float** convMat,int x_size , int y_size);
    cv::Mat do_filter(cv::Mat *mat , QString filter_name);
};

#endif // CONVOLUTION_FILTERS_H
