//
//  MergeImage.hpp
//  Golden_Hour
//
//  Created by 宋題均 on 2018/3/27.
//  Copyright © 2018年 宋題均. All rights reserved.
//

#ifndef MergeImage_hpp
#define MergeImage_hpp
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace std;
using namespace cv;

Mat mergeImage(int r, int c, Mat first, Mat second);
//Mat MergeImage(int r, int c, Mat first, Mat second, Mat third);

#endif /* MergeImage_hpp */
