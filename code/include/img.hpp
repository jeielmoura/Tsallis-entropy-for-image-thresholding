#ifndef IMG_H
#define IMG_H

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <vector>
#include <string>
#include "interval.hpp"

class img : public cv::Mat, public interval {
public:

	std::vector<unsigned long long> frequency;
	
	img();
	img(std::string filepath);

	void thresholdAndShow(std::vector<interval>& intervals);
};

#endif