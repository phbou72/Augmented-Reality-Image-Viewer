#ifndef CAMERACAPTURE_H_
#define CAMERACAPTURE_H_

#include <iostream>

#include <opencv2/highgui/highgui.hpp>

class CameraCapture {
private:
	cv::VideoCapture videoCapture;

	void setConfig(cv::VideoCapture & videoCapture);

public:
	CameraCapture();
	~CameraCapture();

	void openCapture();
	void closeCapture();

	cv::Mat takePicture();
};

#endif /* CAMERACAPTURE_H_ */
