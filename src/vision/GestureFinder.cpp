#include "vision/GestureFinder.h"

using namespace cv;
using namespace std;

namespace vision {

GestureFinder::GestureFinder() {
	if (!palmCascade.load("xml/palm.xml")) {
		cout << "Erreur chargement fichier haar palm.xml";
	}

	if (!fistCascade.load("xml/fist.xml")) {
		cout << "Erreur chargement fichier haar palm.xml";
	}
}

GestureFinder::~GestureFinder() {
}

vector<Rect> GestureFinder::isPalmShow(Mat & src) {
	vector<Rect> hands;
	palmCascade.detectMultiScale(src, hands, 1.1, 4,
			0 | CV_HAAR_DO_ROUGH_SEARCH, Size(100, 100));

	return hands;
}

vector<Rect> GestureFinder::isFistShow(Mat & src) {
	vector<Rect> hands;
	fistCascade.detectMultiScale(src, hands, 1.1, 4,
			0 | CV_HAAR_DO_ROUGH_SEARCH, Size(100, 100));

	return hands;
}

}

