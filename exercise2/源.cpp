#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	cv::Mat binaryMat;
	cv::Mat labelMat;
	cv::Mat statsMat;
	cv::Mat centrMat;
	cv::Mat srcMat = imread("D:\\4.png", 0);
	int font_face = cv::FONT_HERSHEY_COMPLEX;
	double font_scale = 1.5;
	int thickness = 1;
	int baseline;
	int elementSize = 5;
	cv::threshold(srcMat, binaryMat, 0, 255, THRESH_OTSU);
	int nComp = cv::connectedComponentsWithStats(binaryMat,
		labelMat,
		statsMat,
		centrMat,
		8,
		CV_32S);
	cout << "the total of connected Components = " << nComp - 1 << endl;

	for (int i = 1; i < nComp; i++)
	{
		char num[10];
		sprintf_s(num, "%d", i);
		Rect bndbox;
		bndbox.x = statsMat.at<int>(i, 0);
		bndbox.y = statsMat.at<int>(i, 1);
		bndbox.width = statsMat.at<int>(i, 2);
		bndbox.height = statsMat.at<int>(i, 3);
		rectangle(binaryMat, bndbox, CV_RGB(255, 255, 255), 1, 8, 0);
		cv::putText(binaryMat, num, Point(bndbox.x, bndbox.y), font_face, 1, cv::Scalar(0, 255, 255), thickness, 8, 0);
	}
	imshow("binaryMat", binaryMat);
	imshow("frame", srcMat);
	waitKey(0);
	return 0;
}