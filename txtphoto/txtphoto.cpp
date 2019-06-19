// txtphoto.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include<opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

string imagefile = "sampleimage1.jpg";

int main()
{
	Mat img = imread(imagefile,0);
	cout << "visina:  " << img.size().height << endl;
	cout << "sirina:  " << img.size().width;
	Scalar intensity = img.at<uchar>(100, 0);
	// img.at vrne scalar podatkovni tip, v katerem je potrebno dostopati do barve
	cout << "prviprvi" << intensity.val[0];
	namedWindow("image", WINDOW_NORMAL);
	imshow("image", img);
	waitKey(0);
	return 0;



}





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
