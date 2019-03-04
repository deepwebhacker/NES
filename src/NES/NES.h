//© 2019 NIREX ALL RIGHTS RESERVED

#ifndef _N_NES_H_
#define _N_NES_H_

#include "Precompiled.h"
#include "NString.h"
#include <vector>

namespace BP // Basic Pipelines
{
	std::string EncryptA(std::string text, std::string key);
	std::string DecryptA(std::string text, std::string key);

	std::string EncryptB(std::string text, std::string key);
	std::string DecryptB(std::string text, std::string key);

	std::string EncryptC(std::string text, std::string key);
	std::string DecryptC(std::string text, std::string key);

	std::vector<BYTE> EncryptA(const std::vector<BYTE> &data, std::string key);
	std::vector<BYTE> DecryptA(std::vector<BYTE> data, std::string key);
																	  	
	std::vector<BYTE> EncryptB(std::vector<BYTE> data, std::string key);
	std::vector<BYTE> DecryptB(std::vector<BYTE> data, std::string key);
																	  	
	std::vector<BYTE> EncryptC(std::vector<BYTE> data, std::string key);
	std::vector<BYTE> DecryptC(std::vector<BYTE> data, std::string key);
}

namespace AP // Advanced Pipelines
{
}

namespace MP // Mixing Pipelines
{
	std::string MixA(std::string in_s);
	std::string MegaMixA(std::string in_s);
}

#endif // !_N_NES_H_