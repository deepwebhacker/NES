//© 2019 NIREX ALL RIGHTS RESERVED

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

	char* ProperizeWord(char* temp)
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

	char* SubString(char* str, int s_size, int from, int to)
	{
		if (from < 0 || to >= s_size || to < from || from >= s_size || from > to)
		{
			return nullptr;
		}

		std::string tmp = str;
		return (char*)tmp.substr(from, to - from).c_str();
	}

	wchar_t* ToUpper(wchar_t* temp)
	{
		wchar_t* retc = temp;

		int i = 0;
		while (retc[i])
		{
			retc[i] = toupper(retc[i]);
			i++;
		}
		return retc;
	}

	wchar_t* ToLower(wchar_t* temp)
	{
		wchar_t* retc = temp;

		int i = 0;
		while (retc[i])
		{
			retc[i] = tolower(retc[i]);
			i++;
		}
		return retc;
	}

	wchar_t* ProperizeWord(wchar_t* temp)
	{
		wchar_t* retc = temp;

		int i = 0;
		while (retc[i])
		{
			retc[i] = tolower(retc[i]);
			i++;
		}
		retc[0] = toupper(retc[0]);
		return retc;
	}

	wchar_t* SubString(wchar_t* str, int s_size, int from, int to)
	{
		if (from < 0 || to >= s_size || to < from || from >= s_size || from > to)
		{
			return nullptr;
		}

		std::wstring tmp = str;
		return (wchar_t*)tmp.substr(from, to - from).c_str();
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

	std::string ProperizeWord(std::string temp)
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

	std::string SubString(std::string str, int from, int to)
	{
		if (from < 0 || to >= (int)str.length() || to < from || from >= (int)str.length() || from > to)
		{
			return nullptr;
		}

		std::string tmp = str;
		return tmp.substr(from, to - from);
	}

	std::wstring ToUpper(std::wstring temp)
	{
		int i = 0;
		while (temp[i])
		{
			temp[i] = toupper(temp[i]);
			i++;
		}
		return temp;
	}

	std::wstring ToLower(std::wstring temp)
	{
		int i = 0;
		while (temp[i])
		{
			temp[i] = tolower(temp[i]);
			i++;
		}
		return temp;
	}

	std::wstring ProperizeWord(std::wstring temp)
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

	std::wstring SubString(std::wstring str, int from, int to)
	{
		if (from < 0 || to >= (int)str.length() || to < from || from >= (int)str.length() || from > to)
		{
			return nullptr;
		}

		std::wstring tmp = str;
		return tmp.substr(from, to - from);
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

	std::vector<std::wstring> Split(std::wstring in_s, const std::wstring & delim)
	{
		std::vector <std::wstring> retvec;
		size_t pos = 0;
		std::wstring token;

		while ((pos = in_s.find(delim)) != std::wstring::npos)
		{
			token = in_s.substr(0, pos);
			retvec.push_back(token);
			in_s.erase(0, pos + delim.length());
		}

		retvec.push_back(in_s);
		return retvec;
	}

	std::vector<std::string> SplitNoEmpty(std::string in_s, const std::string & delim)
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

		std::vector<std::string> propervec;
		for (const std::string& val : retvec)
		{
			if (val != "")
			{
				propervec.push_back(val);
			}
		}
		return propervec;
	}

	std::vector<std::wstring> SplitNoEmpty(std::wstring in_s, const std::wstring & delim)
	{
		std::vector <std::wstring> retvec;
		size_t pos = 0;
		std::wstring token;

		while ((pos = in_s.find(delim)) != std::wstring::npos)
		{
			token = in_s.substr(0, pos);
			retvec.push_back(token);
			in_s.erase(0, pos + delim.length());
		}

		retvec.push_back(in_s);

		std::vector<std::wstring> propervec;
		for (const std::wstring& val : retvec)
		{
			if (val != L"")
			{
				propervec.push_back(val);
			}
		}
		return propervec;
	}

	std::wstring ToWide(std::string in)
	{
		std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
		return converter.from_bytes(in);
	}

	std::string ToNarrow(std::wstring in)
	{
		std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
		return converter.to_bytes(in);
	}

	std::vector<std::string> ToVector(const std::string temp)
	{
		return SplitNoEmpty(temp, "\n");
	}

	std::string FromVector(std::vector<std::string> temp)
	{
		std::string retS;
		for (const auto& p : temp)
		{
			retS += p;
			retS += "\n";
		}
		return retS;
	}

	std::vector<std::wstring> ToVector(std::wstring temp)
	{
		return SplitNoEmpty(temp, L"\n");
	}

	std::wstring FromVector(std::vector<std::wstring> temp)
	{
		std::wstring retS;
		for (const auto& p : temp)
		{
			retS += p;
			retS += L"\n";
		}
		return retS;
	}

	std::string FullTrim(std::string temp)
	{
		return TrimBegin(TrimEnd(temp));
	}

	std::wstring FullTrim(std::wstring temp)
	{
		return TrimBegin(TrimEnd(temp));
	}

	std::string TrimBegin(std::string temp)
	{
		temp.erase(temp.begin(), std::find_if(temp.begin(), temp.end(), [](int ch) 
		{
			return !std::isspace(ch);
		}));
		return temp;
	}

	std::wstring TrimBegin(std::wstring temp)
	{
		temp.erase(temp.begin(), std::find_if(temp.begin(), temp.end(), [](int ch) 
		{
			return !std::isspace(ch);
		}));
		return temp;
	}

	std::string TrimEnd(std::string temp)
	{
		temp.erase(std::find_if(temp.rbegin(), temp.rend(), [](int ch) 
		{
			return !std::isspace(ch);
		}).base(), temp.end());
		return temp;
	}

	std::wstring TrimEnd(std::wstring temp)
	{
		temp.erase(std::find_if(temp.rbegin(), temp.rend(), [](int ch)
		{
			return !std::isspace(ch);
		}).base(), temp.end());
		return temp;
	}

	std::string Replace(std::string str, std::string original, std::string rps)
	{
		str.replace(str.find(original), original.length(), rps);
		return str;
	}

	std::wstring Replace(std::wstring wstr, std::wstring original, std::wstring rps)
	{
		wstr.replace(wstr.find(original), original.length(), rps);
		return wstr;
	}

	std::string RegexReplace(std::string str, std::string original, std::string rps)
	{
		return std::regex_replace(str, std::regex(original), rps);
	}

	std::wstring RegexReplace(std::wstring wstr, std::wstring original, std::wstring rps)
	{
		return ToWide(std::regex_replace(ToNarrow(wstr), std::regex(ToNarrow(original)), ToNarrow(rps)));
	}

	bool Validate(const std::string& str, const std::set<std::string>& set)
	{
		for (const auto& s : set)
		{
			if (s == str) return true;
		}
		return false;
	}

	bool Validate(const std::wstring& str, const std::set<std::wstring>& set)
	{
		for (const auto& s : set)
		{
			if (s == str) return true;
		}
		return false;
	}

	long Contains(const std::string& str, const::std::string& substr)
	{
		size_t index = str.find(substr);
		if (index != std::string::npos)
		{
			return index;
		}
		return -1;
	}

	long Contains(const std::wstring& str, const::std::wstring& substr)
	{
		size_t index = str.find(substr);
		if (index != std::string::npos)
		{
			return index;
		}
		return -1;
	}

	std::string ToHex(const std::string & in_s)
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

	std::string FromHex(const std::string & in_hex)
	{
		static const char* const lut = "0123456789ABCDEF";
		size_t len = in_hex.length();
		if (len & 1) throw std::invalid_argument("odd length");

		std::string output;
		output.reserve(len / 2);
		for (size_t i = 0; i + 1 < len; i += 2)
		{
			char a = in_hex[i];
			const char* p = std::lower_bound(lut, lut + 16, a);
			if (*p != a) throw std::invalid_argument("not a hex digit");

			char b = in_hex[i + 1];
			const char* q = std::lower_bound(lut, lut + 16, b);
			if (*q != b) throw std::invalid_argument("not a hex digit");

			output.push_back(((p - lut) << 4) | (q - lut));
		}
		return output;
	}

	std::string Replace(std::string in_s, unsigned int index_a, unsigned int index_b)
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
