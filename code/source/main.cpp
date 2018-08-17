#include "img.hpp"
#include "pso.hpp"
#include <vector>

#define SIZE 10
#define ITER 30

#define DIVI 2

std::vector<interval> segmentation (img* image, interval *limits, unsigned size, unsigned iter) {
	std::cout << "[" << limits->bgn << " , " << limits->end << "]" << std::endl;

	pso generate(image, limits, size);
	unsigned T = generate.execute(iter);

	std::vector<interval> ans;
	ans.push_back( make_interval(limits->bgn, T) );
	ans.push_back( make_interval(T+1, limits->end) );
	return ans;
}

int main(int argc, char *argv[]) {
	std::string filepath(argv[1]);

	img image(filepath);

	std::vector<interval>intervals;
	intervals.push_back( make_interval(0,255) );

	for (unsigned d = 0; d < DIVI; d++) {
		std::vector<interval> aux;
		for (unsigned i = 0; i < intervals.size(); i++) {
			std::vector<interval> seg = segmentation(&image, &intervals[i], SIZE, ITER);
			aux.push_back(seg[0]);
			aux.push_back(seg[1]);
		}
		intervals = aux;
	}
	
	image.thresholdAndShow(intervals); 

	return 0;
}