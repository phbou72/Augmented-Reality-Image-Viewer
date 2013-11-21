#ifndef VISIONUTILITY_H_
#define VISIONUTILITY_H_

#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"

namespace vision {

class Utility {

private:
	static int passByCenter;
	static int newPalm;
	static int alreadyPalm;

public:
	static void applyErode(cv::Mat & toErode, int size, int morphShape);
	static void applyDilate(cv::Mat & toDilate, int size, int morphShape);
	static void saveImage(cv::Mat &pict, char* filename);
	void detectionMovement(std::vector<cv::Rect> palms, std::vector<cv::Rect> fists, cv::Mat &frame);
};
}
#endif
