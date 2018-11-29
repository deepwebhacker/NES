//© 2018 NIREX ALL RIGHTS RESERVED

#include "NString.h"

namespace NString
{
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
		static const char* const lut = "0123456789ABCDEF";
		size_t len = in_s.length();

		std::string output;
		output.reserve(2 * len);
		for (size_t i = 0; i < len; i++)
		{
			const unsigned char c = in_s[i];
			output.push_back(lut[c >> 4]);
			output.push_back(lut[c & 15]);
		}
		return output;
	}

	std::string NormalString(const std::string& in_s)
	{
		static const char* const lut = "0123456789ABCDEF";
		size_t len = in_s.length();
		if (len & 1) throw std::invalid_argument("odd length");

		std::string output;
		output.reserve(len / 2);
		for (size_t i = 0; i + 1 < len; i += 2)
		{
			char a = in_s[i];
			const char* p = std::lower_bound(lut, lut + 16, a);
			if (*p != a) throw std::invalid_argument("not a hex digit");

			char b = in_s[i + 1];
			const char* q = std::lower_bound(lut, lut + 16, b);
			if (*q != b) throw std::invalid_argument("not a hex digit");

			output.push_back(((p - lut) << 4) | (q - lut));
		}
		return output;
	}
	std::string Replace(std::string in_s ,unsigned int index_a, unsigned int index_b)
	{
		if (index_a >= in_s.length() || index_b >= in_s.length())
		{
			return in_s;
		}
		else if (index_a == index_b)
		{
			return in_s;
		}

		char tmp = in_s[index_a];
		in_s[index_a] = in_s[index_b];
		in_s[index_b] = tmp;
		return in_s;
	}
}
