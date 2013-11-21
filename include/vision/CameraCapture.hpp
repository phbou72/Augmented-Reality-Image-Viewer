#ifndef CAMERACAPTURE_H_
#define CAMERACAPTURE_H_

#include <iostream>

#include <opencv2/highgui/highgui.hpp>

namespace vision {

class CameraCapture {
private:
	cv::VideoCapture videoCapture;

	void setConfig(cv::VideoCapture & videoCapture);

public:
	static float width;
	static float height;


	CameraCapture();
	~CameraCapture();

	void openCapture();
	void closeCapture();

	cv::Mat takePicture();
};

}

#endif
