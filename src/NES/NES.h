//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _N_NES_H_
#define _N_NES_H_

#include "Precompiled.h"
#include <string>
#include <vector>

namespace NES
{
	std::string TEXT_NESA0(std::string text, std::string key); // TA0
	std::string TEXT_NESA1(std::string text, std::string key); // TA1
																  
	std::string TEXT_NESB0(std::string text, std::string key); // TB0
	std::string TEXT_NESB1(std::string text, std::string key); // TB1
																  
	std::string TEXT_NESC0(std::string text, std::string key); // TC0
	std::string TEXT_NESC1(std::string text, std::string key); // TC1
}

#endif // !_N_NES_H_