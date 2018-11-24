#include "NPatern.h"
#include "NFile.h"
#include "NString.h"
#include "NES.h"

bool NPatern::Load(std::string path)
{
	m_paterns = NFile::ReadAllLines(path);
	for (auto& p : m_paterns)
	{
		if (p != "A0" &&
			p != "A1" &&
			p != "B0" &&
			p != "B1" &&
			p != "C0" &&
			p != "C1")
		{
			// Bad Pattern file
			return false; 
		}
	}
	return true;
}

std::string NPatern::Text_Perfom(std::string text, std::string key)
{
	std::string intext = text;
	for (auto& p : m_paterns)
	{
		if (p == "A0")
		{
			intext = NES::TEXT_NESA0(intext, key);
		}
		else if (p == "A1")
		{
			intext = NES::TEXT_NESA1(intext, key);
		}
		else if (p == "B0")
		{
			intext = NES::TEXT_NESB0(intext, key);
		}
		else if (p == "B1")
		{
			intext = NES::TEXT_NESB1(intext, key);
		}
		else if (p == "C0")
		{
			intext = NES::TEXT_NESC0(intext, key);
		}
		else if (p == "C1")
		{
			intext = NES::TEXT_NESC1(intext, key);
		}
	}
	return intext;
}

std::vector<char> NPatern::Data_Perform(std::vector<char> data, std::string key)
{
	return std::vector<char>();
}
