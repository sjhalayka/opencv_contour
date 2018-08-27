#include <iostream>
using namespace std;

#include <opencv2/opencv.hpp>
using namespace cv;
#pragma comment(lib, "opencv_world340.lib")


RNG rng(12345);



int main(void)
{
	Mat img = imread("star.png", CV_LOAD_IMAGE_GRAYSCALE);

	Canny(img, img, 50, 100);

	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;

	findContours(img, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

	cout << contours.size() << endl;
	
	Mat drawing = Mat::zeros(img.size(), CV_8UC3);
	
	for (int i = 0; i < 1; i++)
	{
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(drawing, contours, i, color, 1, 8, hierarchy, 0, Point());
	}

	imshow("Contours", drawing);

	waitKey(0);

	return 0;
}
