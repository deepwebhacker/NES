#ifndef _N_PATERN_H_
#define _N_PATERN_H_

#include "Precompiled.h"
#include <string>
#include <vector>

class NPatern
{
public:
	bool Load(std::string path);
	std::string Text_Perfom(std::string text, std::string key);
	std::vector<char> Data_Perform(std::vector<char> data, std::string key);

private:
	std::vector<std::string> m_paterns;
};

#endif // !_N_PATERN_H_