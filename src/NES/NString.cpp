//� 2018 NIREX ALL RIGHTS RESERVED

#include "NString.h"

namespace NString
{
	// c_str
	char* ToUpper(char* temp)
	{
		char* retc = temp;

		int i = 0;
		while (retc[i])
		{
			retc[i] = toupper(retc[i]);
			i++;
		}
		return retc;
	}

	char* ToLower(char* temp)
	{
		char* retc = temp;

		int i = 0;
		while (retc[i])
		{
			retc[i] = tolower(retc[i]);
			i++;
		}
		return retc;
	}

	char* Proper(char* temp)
	{
		char* retc = temp;

		int i = 0;
		while (retc[i])
		{
			retc[i] = tolower(retc[i]);
			i++;
		}
		retc[0] = toupper(retc[0]);
		return retc;
	}

	// std::string
	std::string ToUpper(std::string temp)
	{
		int i = 0;
		while (temp[i])
		{
			temp[i] = toupper(temp[i]);
			i++;
		}
		return temp;
	}

	std::string ToLower(std::string temp)
	{
		int i = 0;
		while (temp[i])
		{
			temp[i] = tolower(temp[i]);
			i++;
		}
		return temp;
	}

	std::string Proper(std::string temp)
	{
		int i = 0;
		while (temp[i])
		{
			temp[i] = tolower(temp[i]);
			i++;
		}
		temp[0] = toupper(temp[0]);
		return temp;
	}

	// std::vector
	std::vector<std::string> Split(std::string in_s, const std::string& delim)
	{
		std::vector <std::string> retvec;
		size_t pos = 0;
		std::string token;

		while ((pos = in_s.find(delim)) != std::string::npos)
		{
			token = in_s.substr(0, pos);
			retvec.push_back(token);
			in_s.erase(0, pos + delim.length());
		}

		retvec.push_back(in_s);
		return retvec;
	}

	std::string HexString(const std::string& in_s)
	{
		std::stringstream stream;

		for (size_t i = 0; i < in_s.length(); i++)
		{
			stream << std::hex << (int)in_s[i];
		}

		return stream.str();
	}
}
