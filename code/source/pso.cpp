#ifndef PSO_C
#define PSO_C

#include "pso.hpp"
#include <stdlib.h>

namespace {
    class Randomness {
    public:
        Randomness() {
            FILE *f = fopen("/dev/urandom", "r");
            uint32_t value;
            fread(&value, sizeof value, 1, f);
            srand(value);
        }
    };
    Randomness randomness;
}


long double random01 () {
	return ( (long double) rand() / (RAND_MAX) );
}

long double randomMinus1Plus1 () {
	return random01() * 2 - 1.0;
}

pso::pso(img* image, interval* limits) : pso::pso(image, limits, 1) {

}

pso::pso(img* image, interval* limits, unsigned size) {
	
	this->size = size;

	c1 = c2 = 2.0;

	w	 = 1.00;
	wMin = 0.40;
	wMax = 0.95;

	vMax = 1.15;

	Xcore = core(image, 0.0, limits);
	Pcore = core(image, 0.0, limits);
	Gcore = core(image, 0.0, limits);

	X 		= std::vector<long double>(this->size);
	V 		= std::vector<long double>(this->size);
	Pbest 	= std::vector<long double>(this->size);
	

	for(unsigned i = 0; i < this->size; i++) {
		Pbest[i] = X[i] = random01();
		V[i] = randomMinus1Plus1() * vMax;
	}


	for(unsigned i = 0; i < this->size; i++) {
		Pcore.redefineQ(Pbest[i]);
		if (!i || Gcore.uniformityMeasure() < Pcore.uniformityMeasure() ) {
			Gbest = Pbest[i];
			Gcore.redefineQ(Pbest[i]);
		}
	}
}

unsigned pso::execute(unsigned iter) {
	/*
	std::cout << "X = " << X.vec[0] << std::endl;
	std::cout << "V = " << V.vec[0] << std::endl;
	*/

	for(unsigned t = 1; t <= iter; t++) {

		w = wMax - ( (wMax - wMin)*t ) / iter;

		for(unsigned i = 0; i < size; i++) {
			V[i] = w*V[i] + c1*random01()*(X[i] - Pbest[i]) + c2*random01()*(X[i] - Gbest);

	
			V[i] = std::min(V[i], vMax); 
			V[i] = std::max(V[i], -vMax);

			X[i] = X[i] - V[i];
			
			/*
			std::cout << "X = " << X.vec[0] << std::endl;
			std::cout << "V = " << V.vec[0] << std::endl;
			*/

			X[i] = fabs(X[i]);

			if(X[i] == 0)
				continue;

			Xcore.redefineQ(X[i]);
			Pcore.redefineQ(Pbest[i]);


			if ( Xcore.uniformityMeasure() > Pcore.uniformityMeasure() ) {
				Pbest[i] = X[i], Pcore.redefineQ(X[i]);
				//std::cout << "Pbest = " << Pbest.vec[i] << std::endl;
			}

			if( Gcore.uniformityMeasure() < Xcore.uniformityMeasure() ) {
				Gbest = X[i], Gcore.redefineQ(X[i]);
				//std::cout << "Gbest = " << Gbest << std::endl;
			}
		}

		//std::cout << std::endl;
	}

	return Gcore.bestT;
}

#endif