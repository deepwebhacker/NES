//© 2018 NIREX ALL RIGHTS RESERVED

#include "NPattern.h"
#include "NFile.h"
#include "NString.h"
#include "NES.h"

int NPattern::Load(std::string path)
{
	pattern = NFile::ReadAllLines(path);
	return Check();
}

int NPattern::Check(void)
{
	if (pattern.size() != 0)
	{
		for (auto& p : pattern)
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

const std::vector<std::string> NPattern::GrabPattern() const
{
	return pattern;
}
