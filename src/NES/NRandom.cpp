//© 2018 NIREX ALL RIGHTS RESERVED

#include "NRandom.h"
#include <random>
#include <time.h> 

int NRandom::GetNumber(int min, int max)
{
	time_t timer;
	struct tm y2k = { 0 };
	double val;

	y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
	y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;

	time(&timer);
	val = difftime(timer, mktime(&y2k));

	std::uniform_int_distribution<std::mt19937::result_type> udist(min, max);
	std::mt19937 rng;

	std::mt19937::result_type const seedval = val;
	rng.seed(seedval);

	std::mt19937::result_type random_number = udist(rng);

	return random_number;
}
