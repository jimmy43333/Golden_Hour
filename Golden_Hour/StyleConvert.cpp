//
//  StyleConvert.cpp
//  Golden_Hour
//
//  Created by 宋題均 on 2018/3/27.
//  Copyright © 2018年 宋題均. All rights reserved.
//

#include "StyleConvert.hpp"

Mat sourcesplit[3];
Mat sourcemean,sourcestd;
Mat targetmean,targetstd;
double rstd,gstd,bstd;
double tstd[3];

Mat Img2Img(Mat s,Mat t){
    Mat source = s.clone();
    Mat target = t.clone();
    int i,j,k,x;
    
    //calculate the mean and standard Deviation
    meanStdDev(source,sourcemean,sourcestd);
    meanStdDev(target,targetmean,targetstd);
    
    rstd = targetstd.at<double>(0,0)/sourcestd.at<double>(0,0);
    gstd = targetstd.at<double>(1,0)/sourcestd.at<double>(1,0);
    bstd = targetstd.at<double>(2,0)/sourcestd.at<double>(2,0);
    tstd[0] = rstd;
    tstd[1] = gstd;
    tstd[2] = bstd;
    for(i=0;i<target.rows;i++){
        for(j=0;j< target.cols;j++){
            for(k = 0; k < 3 ;k++){
                x = target.at<Vec3b>(i,j)[k];
                x = x - targetmean.at<double>(k,0);
                x = x * tstd[k];
                if(x + sourcemean.at<double>(k,0) > 255){
                    target.at<Vec3b>(i,j)[k] = 255;
                }else if(x + sourcemean.at<double>(k,0) < 0){
                    target.at<Vec3b>(i,j)[k] = 0;
                }else{
                    target.at<Vec3b>(i,j)[k] = x + sourcemean.at<double>(k,0);
                }
            }
        }
    }
    return target;
}

void Img2Video(Mat s,VideoCapture t){
    String videoname = "Output/I2V.avi";
    Mat source = s;
    Mat target;
    VideoCapture video = t;
    VideoWriter writer;
    Size videoSize = Size((int)video.get(CV_CAP_PROP_FRAME_WIDTH),(int)video.get(CV_CAP_PROP_FRAME_HEIGHT));
    writer.open(videoname, CV_FOURCC('M', 'J', 'P', 'G'), 30, videoSize);
    cout << "Transfer the color!!" << endl;
    while(true){
        video >> target;
        if(target.empty()){
            break;
        }
        target = Img2Img(source,target);
        writer.write(target);
    }
}

void Video2Img(VideoCapture s,Mat t){
    String videoname = "Output/V2I.avi";
    VideoCapture video = s;
    Mat source;
    Mat target = t;
    Mat output;
    VideoWriter writer;
    Size videoSize = Size((int)video.get(CV_CAP_PROP_FRAME_WIDTH),(int)video.get(CV_CAP_PROP_FRAME_HEIGHT));
    writer.open(videoname,CV_FOURCC('M', 'J', 'P', 'G'), 30, videoSize);
    //Video target processing
    cout << "Transfer the color!!" << endl;
    while(true){
        video >> source;
        if(source.empty()){
            break;
        }
        output = Img2Img(source,target);
        resize(output,output,videoSize,0,0,CV_INTER_LINEAR);
        writer.write(output);
    }
}




