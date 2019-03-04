//© 2019 NIREX ALL RIGHTS RESERVED

#ifndef _N_HANDLER_H_
#define _N_HANDLER_H_

#include "Precompiled.h"
#include <vector>

#include "NString.h"
#include "NPattern.h"
#include "NES.h"

namespace NHandler
{
	static inline std::string Perfom(std::string text, std::string key, NPattern pattern)
	{
		std::string intext = text;
		for (auto& p : pattern.GrabPattern())
		{
			if (p == "A0")
			{
				intext = BP::EncryptA(intext, key);
			}
			else if (p == "A1")
			{
				intext = BP::DecryptA(intext, key);
			}
			else if (p == "B0")
			{
				intext = BP::EncryptB(intext, key);
			}
			else if (p == "B1")
			{
				intext = BP::DecryptB(intext, key);
			}
			else if (p == "C0")
			{
				intext = BP::EncryptC(intext, key);
			}
			else if (p == "C1")
			{
				intext = BP::DecryptC(intext, key);
			}
		}
		return intext;
	}

	static inline std::vector<BYTE> Perform(std::vector<BYTE> data, std::string key, NPattern pattern)
	{
		std::vector<BYTE> indata;
		for (auto& p : pattern.GrabPattern())
		{
			if (p == "A0")
			{
				indata = BP::EncryptA(data, key);
			}
			else if (p == "A1")
			{
				indata = BP::DecryptA(data, key);
			}
			else if (p == "B0")
			{
				indata = BP::EncryptB(data, key);
			}
			else if (p == "B1")
			{
				indata = BP::DecryptB(data, key);
			}
			else if (p == "C0")
			{
				indata = BP::EncryptC(data, key);
			}
			else if (p == "C1")
			{
				indata = BP::DecryptC(data, key);
			}
		}
		return indata;
	}
}

#endif // !_N_HANDLER_H_
