//
//  Img2Video.h
//  Golden_Hour
//
//  Created by 宋題均 on 2018/3/21.
//  Copyright © 2018年 宋題均. All rights reserved.
//

#ifndef Img2Video_h
#define Img2Video_h
using namespace cv;

void Img2Video(Mat s,VideoCapture t){
    Mat source = s;
    Mat target;
    VideoCapture video = t;
    VideoWriter writer;
    Size videoSize = Size((int)video.get(CV_CAP_PROP_FRAME_WIDTH),(int)video.get(CV_CAP_PROP_FRAME_HEIGHT));
    writer.open("/Users/TGsung/Desktop/I2V.mp4", CV_FOURCC('M', 'J', 'P', 'G'), 30, videoSize);
    //source processing
    cvtColor(source,source,CV_BGR2Lab);
    Mat sourcesplit[3];
    Mat sourcemean,sourcestd;
    Mat targetmean,targetstd;
    meanStdDev(source,sourcemean,sourcestd);
    
    //Video target processing
    double rstd,gstd,bstd;
    double tstd[3];
    int i,j,k,x;
    while(true){
        video >> target;
        if(target.empty()){
            break;
        }
        cvtColor(target,target,CV_BGR2Lab);
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
        cvtColor(target,target,CV_Lab2BGR);
        writer.write(target);
    }
}

void Video2Img(VideoCapture s,Mat t){
    VideoCapture video = s;
    Mat source;
    Mat target;
    Mat target_o = t;
    VideoWriter writer;
    Size videoSize = Size((int)target_o.cols,(int)target_o.rows);
    writer.open("/Users/TGsung/Desktop/V2I.avi", CV_FOURCC('M', 'J', 'P', 'G'), 30, videoSize);
    //target image processing
    cvtColor(target_o,target_o,CV_BGR2Lab);
    Mat sourcesplit[3];
    Mat sourcemean,sourcestd;
    Mat targetmean,targetstd;
    meanStdDev(target_o,targetmean,targetstd);
    
    //Video target processing
    double rstd,gstd,bstd;
    double tstd[3];
    int i,j,k,x;
    while(true){
        video >> source;
        if(source.empty()){
            break;
        }
        //target = target_o;
        cvtColor(source,source,CV_BGR2Lab);
        meanStdDev(source,sourcemean,sourcestd);
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
        cvtColor(target,target,CV_Lab2BGR);
        writer << target;
    }
}
#endif /* Img2Video_h */
