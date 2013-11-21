#ifndef GESTUREFINDER_H_
#define GESTUREFINDER_H_

#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/objdetect/objdetect.hpp>

namespace vision {

class GestureFinder {
public:
	GestureFinder();
	virtual ~GestureFinder();

	std::vector<cv::Rect> isPalmShow(cv::Mat & src);
	std::vector<cv::Rect> isFistShow(cv::Mat & src);

private:
	cv::CascadeClassifier palmCascade;
	cv::CascadeClassifier fistCascade;
};

}

#endif
