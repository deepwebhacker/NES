//© 2019 NIREX ALL RIGHTS RESERVED

#ifndef _N_NES_H_
#define _N_NES_H_

#include "Precompiled.h"
#include "NString.h"
#include <vector>

namespace BP // Basic Pipelines
{
	std::string EncryptA(const std::string& text, const std::string& key);
	std::string DecryptA(const std::string& text, const std::string& key);

	std::string EncryptB(const std::string& text, const std::string& key);
	std::string DecryptB(const std::string& text, const std::string& key);

	// UNSTABLE (USE HEX STRING)	
	std::string EncryptC(const std::string& text, const std::string& key);
	std::string DecryptC(const std::string& text, const std::string& key);

	std::vector<BYTE> EncryptA(const std::vector<BYTE>& data, const std::string & key);
	std::vector<BYTE> DecryptA(const std::vector<BYTE>& data, const std::string & key);

	std::vector<BYTE> EncryptB(const std::vector<BYTE>& data, const std::string & key);
	std::vector<BYTE> DecryptB(const std::vector<BYTE>& data, const std::string & key);

	// UNSTABLE (USE HEX STRING)
	std::vector<BYTE> EncryptC(const std::vector<BYTE>& data, const std::string & key);
	std::vector<BYTE> DecryptC(const std::vector<BYTE>& data, const std::string & key);
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