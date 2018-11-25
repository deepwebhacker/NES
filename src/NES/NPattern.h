//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _N_PATTERN_H_
#define _N_PATTERN_H_

#include "Precompiled.h"
#include <string>
#include <vector>

class NPattern
{
public:
	int Load(std::string path);
	int Check(void);

	std::string Text_Perfom(std::string text, std::string key);
	std::vector<char> Data_Perform(std::vector<char> data, std::string key);

private:
	std::vector<std::string> m_patterns;
};

#endif // !_N_PATERN_H_