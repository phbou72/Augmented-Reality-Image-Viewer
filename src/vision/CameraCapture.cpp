#include "vision/CameraCapture.hpp"

using namespace cv;
using namespace std;

namespace vision {

float CameraCapture::width = 640.0f;
float CameraCapture::height = 480.0f;

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
	videoCapture.set(CV_CAP_PROP_FRAME_HEIGHT, height);
	videoCapture.set(CV_CAP_PROP_FRAME_WIDTH, width);

	videoCapture.set(CV_CAP_PROP_BRIGHTNESS, 75.0f/250.0f);
	videoCapture.set(CV_CAP_PROP_CONTRAST, 75.0f/250.0f);
	videoCapture.set(CV_CAP_PROP_SATURATION, 25.0f/250.0f);
}

}
