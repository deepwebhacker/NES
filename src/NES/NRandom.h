//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _N_RANDOM_H_
#define _N_RANDOM_H_

#include <random>

class NRandom
{
public:
	static inline int GetNumber(int min, int max, int seed)
	{
		std::uniform_int_distribution<std::mt19937::result_type> udist(min, max);
		std::mt19937 rng;

		std::mt19937::result_type const seedval = seed;
		rng.seed(seedval);

		std::mt19937::result_type random_number = udist(rng);

		return random_number;
	}
};

#endif // !_N_RANDOM_H_
