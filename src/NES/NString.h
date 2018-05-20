//� 2018 NIREX ALL RIGHTS RESERVED

#ifndef _N_STRING_H_
#define _N_STRING_H_

#include "Precompiled.h"
#include <string>
#include <vector>

namespace NString
{
	char* ToUpper(char* temp);
	char* ToLower(char* temp);
	char* Proper(char* temp);

	std::string ToUpper(std::string temp);
	std::string ToLower(std::string temp);
	std::string Proper(std::string temp);

	std::vector<std::string> Split(std::string in_s, const std::string& delim);
}

#endif // !_N_STRING_H_
