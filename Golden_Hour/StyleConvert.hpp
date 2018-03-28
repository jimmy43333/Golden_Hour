//
//  StyleConvert.hpp
//  Golden_Hour
//
//  Created by 宋題均 on 2018/3/27.
//  Copyright © 2018年 宋題均. All rights reserved.
//

#ifndef StyleConvert_hpp
#define StyleConvert_hpp
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

extern Mat sourcesplit[3];
extern Mat sourcemean,sourcestd;
extern Mat targetmean,targetstd;
extern double rstd,gstd,bstd;
extern double tstd[3];

Mat Img2Img(Mat s,Mat t);
void Img2Video(Mat s,VideoCapture t);
void Video2Img(VideoCapture s,Mat t);




#endif /* StyleConvert_hpp */
