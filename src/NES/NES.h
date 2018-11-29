//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _N_NES_H_
#define _N_NES_H_

#include "Precompiled.h"
#include <string>
#include <vector>

namespace NES
{
	std::string NESA0(std::string text, std::string key); // TA0
	std::string NESA1(std::string text, std::string key); // TA1

	std::string NESB0(std::string text, std::string key); // TB0
	std::string NESB1(std::string text, std::string key); // TB1

	std::string NESC0(std::string text, std::string key); // TC0
	std::string NESC1(std::string text, std::string key); // TC1

	std::vector<BYTE> NESA0(std::vector<BYTE> data, std::string key); // DA0
	std::vector<BYTE> NESA1(std::vector<BYTE> data, std::string key); // DA1
																	  	 
	std::vector<BYTE> NESB0(std::vector<BYTE> data, std::string key); // DB0
	std::vector<BYTE> NESB1(std::vector<BYTE> data, std::string key); // DB1
																	  	 
	std::vector<BYTE> NESC0(std::vector<BYTE> data, std::string key); // DC0
	std::vector<BYTE> NESC1(std::vector<BYTE> data, std::string key); // DC1
}

#endif // !_N_NES_H_