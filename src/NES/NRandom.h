//© 2019 NIREX ALL RIGHTS RESERVED

#ifndef _N_RANDOM_H_
#define _N_RANDOM_H_

#include <random>

class NRandom
{
public:
	NRandom(int min, int max, int seed = 0);
	~NRandom(void);

	int GenerateRandom(void);

private:
	std::mt19937 rng;
	std::uniform_int_distribution<std::mt19937::result_type>* udist;
};

#endif // !_N_RANDOM_H_