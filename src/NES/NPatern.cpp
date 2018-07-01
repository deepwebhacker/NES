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

std::string NPatern::Perfom(std::string text, std::string key)
{
	std::string intext = text;
	for (auto& p : m_paterns)
	{
		if (p == "A0")
		{
			intext = NES::NESForward(intext, key);
		}
		else if (p == "A1")
		{
			intext = NES::NESBackward(intext, key);
		}
		else if (p == "B0")
		{
			intext = NES::NPLForward(intext, key);
		}
		else if (p == "B1")
		{
			intext = NES::NPLBackward(intext, key);
		}
		else if (p == "C0")
		{
			intext = NES::NSXForward(intext, key);
		}
		else if (p == "C1")
		{
			intext = NES::NSXBackward(intext, key);
		}
	}
}
