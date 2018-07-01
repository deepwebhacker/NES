#ifndef _N_PATERN_H_
#define _N_PATERN_H_

#include "Precompiled.h"

class NPatern
{
public:
	bool Load(std::string path);
	std::string Perfom(std::string text, std::string key);

private:
	std::vector<std::string> m_paterns;
};

#endif // !_N_PATERN_H_