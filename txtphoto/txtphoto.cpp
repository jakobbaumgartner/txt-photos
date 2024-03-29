// txtphoto.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include<opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
using namespace std;
using namespace cv;


//Mat odrezi(Mat izvirna);
void natisni(Mat izvirna, int visina, int sirina);
Mat dobisliko();

int main()
{
	Mat img = dobisliko();

	cout << "visina:  " << img.size().height << endl;
	cout << "sirina:  " << img.size().width << endl;

	natisni(img, img.size().height, img.size().width);



	return 0;



}



void natisni(Mat izvirna, int visina, int sirina) {

	ofstream myfile;
	myfile.open("primer.txt");
	
	

	for (int y = 0; y < visina; y++)
	{
		for (int x = 0; x < sirina; x++)
		{

			if (x % 2) {
				Scalar intensity = izvirna.at<uchar>(y, x);
				int vrednost = intensity.val[0];
				//cout << vrednost << "  ";



				if (vrednost < 100) {
					myfile << "00";
				}

				if (vrednost >= 100 && vrednost < 200) {
					myfile << "--";
				}

				if (vrednost >= 200) {
					myfile << "  ";
				}
			}


		}

		myfile << endl;


	}

	myfile.close();
}


Mat dobisliko() {

	string pot; 

	cout << "vnesite pot do slike:  ";
	cin >> pot;

	Mat img = imread(pot, 0);

	return img;
}

Mat odrezi(Mat izvirna) {
	int visina = izvirna.size().height;
	int sirina = izvirna.size().width;

	int visinakos = (visina / 10);
	int sirinakos = (sirina / 10);

	cout << visinakos * 10 << endl;
	cout << sirinakos * 10 << endl;

	Mat nova(izvirna, Rect(0, 0, sirinakos * 10, visinakos * 10));

	return nova;
}