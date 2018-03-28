//
//  MergeImage.cpp
//  Golden_Hour
//
//  Created by 宋題均 on 2018/3/27.
//  Copyright © 2018年 宋題均. All rights reserved.
//

#include "MergeImage.hpp"

// the value of r and c must be even
// the size of two image must be same direction(same height > width or same width > height)

Mat mergeImage(int r, int c, Mat f, Mat s){
    Mat output(r,c,CV_8UC3);
    Mat first = f;
    Mat second = s;
    int orows,ocols,i,j;
    if(first.rows > first.cols && second.rows > second.cols){
        //two picture is vertical
        orows = r;
        ocols = c/2;
        resize(first,first,Size(ocols,orows),0,0,CV_INTER_LINEAR);
        resize(second,second,Size(ocols,orows),0,0,CV_INTER_LINEAR);
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                if(j < ocols){
                    output.at<Vec3b>(i,j) = first.at<Vec3b>(i,j);
                }else{
                    output.at<Vec3b>(i,j) = second.at<Vec3b>(i,j-ocols);
                }
            }
        }
    }else if(first.rows < first.cols && second.rows < second.cols){
        //two picture is horizen
        orows = r/2;
        ocols = c;
        resize(first,first,Size(ocols,orows),0,0,CV_INTER_LINEAR);
        resize(second,second,Size(ocols,orows),0,0,CV_INTER_LINEAR);
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                if(i < orows){
                    output.at<Vec3b>(i,j) = first.at<Vec3b>(i,j);
                }else{
                    output.at<Vec3b>(i,j) = second.at<Vec3b>(i-orows,j);
                }
                
            }
        }
    }else{
        return output;
    }
    return output;
}

//Mat MergeImage(int r, int c, Mat first, Mat second, Mat third){
    
//}
