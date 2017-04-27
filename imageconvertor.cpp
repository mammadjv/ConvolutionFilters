#include "imageconvertor.h"
#include <QDebug>
#include <QRgb>

ImageConvertor::ImageConvertor()
{
}


QImage* ImageConvertor::cv_mat_to_qimage(const cv::Mat &inMat){
    QImage *qi = new QImage(inMat.cols, inMat.rows, QImage::Format_RGB32);
    for (int i = 0; i < inMat.cols; i++)
    {
        for (int j = 0; j < inMat.rows; j++)
        {
            int gray = inMat.at<uchar>(j,i);
            qi->setPixel(i, j, qRgb(gray,gray,gray));
        }
    }
    return qi;
}
