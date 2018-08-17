#ifndef CORE_H
#define CORE_H

#include "interval.hpp"
#include "img.hpp"
#include "prefixSum.hpp"

class core {
public:
	unsigned bestT;

	unsigned hMin;
	unsigned hMax;

	long double Q;
	
	interval *limits;
	img *image;

	prefixSum<unsigned long long> frequencyGrayScale;
	prefixSum<unsigned long long> pixelSum;
	prefixSum<unsigned long long> pixelSumSquared;

	prefixSum<long double> frequencyGrayScaleQ;
	prefixSum<long double> frequencyGrayScaleLog;

	core();
	core(img* image, long double Q, interval *limits);

	void redefineQ(long double q);
	long double calculateEntropy(unsigned t);
	unsigned calculateBestT();
	
	long double tMax();
	long double averageError(unsigned left, unsigned rigth);

	long double uniformityMeasure();
	long double uniformityMeasure(unsigned t);
};

#endif