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
#include "Img2Video.h"
using namespace std;
using namespace cv;

int main(int argc, const char * argv[]) {
    Mat source = imread("/Users/TGsung/Desktop/Traindata/11.jpg",1);
    //Mat target = imread("/Users/TGsung/Desktop/00.jpg",1);
    Mat target;
    VideoCapture video = VideoCapture("/Users/TGsung/Desktop/Source.mp4");
    if(!video.isOpened()){
        return -1;
    }
    Img2Video(source,video);
    //imwrite("/Users/TGsung/Desktop/Goal.jpg",target);
    //Video2Img(video,source);
    return 0;
}
