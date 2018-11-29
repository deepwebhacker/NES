//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _N_NES_H_
#define _N_NES_H_

#include "Precompiled.h"
#include "NString.h"
#include <vector>

namespace BMP // Basic Math Pipelines
{
	std::string BM_A0(std::string text, std::string key); // TA0
	std::string BM_A1(std::string text, std::string key); // TA1

	std::string BM_B0(std::string text, std::string key); // TB0
	std::string BM_B1(std::string text, std::string key); // TB1

	std::string BM_C0(std::string text, std::string key); // TC0
	std::string BM_C1(std::string text, std::string key); // TC1

	std::vector<BYTE> BM_A0(std::vector<BYTE> data, std::string key); // DA0
	std::vector<BYTE> BM_A1(std::vector<BYTE> data, std::string key); // DA1
																	  	 
	std::vector<BYTE> BM_B0(std::vector<BYTE> data, std::string key); // DB0
	std::vector<BYTE> BM_B1(std::vector<BYTE> data, std::string key); // DB1
																	  	 
	std::vector<BYTE> BM_C0(std::vector<BYTE> data, std::string key); // DC0
	std::vector<BYTE> BM_C1(std::vector<BYTE> data, std::string key); // DC1
}

namespace AMP // Advanced Math Pipelines
{
}

namespace MOP // Mixing Operation Pipelines
{
	std::string MO_A0(std::string in_s);
	std::string MO_A1(std::string in_s);
}

#endif // !_N_NES_H_