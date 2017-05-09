#include "viewframe.h"
#include "ui_viewframe.h"
#include <QLabel>
#include <QDebug>
#include <QGraphicsScene>
#include <QFileDialog>


ViewFrame::ViewFrame(QWidget *parent,cv::Mat *main_image) :
    QDialog(parent),
    ui(new Ui::ViewFrame)
{
    ui->setupUi(this);
    imageConvertor = new ImageConvertor();
    convolv = new Convolution_filters();

    connect(ui->buttonGroup,SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(button_clicked(QAbstractButton*)));
}

void ViewFrame::button_clicked(QAbstractButton *button){
    QCheckBox *checkbox = (QCheckBox*)button;
    cv::Mat conved = convolv->do_filter(this->main_image,checkbox->text());
    showConvedImage(conved);
}


ViewFrame::~ViewFrame()
{
    delete ui;
}

void ViewFrame::on_files_clicked(){
    QString str = QFileDialog::getOpenFileName(this,tr("Open image"),"/home");
    ui->path->setText(str);
    cv::Mat image = cv::imread(str.toStdString().c_str());
    cv::Mat *gray = new cv::Mat();
    cv::cvtColor(image,*gray,CV_BGR2GRAY);
    this->main_image = gray;
    main_gray = imageConvertor->cv_mat_to_qimage(*this->main_image);
    QLabel *myLabel = new QLabel(ui->mainImg); // sets parent of label to main window
    myLabel->setPixmap(QPixmap::fromImage(*main_gray));
    myLabel->show();
}
void ViewFrame::showConvedImage(cv::Mat conved){
    qDebug() << conved.cols << "@@@" << conved.rows ;
    this->convolved_image = imageConvertor->cv_mat_to_qimage(conved);

    QLabel *myLabel = new QLabel(ui->convedimg); // sets parent of label to main window
    myLabel->setPixmap(QPixmap::fromImage(*this->convolved_image));
    myLabel->show();
}
