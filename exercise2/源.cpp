#include <iostream>
#include <opencv.hpp>
#include <stdlib.h>
using namespace cv;
int main() {
	cv::Mat srcMat = imread("D:\\1.jpg");
	Mat src;
	cvtColor(srcMat, src, COLOR_BGR2GRAY);
	Mat result1 = Mat::zeros(Size(256, 256), CV_8UC3);
	threshold(src, result1, 100, 255, THRESH_BINARY);
	imshow("【二值化图1】", result1);
	Mat result2 = Mat::zeros(Size(256, 256), CV_8UC3);
	adaptiveThreshold(src, result2, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 15, 10);
	imshow("【二值化图2】", result2);
	waitKey(0);
	return 0;
}

