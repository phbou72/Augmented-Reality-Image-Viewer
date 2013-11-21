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
	newPalm = false;
	alreadyPalm = false;

	String fist_cascade_name = "xml/fist.xml";

	if (!fist_cascade.load(fist_cascade_name)) {
		cout << "--(!)Error loading" << endl;
	};

	String palm_cascade_name = "xml/palm.xml";
	if (!palm_cascade.load(palm_cascade_name)) {
		cout << "--(!)Error loading\n" << endl;
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

void MovementDetector::detectHands(Mat & grayFrame, Mat & frame) {
	fist_cascade.detectMultiScale(grayFrame, fists, 1.1, 10, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));

	for (unsigned int i = 0; i < fists.size(); i++) {
		rectangle(frame, fists[i], Scalar(0, 0, 255), 2.0);
		cout << "Poing détecté!!! " << endl;
	}

	palm_cascade.detectMultiScale(grayFrame, palms, 1.1, 10, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));

	for (unsigned int i = 0; i < palms.size(); i++) {
		rectangle(frame, palms[i], Scalar(0, 0, 255), 2.0);
		cout << "Main ouverte  détecté!!! " << endl;
	}
}

void MovementDetector::detectionMovement(Mat &grayFrame, Mat &frame) {
	detectHands(grayFrame, frame);

	if (!fists.empty()) {
		if (zoneGauche.contains(fists[0].tl()) && passByCenter) {
			cout << "GAUCHE" << endl;

			alreadyPalm = false;
			passByCenter = false;
		}

		if (zoneDroite.contains(fists[0].br()) && passByCenter) {
			cout << "DROITE" << endl;

			alreadyPalm = false;
			passByCenter = false;
		}

		if (zoneHaut.contains(fists[0].tl()) && passByCenter) {
			cout << "HAUT" << endl;

			alreadyPalm = false;
			passByCenter = false;
		}

		if (zoneBas.contains(fists[0].br()) && passByCenter) {
			cout << "BAS" << endl;

			alreadyPalm = false;
			passByCenter = false;
		}

		if ((zoneCentre.contains(fists[0].tl()) && zoneCentre.contains(fists[0].br())) && passByCenter == false) {
			cout << "CENTRE" << endl;

			passByCenter = true;
		}

		newPalm = 1;
	}

	if (!palms.empty()) {
		if (newPalm) {
			if (alreadyPalm) {
				cout << "PALM 2" << endl;
				alreadyPalm = false;
			} else {
				cout << "PALM 1" << endl;
				alreadyPalm = true;
			}
			newPalm = 0;
		}
	}
}

}
