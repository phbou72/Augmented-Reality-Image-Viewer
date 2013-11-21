#ifndef MOVEMENTDETECTOR_HPP_
#define MOVEMENTDETECTOR_HPP_

#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/objdetect/objdetect.hpp>

namespace vision {

class MovementDetector {
public:
	static cv::Rect zoneGauche;
	static cv::Rect zoneDroite;
	static cv::Rect zoneHaut;
	static cv::Rect zoneBas;
	static cv::Rect zoneCentre;


	MovementDetector();
	~MovementDetector();

	void drawZones(cv::Mat & frame);
	void detectionMovement(cv::Mat & grayFrame, cv::Mat & frame);

private:
	bool passByCenter;
	bool newPalm;
	bool alreadyPalm;

	cv::CascadeClassifier fist_cascade;
	cv::CascadeClassifier palm_cascade;

	std::vector<cv::Rect> fists;
	std::vector<cv::Rect> palms;

	void detectHands(cv::Mat & grayFrame, cv::Mat & frame);

};

}
#endif
