#ifndef INTERVAL_C
#define INTERVAL_C

#include "interval.hpp"
#include <algorithm>

interval::interval() {

}

interval::interval(unsigned bgn, unsigned end) {
	
	if(bgn > end)
		std::swap(bgn, end);

	this->bgn = bgn;
	this->end = end;
}

unsigned interval::length() {
	return end - bgn + 1;
}

bool interval::belong(unsigned value) {
	return (value >= bgn) && (value <= end);
}

unsigned interval::convert(unsigned position) {
	position = std::max(bgn, position);
	position = std::min(end, position);
	return position - bgn;
}

interval make_interval(unsigned bgn, unsigned end) {
	interval ans(bgn,end);
	return ans;
}

#endif