//
//  main.cpp
//  Golden_Hour
//
//  Created by 宋題均 on 2018/3/20.
//  Copyright © 2018年 宋題均. All rights reserved.
//

#include <iostream>
#include "iostream"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "vector"
#include "StyleConvert.hpp"
#include "MergeImage.hpp"
using namespace std;
using namespace cv;

string int2str(int&);

int main(int argc, const char * argv[]) {
    String Imgname;
    Mat source;
    Mat target;
    Mat output;
    VideoCapture video;
    
    /*/Image to image
    //////////////////////////////////////////////////////
    int num_G = 5;
    int num_T = 7;
    int i,j;
    for(i=1;i<=num_G;i++){
        for(j=1;j< num_T;j++){
            Imgname = "TrainData/GoldenHour/G0"+ int2str(i) + ".jpg";
            source = imread(Imgname,1);
            Imgname = "TrainData/T0" + int2str(j) + ".jpg";
            target = imread(Imgname,1);
            output = Img2Img(source, target);
            output = mergeImage(600,600,target,output);
            Imgname = "Output/G0" + int2str(i) + "_" + "T0" + int2str(j) + ".jpg";
            imwrite(Imgname, output);
        }
    }
    ////////////////////////////////////////////////////*/
    
    /*/Image to Video
    //////////////////////////////////////////////////////
    Imgname = "TrainData/02.jpg";
    video = VideoCapture("TrainData/Video/test03.mp4");
    if(!video.isOpened()){
        return -1;
    }
    source = imread(Imgname,1);
    Img2Video(source,video);
    ////////////////////////////////////////////////////*/
    
    //Video to image
    //////////////////////////////////////////////////////
    Imgname = "TrainData/T02.jpg";
    video = VideoCapture("TrainData/Video/test03.mp4");
    if(!video.isOpened()){
       return -1;
     }
    target = imread(Imgname,1);
    Video2Img(video,target);
    ////////////////////////////////////////////////////*/
    
    /*/mergeImage function test
    //////////////////////////////////////////////////////
    Mat f,s;
    f = imread("Output/G01_T04.jpg");
    s = imread("Output/G01_T05.jpg");
    Mat merge = mergeImage(300,600,f,s);
    imshow("Play",merge);
    waitKey(0);
    ////////////////////////////////////////////////////*/
    
    return 0;
}

string int2str(int &i){
    string s;
    stringstream ss(s);
    ss << i;
    return ss.str();
}
