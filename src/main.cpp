#include <iostream>
#include <stdio.h>

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/photo/photo.hpp"
#include "opencv2/highgui/highgui.hpp"

#include "vision/CameraCapture.hpp"
#include "vision/HandExtractor.h"
#include "vision/Utility.h"
#include "vision/MovementDetector.hpp"

#include "interface/HSVTester.h"

using namespace cv;
using namespace std;

using namespace vision;
using namespace interface;

int main() {
	Ptr<CameraCapture> cam(new CameraCapture());
	cam->openCapture();

	Ptr<HSVTester> hsvTester(new HSVTester());
	Ptr<HandExtractor> handExtractor(new HandExtractor);
	Ptr<MovementDetector> mvtDetector(new MovementDetector);

	Vector<double> msFrame;
	Vector<double> msDraw;
	Vector<double> msDetect;

	char key = 'a';
	double t = 0.0;
	double t2 = 0.0;

	int nbImg = 6;
	int currentImg = 0;
	float fistScale = 1.0f;
	float fistRelativeSize = 0;
	float fistSizeMin = 60.0f;
	float fistSizeMax = 350.0f;

	Vector<float> fistSizes;

	bool passByCenter = false;

	Vector<Mat> images;
	for (int i = 1; i <= nbImg; i++) {
		stringstream filename;
		filename << "img/img" << i << ".jpg";
		images.push_back(imread(filename.str(), CV_LOAD_IMAGE_COLOR).clone());
	}

	while (key != 27) {
		t2 = (double) getTickCount();

		Mat frame = cam->takePicture();

		Mat grayFrame;
		cvtColor(frame, grayFrame, CV_RGB2GRAY);

		GaussianBlur(grayFrame, grayFrame, Size(11, 11), 1, 1);

		t = (double) getTickCount();
		mvtDetector->drawZones(frame);
		t = ((double) getTickCount() - t) / getTickFrequency();
		msDraw.push_back(t);

		t = (double) getTickCount();
		std::vector<cv::Rect> fists = mvtDetector->detectHands(grayFrame, frame);

		if (!fists.empty()) {
			if (passByCenter) {
				if (MovementDetector::zoneGauche.contains(fists[0].tl())) {
					cout << "GAUCHE" << endl;
					passByCenter = false;

					if (currentImg != 0) {
						currentImg--;
					} else {
						currentImg = nbImg - 1;
					}
				} else if (MovementDetector::zoneDroite.contains(fists[0].br())) {
					cout << "DROITE" << endl;
					passByCenter = false;

					if (currentImg != (nbImg - 1)) {
						currentImg++;
					} else {
						currentImg = 0;
					}
				} else if (MovementDetector::zoneHaut.contains(fists[0].tl())) {
					cout << "HAUT" << endl;
					passByCenter = false;

					if (fistScale < 2.6) {
						fistScale += 0.5f;
					}
				} else if (MovementDetector::zoneBas.contains(fists[0].br())) {
					cout << "BAS" << endl;
					passByCenter = false;

					if (fistScale > 0.9f) {
						fistScale -= 0.5f;
					}
				}
			} else {
				if ((MovementDetector::zoneCentre.contains(fists[0].tl()) && MovementDetector::zoneCentre.contains(fists[0].br()))) {
					cout << "CENTRE" << endl;
					passByCenter = true;
				}
			}

			if (fists[0].width >= fistSizeMin) {
				fistRelativeSize = (fists[0].width - fistSizeMin) / (fistSizeMax - fistSizeMin) * 100;
			}
		}

		t = ((double) getTickCount() - t) / getTickFrequency();
		msDetect.push_back(t);

		imshow("frame", frame);

		Mat img = images[currentImg].clone();

		Mat resizedImage;
		resize(img, resizedImage, resizedImage.size(), fistScale, fistScale, CV_INTER_LINEAR);

		Mat newIntensityImg;
		resizedImage.convertTo(newIntensityImg, -1, 1, fistRelativeSize);

		imshow("img", newIntensityImg);

		key = waitKey(1);
		t2 = ((double) getTickCount() - t2) / getTickFrequency();
		msFrame.push_back(t2);
	}

	/*
	 * Calcul du temps d'exécution
	 */
	double n = msDraw.size();

	double timeDetect = 0;
	for (unsigned int i = 0; i < n; i++) {
		timeDetect += msDetect[i];
	}
	timeDetect /= n;
	cout << "Temps moyen pour détecter les mains " << timeDetect << endl;

	double timeFrame = 0;
	for (unsigned int i = 0; i < n; i++) {
		timeFrame += msFrame[i];
	}
	timeFrame /= n;
	cout << "Temps moyen pour traiter un frame " << timeFrame << endl;

	cam->closeCapture();

	return 0;
}
