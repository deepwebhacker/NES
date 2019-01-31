//© 2019 NIREX ALL RIGHTS RESERVED

#include "NRandom.h"
#include <time.h>

NRandom::NRandom(int min, int max, int seed)
{
	if (!seed) seed = time(0);

	udist = new std::uniform_int_distribution<std::mt19937::result_type>(min, max);
	std::mt19937::result_type const seedval = seed;
	rng.seed(seedval);
}

NRandom::~NRandom(void)
{
	delete udist;
}

int NRandom::GenerateRandom(void)
{
	std::mt19937::result_type random_number = (*udist)(rng);

	return random_number;
}
