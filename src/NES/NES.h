//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _N_NES_H_
#define _N_NES_H_

#include "Precompiled.h"
#include <string>
#include <vector>

namespace NES
{
	std::string NESEncrypt(std::string text, std::string key);
	std::string NESDecrypt(std::string text, std::string key);
}

#endif // !_N_NES_H_