#ifndef CORE_C
#define CORE_C

#include "core.hpp"
#include <algorithm>
#include <math.h>
#include <stdlib.h>

core::core() {

}

core::core (img* image, long double Q, interval *limits) {
	this->Q = Q;
	this->limits = limits;
	this->image = image;
	
	frequencyGrayScale 		= prefixSum<unsigned long long>	(image->frequency, psSum, limits);
	pixelSum 				= prefixSum<unsigned long long>	(image->frequency, psPixel, limits);
	pixelSumSquared			= prefixSum<unsigned long long>	(image->frequency, psPixelSquared, limits);

	frequencyGrayScaleQ 	= prefixSum<long double>		(image->frequency, psQ, Q, limits);
	frequencyGrayScaleLog 	= prefixSum<long double>		(image->frequency, psLog, limits);

	hMin = limits->end + 1;
	hMax = limits->bgn - 1;

	for(unsigned i = limits->bgn; i <= limits->end; i++) {
		if (image->frequency[i]) {
			hMax = std::max(hMax, i);
			hMin = std::min(hMin, i);
		}	
	}

	bestT = calculateBestT();
}


long double core::calculateEntropy (unsigned t) {

	if( !frequencyGrayScale.getInterval(limits->bgn,t) || !frequencyGrayScale.getInterval(t+1,limits->end) )
		return 0.0;

	long double Sa, Sb;
	long double num, den;
	long double ans = 0.0;

	if(fabs(Q - 1) < 1e-9) {
		
		Sa = 0.0, Sb = 0.0;


		num = frequencyGrayScaleLog.getInterval(limits->bgn,t);
		den	= frequencyGrayScale.getInterval(limits->bgn,t);

		Sa += log( frequencyGrayScale.getInterval(limits->bgn,t) );
		Sa -= num/den;

		num	= frequencyGrayScaleLog.getInterval(t+1,limits->end);
		den	= frequencyGrayScale.getInterval(t+1,limits->end);
		
		Sb += log( frequencyGrayScale.getInterval(t+1,limits->end) );
		Sb -= num/den;


		ans += Sa;
		ans += Sb;
	}
	else {

		Sa = 1.0, Sb = 1.0;
		
		num	= frequencyGrayScaleQ.getInterval(limits->bgn,t);
		den	= pow(frequencyGrayScale.getInterval(limits->bgn,t), Q);

		
		Sa -= num/den;
		Sa /= Q - 1;

		num	= frequencyGrayScaleQ.getInterval(t+1,limits->end);
		den	= pow(frequencyGrayScale.getInterval(t+1,limits->end), Q);

		Sb -=  num/den;
		Sb /= Q - 1;

		ans += Sa;
		ans += Sb;
		ans += (1 - Q)*Sa*Sb;
	}

	return ans;
}

void core::redefineQ (long double Q) {
	if (this->Q != Q) {
		this->Q = Q;
		//std::cout << "\tmudou meu\n";
		frequencyGrayScaleQ = prefixSum<long double>(image->frequency, psQ, Q, limits);
		//std::cout << "\trecalculou meu \n";
		this->bestT = calculateBestT();
	}
}

unsigned core::calculateBestT () {
	unsigned ans = limits->end + 1;
	long double bestS = 0, currentS = 0;

	for(unsigned t = limits->bgn; t <= limits->end; t++) {

		if( !frequencyGrayScale.getInterval(limits->bgn,t) || !frequencyGrayScale.getInterval(t+1,limits->end) )
			continue;

		currentS = this->calculateEntropy(t);

		if( !limits->belong(ans) || bestS <= currentS)
			bestS = currentS, ans = t;
	}

	return ans;
}

long double core::averageError (unsigned left, unsigned rigth) {

	long double num = pixelSum.getInterval(left,rigth);
	long double den = frequencyGrayScale.getInterval(left,rigth);
	
	long double ans = pixelSumSquared.getInterval(left, rigth);
	
	num *= num;
	ans -= num/den;

	return  ans;
}

long double core::tMax () {
	long double diff = hMax - hMin;
	return (diff*diff)/2;
}

long double core::uniformityMeasure (unsigned t) {

	long double num = 	frequencyGrayScale.getInterval(limits->bgn, t)   * averageError(0, t) +
						frequencyGrayScale.getInterval(t+1, limits->end) * averageError(t+1, limits->end);
	
	long double den = 	frequencyGrayScale.getInterval(limits->bgn, limits->end) * tMax();
	
	return 1.0 - num / den;
}

long double core::uniformityMeasure () {
	return uniformityMeasure(bestT);
}

#endif