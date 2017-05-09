#ifndef VIEWFRAME_H
#define VIEWFRAME_H

#include <QDialog>
#include <opencv2/opencv.hpp>
#include <imageconvertor.h>
#include <convolution_filters.h>
#include <QAbstractButton>

namespace Ui {
class ViewFrame;
}

class ViewFrame : public QDialog
{
    Q_OBJECT

public:
    explicit ViewFrame(QWidget *parent = 0 , cv::Mat *main_image = 0);
    ~ViewFrame();
    Convolution_filters* convolv ;
private:
    Ui::ViewFrame *ui;
    ImageConvertor* imageConvertor;
    cv::Mat *main_image;
    QImage *main_gray;
    QImage *convolved_image;
    void showConvedImage(cv::Mat conved);

public slots:
    void on_files_clicked();
    void button_clicked(QAbstractButton*);

};

#endif // VIEWFRAME_H
