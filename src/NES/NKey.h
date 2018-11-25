//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _N_KEY_H_
#define _N_KEY_H_

#include "Precompiled.h"
#include "NString.h"

#include <vector>

namespace NKey
{
	std::string Generate(int min, int max);

	std::vector<std::string> GenerateKeyChain(int min, int max, int amount);
}

#endif // !_N_KEY_H_