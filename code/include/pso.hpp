#ifndef PSO_H
#define PSO_H

#include <vector>
#include "core.hpp"

class pso {
public:
	unsigned size;


	long double c1, c2;
	long double w, wMax, wMin;
	long double vMax;

	long double Gbest;

	std::vector<long double> X;
	std::vector<long double> V;
	std::vector<long double> Pbest;

	core Xcore, Pcore, Gcore;


	pso(img* image, interval *limits);
	pso(img* image, interval *limits, unsigned size);


	unsigned execute(unsigned iter);
};

#endif