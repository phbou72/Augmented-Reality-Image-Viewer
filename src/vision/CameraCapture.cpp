#include "vision/CameraCapture.hpp"

using namespace cv;
using namespace std;

CameraCapture::CameraCapture() {
}

CameraCapture::~CameraCapture() {
}

Mat CameraCapture::takePicture() {
	Mat picture;
	if (videoCapture.isOpened() == false) {
		cout << "ERROR, COULD NOT TAKE A PICTURE" << endl;
		return picture;
	}

	videoCapture >> picture;

	return picture.clone();
}

void CameraCapture::openCapture() {
	videoCapture.open(0);
	setConfig(videoCapture);

	Mat picture;
	if (videoCapture.isOpened() == true) {
		for (int i = 0; i < 5; i++) { //5 images le temps que la caméra se stabilise
			videoCapture >> picture;
		}
	}
}

void CameraCapture::closeCapture() {
	videoCapture.release();
}

void CameraCapture::setConfig(cv::VideoCapture & videoCapture) {
	/*videoCapture.set(CV_CAP_PROP_BRIGHTNESS, 0.700f);
	videoCapture.set(CV_CAP_PROP_CONTRAST, 0.196078f);
	videoCapture.set(CV_CAP_PROP_SATURATION, 0.176470f);*/
}
