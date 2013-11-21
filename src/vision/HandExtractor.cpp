#include "vision/HandExtractor.h"

namespace vision {

using namespace cv;

HandExtractor::HandExtractor() {

}

HandExtractor::~HandExtractor() {

}

Mat HandExtractor::extractWithHSVMethod(Mat & src) {
	Mat sk = src.clone();
	GaussianBlur(sk, sk, Size(5, 5), 1, 1);

	Mat cskHSV;
	cvtColor(sk, cskHSV, CV_BGR2HSV);

	Mat segmentedHand;
	inRange(cskHSV, Scalar(0, 0, 0), Scalar(20, 255, 255), segmentedHand);
	Utility::applyErode(segmentedHand, 5, CV_SHAPE_CROSS);
	Utility::applyDilate(segmentedHand, 10, CV_SHAPE_RECT);

	Mat segmentedHand2;
	inRange(cskHSV, Scalar(135, 0, 0), Scalar(170, 255, 255), segmentedHand2);
	Utility::applyErode(segmentedHand2, 5, CV_SHAPE_CROSS);
	Utility::applyDilate(segmentedHand2, 10, CV_SHAPE_RECT);

	segmentedHand += segmentedHand2;

	return segmentedHand2;
}

Mat HandExtractor::extractWithRGBMethod(Mat & src) {
	Mat tata;
	return tata;
}

}
