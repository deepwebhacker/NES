//© 2018 NIREX ALL RIGHTS RESERVED

#include "NPattern.h"
#include "NFile.h"
#include "NString.h"
#include "NES.h"

int NPattern::Load(std::string path)
{
	m_patterns = NFile::ReadAllLines(path);
	return Check();
}

int NPattern::Check(void)
{
	if (m_patterns.size() != 0)
	{
		for (auto& p : m_patterns)
		{
			if (p != "A0" &&
				p != "A1" &&
				p != "B0" &&
				p != "B1" &&
				p != "C0" &&
				p != "C1")
			{
				return E_ERR;
			}
		}
		return S_OK;
	}
	return E_ERR;
}

std::string NPattern::Text_Perfom(std::string text, std::string key)
{
	std::string intext = text;
	for (auto& p : m_patterns)
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

std::vector<BYTE> NPattern::Data_Perform(std::vector<BYTE> data, std::string key)
{
	std::vector<BYTE> indata;
	for (auto& p : m_patterns)
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
