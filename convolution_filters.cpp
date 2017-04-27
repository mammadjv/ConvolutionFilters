#include "convolution_filters.h"
#include <QDebug>

Convolution_filters::Convolution_filters()
{

}
cv::Mat Convolution_filters::conv(cv::Mat *mat,float** convMat,int x_size , int y_size){
    cv::Mat other = cv::Mat::zeros(mat->rows,mat->cols,CV_16U);
    int mid_x = x_size/2;
    int mid_y = y_size/2;

    int** image = new int*[mat->cols];
    for(int x = 0 ;x < mat->cols ; x++){
        image[x] = new int[mat->rows];
    }

    int max = 255 , min = 0;

    for(int y = mid_y ; y < mat->rows-mid_y ; y++){
        for(int x = mid_x  ; x < mat->cols-mid_x ; x++){
            int value = 0;
            for(int c_y = -mid_y ; c_y <= mid_y ; c_y+=1){
                for(int c_x = -mid_x ; c_x <= mid_x ; c_x+=1){
                    value += (float)(mat->at<uchar>(y+c_y,x+c_x))*convMat[c_x+mid_x][c_y+mid_y];
                }
            }
            if(value > max){
                max = value;
            }
            if(value < min){
                min = value;
            }
            image[x][y] = value;
        }
    }

    if(max == 255 && min == 0){
        for(int y = mid_y ; y < mat->rows - mid_y ;y++){
            for(int x = mid_x ; x < mat->cols - mid_x ;x++){
                other.at<uchar>(y,x) = image[x][y];
            }
        }
        return other;
    }

    float range = max - min;
    for(int y = mid_y ; y < mat->rows - mid_y ; y++){
        for(int x = mid_x  ; x < mat->cols - mid_x ; x++){
            float dist = (float)(image[x][y] - min);
            int value = (dist/(float)range)*255.00;
            other.at<uchar>(y,x) = value;
        }
    }
    return other;
}

cv::Mat Convolution_filters::do_filter(cv::Mat *mat , QString filter_name){
    float** filter;
    int x_kernel , y_kernel;
    if(filter_name == "LP1"){
        filter = new float*[3];
        for(int x = 0 ; x < 3 ; x++){
            filter[x] = new float[3];
            for(int y = 0 ; y < 3 ; y++)
                filter[x][y] = float(1.00)/float(9.00);
        }
        x_kernel = 3;
        y_kernel = 3;
    }

    if( filter_name == "LP2"){
        filter = new float*[3];
        for(int x = 0 ; x < 3 ; x++){
            filter[x] = new float[3];
            for(int y = 0 ; y < 3 ; y++)
                filter[x][y] = float(1.00)/float(10.00);
        }
        filter[1][1] = float(1.00)/float(5.00);
        x_kernel = 3;
        y_kernel = 3;
    }

    if( filter_name == "LP3"){
        filter = new float*[3];
        for(int x = 0 ; x < 3 ; x++){
            filter[x] = new float[3];
        }

        filter[0][0] = (1.00)/(16.00);
        filter[1][0] = (1.00)/(8.00);
        filter[2][0] = (1.00)/(16.00);

        filter[0][1] = (1.00)/(8.00);
        filter[1][1] = (1.00)/(4.00);
        filter[2][1] = (1.00)/(8.00);

        filter[0][2] = (1.00)/(16.00);
        filter[1][2] = (1.00)/(8.00);
        filter[2][2] = (1.00)/(16.00);

        x_kernel = 3;
        y_kernel = 3;
    }

    if( filter_name == "HP1"){
        filter = new float*[3];
        for(int x = 0 ; x < 3 ; x++){
            filter[x] = new float[3];
            for(int y = 0 ; y < 3 ; y++)
                filter[x][y] = -1.00;
        }
        filter[1][1] = 9.00;

        x_kernel = 3;
        y_kernel = 3;
    }

    if( filter_name == "HP2"){
        filter = new float*[3];
        for(int x = 0 ; x < 3 ; x++){
            filter[x] = new float[3];
        }

        filter[0][0] = (0.00);
        filter[1][0] = (-1.00);
        filter[2][0] = (0.00);

        filter[0][1] = (-1.00);
        filter[1][1] = (5.00);
        filter[2][1] = (-1.00);

        filter[0][2] = (0.00);
        filter[1][2] = (-1.00);
        filter[2][2] = (0.00);

        x_kernel = 3;
        y_kernel = 3;
    }

    if( filter_name == "HP3"){
        filter = new float*[3];
        for(int x = 0 ; x < 3 ; x++){
            filter[x] = new float;
        }

        filter[0][0] = (1.00);
        filter[1][0] = (-2.00);
        filter[2][0] = (1.00);

        filter[0][1] = (-2.00);
        filter[1][1] = (5.00);
        filter[2][1] = (-2.00);

        filter[0][2] = (1.00);
        filter[1][2] = (-2.00);
        filter[2][2] = (1.00);

        x_kernel = 3;
        y_kernel = 3;
    }

    if( filter_name == "ver_edges"){
        filter = new float*[3];
        for(int x = 0 ; x < 3 ; x++){
            filter[x] = new float[3];
        }

        filter[0][0] = (0.00);
        filter[1][0] = (0.00);
        filter[2][0] = (0.00);

        filter[0][1] = (-1.00);
        filter[1][1] = (1.00);
        filter[2][1] = (0.00);

        filter[0][2] = (0.00);
        filter[1][2] = (0.00);
        filter[2][2] = (0.00);

        x_kernel = 3;
        y_kernel = 3;

    }

    if( filter_name == "hor_edges"){
        filter = new float*[3];
        for(int x = 0 ; x < 3 ; x++){
            filter[x] = new float[3];
        }

        filter[0][0] = (0.00);
        filter[1][0] = (-1.00);
        filter[2][0] = (0.00);

        filter[0][1] = (0.00);
        filter[1][1] = (1.00);
        filter[2][1] = (0.00);

        filter[0][2] = (0.00);
        filter[1][2] = (0.00);
        filter[2][2] = (0.00);

        x_kernel = 3;
        y_kernel = 3;
    }

    if( filter_name == "horver_edges"){
        filter = new float*[3];
        for(int x = 0 ; x < 3 ; x++){
            filter[x] = new float[3];
        }

        filter[0][0] = (-1.00);
        filter[1][0] = (0.00);
        filter[2][0] = (0.00);

        filter[0][1] = (0.00);
        filter[1][1] = (1.00);
        filter[2][1] = (0.00);

        filter[0][2] = (0.00);
        filter[1][2] = (0.00);
        filter[2][2] = (0.00);

        x_kernel = 3;
        y_kernel = 3;
    }

    if( filter_name == "sec_ver_edges"){
        filter = new float*[3];
        for(int x = 0 ; x < 3 ; x++){
            filter[x] = new float[5];
        }
        filter[0][0] = (-1.00);
        filter[1][0] = (0.00);
        filter[2][0] = (1.00);

        filter[0][1] = (-1.00);
        filter[1][1] = (0.00);
        filter[2][1] = (1.00);

        filter[0][2] = (-1.00);
        filter[1][2] = (0.00);
        filter[2][2] = (1.00);

        filter[0][3] = (-1.00);
        filter[1][3] = (0.00);
        filter[2][3] = (1.00);

        filter[0][4] = (-1.00);
        filter[1][4] = (0.00);
        filter[2][4] = (1.00);

        x_kernel = 3;
        y_kernel = 5;

    }

    if( filter_name == "sec_hor_edges"){
        filter = new float*[5];
        for(int x = 0 ; x < 5 ; x++){
            filter[x] = new float[3];
        }
        filter[0][0] = (-1.00);
        filter[1][0] = (-1.00);
        filter[2][0] = (-1.00);
        filter[3][0] = (-1.00);
        filter[4][0] = (-1.00);

        filter[0][1] = (0.00);
        filter[1][1] = (0.00);
        filter[2][1] = (0.00);
        filter[3][1] = (0.00);
        filter[4][1] = (0.00);

        filter[0][2] = (1.00);
        filter[1][2] = (1.00);
        filter[2][2] = (1.00);
        filter[3][2] = (1.00);
        filter[4][2] = (1.00);

        x_kernel = 3;
        y_kernel = 5;
    }

    if( filter_name == "north"){
        filter = new float*[3];
        for(int x = 0 ; x < 3 ; x++){
            filter[x] = new float[3];
        }

        filter[0][0] = (1.00);
        filter[1][0] = (1.00);
        filter[2][0] = (1.00);

        filter[0][1] = (1.00);
        filter[1][1] = (-2.00);
        filter[2][1] = (1.00);

        filter[0][2] = (-1.00);
        filter[1][2] = (-1.00);
        filter[2][2] = (-1.00);

        x_kernel = 3;
        y_kernel = 3;
    }

    if( filter_name == "north_east"){
        filter = new float*[3];
        for(int x = 0 ; x < 3 ; x++){
            filter[x] = new float[3];
        }

        filter[0][0] = (1.00);
        filter[1][0] = (1.00);
        filter[2][0] = (1.00);

        filter[0][1] = (-1.00);
        filter[1][1] = (-2.00);
        filter[2][1] = (1.00);

        filter[0][2] = (-1.00);
        filter[1][2] = (-1.00);
        filter[2][2] = (1.00);

        x_kernel = 3;
        y_kernel = 3;
    }

    if( filter_name == "east"){
        filter = new float*[3];
        for(int x = 0 ; x < 3 ; x++){
            filter[x] = new float[3];
        }

        filter[0][0] = (-1.00);
        filter[1][0] = (1.00);
        filter[2][0] = (1.00);

        filter[0][1] = (-1.00);
        filter[1][1] = (-2.00);
        filter[2][1] = (1.00);

        filter[0][2] = (-1.00);
        filter[1][2] = (1.00);
        filter[2][2] = (-1.00);

        x_kernel = 3;
        y_kernel = 3;
    }

    if( filter_name == "south_east"){
        filter = new float*[3];
        for(int x = 0 ; x < 3 ; x++){
            filter[x] = new float[3];
        }

        filter[0][0] = (-1.00);
        filter[1][0] = (-1.00);
        filter[2][0] = (1.00);

        filter[0][1] = (-1.00);
        filter[1][1] = (-2.00);
        filter[2][1] = (1.00);

        filter[0][2] = (1.00);
        filter[1][2] = (1.00);
        filter[2][2] = (1.00);

        x_kernel = 3;
        y_kernel = 3;
    }

    if( filter_name == "blur"){
        filter = new float*[5];
        for(int x = 0 ; x < 5 ; x++){
            filter[x] = new float[5];
            for(int y = 0 ; y < 5 ; y++){
                filter[x][y] = 1;
            }
        }
        x_kernel = 5;
        y_kernel = 5;
    }

    if( filter_name == "south"){
        filter = new float*[3];
        for(int x = 0 ; x < 3 ; x++){
            filter[x] = new float[3];
        }

        filter[0][0] = (-1.00);
        filter[1][0] = (-1.00);
        filter[2][0] = (-1.00);

        filter[0][1] = (1.00);
        filter[1][1] = (-2.00);
        filter[2][1] = (1.00);

        filter[0][2] = (1.00);
        filter[1][2] = (1.00);
        filter[2][2] = (1.00);

        x_kernel = 3;
        y_kernel = 3;
    }

    if( filter_name == "south_west"){
        filter = new float*[3];
        for(int x = 0 ; x < 3 ; x++){
            filter[x] = new float[3];
        }

        filter[0][0] = (1.00);
        filter[1][0] = (-1.00);
        filter[2][0] = (-1.00);

        filter[0][1] = (1.00);
        filter[1][1] = (-2.00);
        filter[2][1] = (-1.00);

        filter[0][2] = (1.00);
        filter[1][2] = (1.00);
        filter[2][2] = (1.00);

        x_kernel = 3;
        y_kernel = 3;
    }

    if( filter_name == "west"){
        filter = new float*[3];
        for(int x = 0 ; x < 3 ; x++){
            filter[x] = new float[3];
        }

        filter[0][0] = (1.00);
        filter[1][0] = (1.00);
        filter[2][0] = (-1.00);

        filter[0][1] = (1.00);
        filter[1][1] = (-2.00);
        filter[2][1] = (-1.00);

        filter[0][2] = (1.00);
        filter[1][2] = (1.00);
        filter[2][2] = (-1.00);

        x_kernel = 3;
        y_kernel = 3;
    }

    if( filter_name == "north_west"){
        filter = new float*[3];
        for(int x = 0 ; x < 3 ; x++){
            filter[x] = new float[3];
        }

        filter[0][0] = (1.00);
        filter[1][0] = (1.00);
        filter[2][0] = (1.00);

        filter[0][1] = (1.00);
        filter[1][1] = (-2.00);
        filter[2][1] = (1.00);

        filter[0][2] = (-1.00);
        filter[1][2] = (-1.00);
        filter[2][2] = (-1.00);

        x_kernel = 3;
        y_kernel = 3;
    }

    if( filter_name == "LAP1"){
        filter = new float*[3];
        for(int x = 0 ; x < 3 ; x++){
            filter[x] = new float[3];
        }

        filter[0][0] = (0.00);
        filter[1][0] = (1.00);
        filter[2][0] = (0.00);

        filter[0][1] = (1.00);
        filter[1][1] = (-4.00);
        filter[2][1] = (1.00);

        filter[0][2] = (0.00);
        filter[1][2] = (1.00);
        filter[2][2] = (0.00);

        x_kernel = 3;
        y_kernel = 3;
    }

    if( filter_name == "LAP2"){
        filter = new float*[3];
        for(int x = 0 ; x < 3 ; x++){
            filter[x] = new float[3];
        }

        filter[0][0] = (-1.00);
        filter[1][0] = (-1.00);
        filter[2][0] = (-1.00);

        filter[0][1] = (-1.00);
        filter[1][1] = (8.00);
        filter[2][1] = (-1.00);

        filter[0][2] = (-1.00);
        filter[1][2] = (-1.00);
        filter[2][2] = (-1.00);

        x_kernel = 3;
        y_kernel = 3;
    }

    if( filter_name == "LAP3"){
        filter = new float*[3];
        for(int x = 0 ; x < 3 ; x++){
            filter[x] = new float[3];
        }

        filter[0][0] = (-1.00);
        filter[1][0] = (-1.00);
        filter[2][0] = (-1.00);

        filter[0][1] = (-1.00);
        filter[1][1] = (9.00);
        filter[2][1] = (-1.00);

        filter[0][2] = (-1.00);
        filter[1][2] = (-1.00);
        filter[2][2] = (-1.00);

        x_kernel = 3;
        y_kernel = 3;
    }

    if( filter_name == "LAP4"){
        filter = new float*[3];
        for(int x = 0 ; x < 3 ; x++){
            filter[x] = new float[3];
        }

        filter[0][0] = (1.00);
        filter[1][0] = (-2.00);
        filter[2][0] = (1.00);

        filter[0][1] = (-2.00);
        filter[1][1] = (4.00);
        filter[2][1] = (-2.00);

        filter[0][2] = (1.00);
        filter[1][2] = (-2.00);
        filter[2][2] = (1.00);

        x_kernel = 3;
        y_kernel = 3;
    }
    return conv(mat,filter,x_kernel,y_kernel);
}
