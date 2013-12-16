#include "vision/MovementDetector.hpp"

namespace vision {

using namespace std;
using namespace cv;

Rect MovementDetector::zoneGauche = Rect(0, 1, 100, 480);
Rect MovementDetector::zoneDroite = Rect(540, 0, 100, 480);
Rect MovementDetector::zoneHaut = Rect(100, 0, 440, 80);
Rect MovementDetector::zoneBas = Rect(100, 420, 440, 80);
Rect MovementDetector::zoneCentre = Rect(100, 80, 440, 340);

MovementDetector::MovementDetector() {
	passByCenter = false;

	String fist_cascade_name = "xml/fist.xml";
	if (!fist_cascade.load(fist_cascade_name)) {
		cout << "--(!)Error loading" << endl;
	};
}

MovementDetector::~MovementDetector() {
}

void MovementDetector::drawZones(Mat & frame) {
	rectangle(frame, zoneGauche, Scalar(0, 255, 0), 2.0);
	rectangle(frame, zoneDroite, Scalar(0, 255, 0), 2.0);
	rectangle(frame, zoneHaut, Scalar(0, 255, 0), 2.0);
	rectangle(frame, zoneBas, Scalar(0, 255, 0), 2.0);
	rectangle(frame, zoneCentre, Scalar(0, 255, 0), 2.0);
}

vector<Rect> MovementDetector::detectHands(Mat & grayFrame, Mat & frame) {
	std::vector<cv::Rect> fists;

	fist_cascade.detectMultiScale(grayFrame, fists, 1.1, 10, 0 | CV_HAAR_SCALE_IMAGE, Size(60, 60));
	for (unsigned int i = 0; i < fists.size(); i++) {
		rectangle(frame, fists[i], Scalar(0, 0, 255), 2.0);
	}

	return fists;
}

}
