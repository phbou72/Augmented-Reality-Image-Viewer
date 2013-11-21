#include "vision/Utility.h"

using namespace cv;
using namespace std;

namespace vision {

int Utility::passByCenter = 0;
int Utility::newPalm = 0;
int Utility::alreadyPalm = 0;

void Utility::applyErode(Mat & toErode, const int size, const int morphShape) {
	Point erodePoint(size, size);
	Mat erodeElem = getStructuringElement(morphShape, Size(2 * size + 1, 2 * size + 1), erodePoint);
	erode(toErode, toErode, erodeElem);
}

void Utility::applyDilate(Mat & toDilate, const int size, const int morphShape) {
	Point dilatePoint(size, size);
	Mat dilateElem = getStructuringElement(morphShape, Size(2 * size + 1, 2 * size + 1), dilatePoint);
	dilate(toDilate, toDilate, dilateElem);
}

void Utility::saveImage(Mat &pict, char* filename) {
	vector<int> compression_params;
	compression_params.push_back(100);
	//compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);

	imwrite(filename, pict, compression_params);
}

}

