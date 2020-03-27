#include <iostream>
#include <opencv.hpp>
#include <stdlib.h>
using namespace cv;
using namespace std;
int main()
{
	VideoCapture cap;
	cap.open(0);
	if (!cap.isOpened())
	{
		std::cout << "���ܴ���Ƶ�ļ�" << std::endl;
		return -1;
	}
	double fps = cap.get(CAP_PROP_FPS);
	std::cout << "fps" << fps << std::endl;
	while (1)
	{
		cv::Mat frame;
		cv::Mat dst;
		bool rSucess = cap.read(frame);
		if (!rSucess)
		{
			std::cout << "���ܴ���Ƶ�ļ��ж�ȡ֡" << std::endl;
			break;
		}
		else
		{
			cv::blur(frame, dst, Size(3,3));
			cv::imshow("dst", dst);

		}

	}
	waitKey(30);
	return 0;

}