#ifndef IMAGECONVERTOR_H
#define IMAGECONVERTOR_H
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgproc/types_c.h"

#include <QImage>
#include <QPixmap>


class ImageConvertor
{
public:
    ImageConvertor();
    QImage* cv_mat_to_qimage(const cv::Mat &inMat);
};

#endif // IMAGECONVERTOR_H
