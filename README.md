Golden Hour 
====
## Introduction
This is the project to do the color style transfer. We want to transfer the color style of golden hour to other picture that is not at golden hour.

## How to transfer the color
We take two pictures as source and target.  
Calculate the **mean** and **standard deviation** of source and target, and calculate the value **target's sd / source's sd** of each channel.
1. For each channel in target, every pixel minus the target sd.
2. And then multiple the target's sd / source's sd.
3. Last add the source sd, and control than in the range of 0 to 255.

## Function
1. Images to Images
2. Image to Video
3. Video to Image
4. Marge function to let two pictures together
## Comment
1. When pass the **Mat** as value by function, it refer to the same object.
2. Learn how to seperate the header file.