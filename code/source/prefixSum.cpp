#ifndef PREFIXSUM_C
#define PREFIXSUM_C

#include <math.h>

unsigned long long psSum (unsigned long long quantity) {
	return quantity;
}

long double psLog (unsigned long long quantity) {
	return (quantity? quantity*log(quantity) : 0);
}


unsigned long long psPixel (unsigned long long quantity, unsigned intensity) {
	return quantity*intensity;
}
unsigned long long psPixelSquared (unsigned long long quantity, unsigned intensity) {
	return quantity*intensity*intensity;
}


long double psQ (unsigned long long quantity, long double Q) {
	return pow(quantity, Q);
}

#endif