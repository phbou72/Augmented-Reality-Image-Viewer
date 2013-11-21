#ifndef HANDEXTRACTOR_H_
#define HANDEXTRACTOR_H_

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "vision/Utility.h"

namespace vision {

class HandExtractor {

public:
	HandExtractor();
	virtual ~HandExtractor();
	cv::Mat extractWithHSVMethod(cv::Mat & src);
	cv::Mat extractWithRGBMethod(cv::Mat & src);
};

}

#endif
