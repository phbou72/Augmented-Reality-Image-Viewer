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
	char key = 'a';
	float fistSizeMin = 60.0f; // Pour le calcul de imgIntensity seulement...
	float fistSizeMax = 350.0f; // Pour le calcul de imgIntensity seulement...

	int currentImg = 0;
	float imgScale = 1.0f;
	float imgIntensity = 0.0f;
	int nbImg = 7;

	Ptr<CameraCapture> cam(new CameraCapture());
	cam->openCapture();

	Ptr<HandExtractor> handExtractor(new HandExtractor);
	Ptr<MovementDetector> mvtDetector(new MovementDetector);

	Vector<float> fistSizes;

	bool passByCenter = false;

	Vector<Mat> images;
	for (int i = 1; i <= nbImg; i++) {
		stringstream filename;
		filename << "img/img" << i << ".jpg";
		images.push_back(imread(filename.str(), CV_LOAD_IMAGE_COLOR).clone());
	}

	while (key != 27) {
		Mat frame = cam->takePicture();

		Mat grayFrame;
		cvtColor(frame, grayFrame, CV_RGB2GRAY);
		GaussianBlur(grayFrame, grayFrame, Size(11, 11), 1, 1);

		mvtDetector->drawZones(frame);

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

					if (imgScale < 2.6) {
						imgScale += 0.5f;
					}
				} else if (MovementDetector::zoneBas.contains(fists[0].br())) {
					cout << "BAS" << endl;
					passByCenter = false;

					if (imgScale > 0.9f) {
						imgScale -= 0.5f;
					}
				}
			} else {
				if ((MovementDetector::zoneCentre.contains(fists[0].tl()) && MovementDetector::zoneCentre.contains(fists[0].br()))) {
					cout << "CENTRE" << endl;
					passByCenter = true;
				}
			}

			if (fists[0].width >= fistSizeMin) {
				imgIntensity = (fists[0].width - fistSizeMin) / (fistSizeMax - fistSizeMin) * 100;
			}
		}

		key = waitKey(1);

		Mat img = images[currentImg].clone();

		Mat resizedImage;
		resize(img, resizedImage, resizedImage.size(), imgScale, imgScale, CV_INTER_LINEAR);

		Mat newIntensityImg;
		resizedImage.convertTo(newIntensityImg, -1, 1, imgIntensity);

		imshow("frame", frame);
		imshow("img", newIntensityImg);
	}

	cam->closeCapture();

	return 0;
}
