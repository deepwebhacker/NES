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
				intext = NES::NESA0(intext, key);
			}
			else if (p == "A1")
			{
				intext = NES::NESA1(intext, key);
			}
			else if (p == "B0")
			{
				intext = NES::NESB0(intext, key);
			}
			else if (p == "B1")
			{
				intext = NES::NESB1(intext, key);
			}
			else if (p == "C0")
			{
				intext = NES::NESC0(intext, key);
			}
			else if (p == "C1")
			{
				intext = NES::NESC1(intext, key);
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
				indata = NES::NESA0(data, key);
			}
			else if (p == "A1")
			{
				indata = NES::NESA1(data, key);
			}
			else if (p == "B0")
			{
				indata = NES::NESB0(data, key);
			}
			else if (p == "B1")
			{
				indata = NES::NESB1(data, key);
			}
			else if (p == "C0")
			{
				indata = NES::NESC0(data, key);
			}
			else if (p == "C1")
			{
				indata = NES::NESC1(data, key);
			}
		}
		return indata;
	}
}

#endif // !_N_HANDLER_H_
