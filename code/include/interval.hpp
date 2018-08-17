#ifndef INTERVAL_H
#define INTERVAL_H

class interval {
public:
	unsigned bgn;
	unsigned end;

	interval();
	interval(unsigned bgn, unsigned end);
	
	unsigned length();
	unsigned convert(unsigned position);
	bool belong(unsigned value);
};

interval make_interval(unsigned bgn, unsigned end);

#endif