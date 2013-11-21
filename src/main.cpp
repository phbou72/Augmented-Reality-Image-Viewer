#include <iostream>
#include <stdio.h>

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
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

	//Extraction du fond
	//Mat fgMaskMOG2;
	//BackgroundSubtractorMOG2 pMOG2(500, 70, true);

	char key = 'a';
	while (key != 27) {
		Mat frame = cam->takePicture();
		Mat sk = frame.clone();
		GaussianBlur(sk, sk, Size(11, 11), 1, 1);

		Mat grayFrame;
		cvtColor(sk, grayFrame, CV_RGB2GRAY);
		//equalizeHist(grayFrame, grayFrame);

		//Mat extractedHand = handExtractor->extractWithHSVMethod(frame);
		//imshow("frame2", extractedHand);

		mvtDetector->drawZones(frame);
		mvtDetector->detectionMovement(grayFrame, frame);


		//pMOG2.operator()(frame, fgMaskMOG2);
		//imshow("FG Mask MOG 2", fgMaskMOG2);

		imshow("frame", frame);

		key = waitKey(1);
	}
	cam->closeCapture();

	return 0;
}
