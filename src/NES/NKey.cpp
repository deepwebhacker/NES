//© 2019 NIREX ALL RIGHTS RESERVED

#include "NKey.h"
#include "NRandom.h"

namespace NKey
{
	std::string Generate(int min, int max)
	{
		NRandom nr(min, max);
		int len = nr.GenerateRandom();

		std::string retval = "";
		for (int i = 0; i < len; i++)
		{
			retval += static_cast<char>(nr.GenerateRandom());
		}
		return retval;
	}

	std::vector<std::string> GenerateKeyChain(int min, int max, int amount)
	{
		std::vector<std::string> retVec;
		for (int i = 0; i < amount; i++)
		{
			retVec.push_back(Generate(min, max));
		}
		return retVec;
	}
}