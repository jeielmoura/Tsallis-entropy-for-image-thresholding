#ifndef IMG_C
#define IMG_C

#include "img.hpp"

img::img() : cv::Mat(), interval() {
	
}

img::img(std::string filepath) : cv::Mat( cv::imread(filepath.c_str(), CV_LOAD_IMAGE_GRAYSCALE) ) {

	frequency = std::vector<unsigned long long>(256, 0);
	
	for (int r = 0; r < this->rows; r++) {
		for (int c = 0; c < this->cols; c++) {
			unsigned value = (unsigned) this->data[ this->cols*r + c ];
			frequency[value]++;
		}
	}
}

void img::thresholdAndShow(std::vector<interval>& intervals) {
	
	const unsigned COLORS = 256;
	const unsigned INTERVALS = intervals.size() - 1;
	const unsigned STEP = (COLORS-1)/INTERVALS;

	cv::Mat tmp = (cv::Mat) *this;

	unsigned map[COLORS];

	int i = 0, j = 0;

	while (i < COLORS) {
		if( intervals[j].belong(i) )
			map[i++] = j*STEP;
		else
			j++;
	}

	for (int r = 0; r < tmp.rows; r++) {
		for (int c = 0; c < tmp.cols; c++) {
			unsigned value = (unsigned) tmp.data[ tmp.cols*r + c ];
			tmp.data[ tmp.cols*r + c ] = map[value];			
		}
	}	
	
	cv::imshow(std::to_string( intervals.size() ), tmp);
	cv::waitKey(0);
}
#endif
