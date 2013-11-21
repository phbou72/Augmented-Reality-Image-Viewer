
#include "interface/HSVTester.h"
#include "stdio.h"

using namespace cv;
using namespace std;

namespace interface {

int hue_max = 179;
int sat_max = 255;
int val_max = 255;

int hue1_slider_min = 0;
int hue1_slider_max = 30;
int sat1_slider_min = 0;
int sat1_slider_max = 255;
int val1_slider_min = 0;
int val1_slider_max = 255;

int hue2_slider_min = 135;
int hue2_slider_max = 179;
int sat2_slider_min = 0;
int sat2_slider_max = 255;
int val2_slider_min = 0;
int val2_slider_max = 255;


HSVTester::HSVTester() {

}

HSVTester::~HSVTester() {
}

void HSVTester::showInterface(Mat & src) {
	namedWindow("  Seg", 1);
	char TrackbarName[50];
	sprintf(TrackbarName, "Hue1 min x %d", hue_max);
	createTrackbar(TrackbarName, "Seg", &hue1_slider_min, hue_max);

	sprintf(TrackbarName, "Hue1 max x %d", hue_max);
	createTrackbar(TrackbarName, "Seg", &hue1_slider_max, hue_max);

	sprintf(TrackbarName, "Sat1 min x %d", sat_max);
	createTrackbar(TrackbarName, "Seg", &sat1_slider_min, sat_max);

	sprintf(TrackbarName, "Sat1 max x %d", sat_max);
	createTrackbar(TrackbarName, "Seg", &sat1_slider_max, sat_max);

	sprintf(TrackbarName, "Val1 min x %d", val_max);
	createTrackbar(TrackbarName, "Seg", &val1_slider_min, val_max);

	sprintf(TrackbarName, "Val1 max x %d", val_max);
	createTrackbar(TrackbarName, "Seg", &val1_slider_max, val_max);

	sprintf(TrackbarName, "Hue2 min x %d", hue_max);
	createTrackbar(TrackbarName, "Seg", &hue2_slider_min, hue_max);

	sprintf(TrackbarName, "Hue2 max x %d", hue_max);
	createTrackbar(TrackbarName, "Seg", &hue2_slider_max, hue_max);

	sprintf(TrackbarName, "Sat2 min x %d", sat_max);
	createTrackbar(TrackbarName, "Seg", &sat2_slider_min, sat_max);

	sprintf(TrackbarName, "Sat2 max x %d", sat_max);
	createTrackbar(TrackbarName, "Seg", &sat2_slider_max, sat_max);

	sprintf(TrackbarName, "Val2 min x %d", val_max);
	createTrackbar(TrackbarName, "Seg", &val2_slider_min, val_max);

	sprintf(TrackbarName, "Val2 max x %d", val_max);
	createTrackbar(TrackbarName, "Seg", &val2_slider_max, val_max);
}

}
