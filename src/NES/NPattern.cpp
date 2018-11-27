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
		if (p == "TA0")
		{
			intext = NES::TEXT_NESA0(intext, key);
		}
		else if (p == "TA1")
		{
			intext = NES::TEXT_NESA1(intext, key);
		}
		else if (p == "TB0")
		{
			intext = NES::TEXT_NESB0(intext, key);
		}
		else if (p == "TB1")
		{
			intext = NES::TEXT_NESB1(intext, key);
		}
		else if (p == "TC0")
		{
			intext = NES::TEXT_NESC0(intext, key);
		}
		else if (p == "TC1")
		{
			intext = NES::TEXT_NESC1(intext, key);
		}
	}
	return intext;
}

std::vector<char> NPattern::Data_Perform(std::vector<char> data, std::string key)
{
	std::vector<char> indata;
	for (auto& p : m_patterns)
	{
		//if (p == "DA0")
		//{
		//	indata = NES::DATA_NESA0(indata, key);
		//}
		//else if (p == "DA1")
		//{
		//	indata = NES::DATA_NESA1(indata, key);
		//}
		//else if (p == "DB0")
		//{
		//	indata = NES::DATA_NESB0(indata, key);
		//}
		//else if (p == "DB1")
		//{
		//	indata = NES::DATA_NESB1(indata, key);
		//}
		//else if (p == "DC0")
		//{
		//	indata = NES::DATA_NESC0(indata, key);
		//}
		//else if (p == "DC1")
		//{
		//	indata = NES::DATA_NESC1(indata, key);
		//}
	}
	return indata;
}
