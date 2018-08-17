#ifndef PREFIXSUM_H
#define PREFIXSUM_H

#include "interval.hpp"

#include <vector>
#include <algorithm>
#include <iostream>

template<class T>
class prefixSum : public std::vector<T> {
public:

	interval *limits;

    prefixSum() : std::vector<T>() {

    }

 	prefixSum (	std::vector<unsigned long long>& in,
 				T store(unsigned long long quantity),
 				interval *limits						) : std::vector<T>( limits->length() ) {

 		this->limits = limits;

 		if( limits->end < in.size() ) {
			this->operator[](0) = store(in[limits->bgn]);

			for(unsigned i = 1; i < limits->length(); i++)
				this->operator[](i) = this->operator[](i-1) + store(in[limits->bgn + i]);
		}
 	}

 	prefixSum (	std::vector<unsigned long long>& in,
 				T store(unsigned long long quantity, unsigned intensity),
 				interval *limits											) : std::vector<T>( limits->length() ) {

 		this->limits = limits;

 		if( limits->end < in.size() ) {
			this->operator[](0) = store(in[limits->bgn], limits->bgn);

			for(unsigned i = 1; i < limits->length(); i++)
				this->operator[](i) = this->operator[](i-1) + store(in[limits->bgn + i], limits->bgn + i);
		}
 	}

 	prefixSum (	std::vector<unsigned long long>& in,
 				T store(unsigned long long quantity, long double Q),
 				long double Q,
 				interval *limits										) : std::vector<T>( limits->length() ) {

 		this->limits = limits;

 		if( limits->end < in.size() ) {
			this->operator[](0) = store(in[limits->bgn], Q);

			for(unsigned i = 1; i < limits->length(); i++)
				this->operator[](i) = this->operator[](i-1) + store(in[limits->bgn + i], Q);
		}
 	}

	T getInterval(unsigned left, unsigned rigth) {
		left  = limits->convert(left);
		rigth = limits->convert(rigth);

		if(rigth < left)	std::swap(left, rigth);

		T ans = this->operator[](rigth) - ( left ? this->operator[](left-1) : 0 );

		return ans;
	}
};

unsigned long long psSum (unsigned long long quantity);

long double psLog (unsigned long long quantity);


unsigned long long psPixel (unsigned long long quantity, unsigned intensity);
unsigned long long psPixelSquared (unsigned long long quantity, unsigned intensity);


long double psQ (unsigned long long quantity, long double Q);
#endif