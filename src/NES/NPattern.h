//© 2019 NIREX ALL RIGHTS RESERVED

#ifndef _N_PATTERN_H_
#define _N_PATTERN_H_

#include "Precompiled.h"
#include "NString.h"

#include <vector>

class NPattern
{
public:
	int Load(std::string path);
	int Check(void);

	const std::vector<std::string> GrabPattern() const;

private:
	std::vector<std::string> pattern;
};

#endif // !_N_PATERN_H_