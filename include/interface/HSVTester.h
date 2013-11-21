#ifndef HSVTESTER_H_
#define HSVTESTER_H_

#include <opencv2/highgui/highgui.hpp>

namespace interface {

class HSVTester {
public:
	HSVTester();
	virtual ~HSVTester();

	void showInterface(cv::Mat & src);

};


}

#endif
