//© 2018 NIREX ALL RIGHTS RESERVED

#include "NES.h"

namespace NES
{
	std::string TEXT_NESA0(std::string text, std::string key)
	{
		std::vector<char> vec;
		for (int i = 0; i < text.length(); i++)
		{
			char l;
			for (int j = 0; j < key.length(); j++)
			{
				l = static_cast<char>(text[i] + (2 * key[j] * pow(key[j], 2) + (8 * key[j])));
			}
			vec.push_back(l);
		}
		std::string returnStr = "";
		int size = static_cast<int>(vec.size());
		for (int i = 0; i < size; i++)
		{
			returnStr += vec[i];
		}
		return returnStr;
	}
				
	std::string TEXT_NESA1(std::string text, std::string key)
	{
		std::vector<char> vec;
		for (int i = 0; i < text.length(); i++)
		{
			char l;
			for (int j = 0; j <  key.length(); j++)
			{
				l = static_cast<char>(text[i] - (2 * key[j] * pow(key[j], 2) + (8 * key[j])));
			}
			vec.push_back(l);
		}
		std::string returnStr = "";
		int size = static_cast<int>(vec.size());
		for (int i = 0; i < size; i++)
		{
			returnStr += vec[i];
		}
		return returnStr;
	}
				
	std::string TEXT_NESB0(std::string text, std::string key)
	{
		std::vector<char> vec;
		for (int i = 0; i < text.length(); i++)
		{
			char l;
			for (int j = 0; j < key.length(); j++)
			{
				l = static_cast<char>(text[i] + ((2 * key[j]) + (key[j] / 2)));
			}
			vec.push_back(l);
		}
		std::string returnStr = "";
		int size = static_cast<int>(vec.size());
		for (int i = 0; i < size; i++)
		{
			returnStr += vec[i];
		}
		return returnStr;
	}
				
	std::string TEXT_NESB1(std::string text, std::string key)
	{
		std::vector<char> vec;
		for (int i = 0; i < text.length(); i++)
		{
			char l;
			for (int j = 0; j < key.length(); j++)
			{
				l = static_cast<char>(text[i] - ((2 * key[j]) + (key[j] / 2)));
			}
			vec.push_back(l);
		}
		std::string returnStr = "";
		int size = static_cast<int>(vec.size());
		for (int i = 0; i < size; i++)
		{
			returnStr += vec[i];
		}
		return returnStr;
	}
				
	std::string TEXT_NESC0(std::string text, std::string key)
	{
		std::vector<char> vec;
		for (int i = 0; i <  text.length(); i++)
		{
			char l;
			for (int j = 0; j < key.length(); j++)
			{
				l = static_cast<char>(text[i] + (key[j]));
			}
			vec.push_back(l);
		}
		std::string returnStr = "";
		int size = static_cast<int>(vec.size());
		for (int i = 0; i < size; i++)
		{
			returnStr += vec[i];
		}
		return returnStr;
	}
				
	std::string TEXT_NESC1(std::string text, std::string key)
	{
		std::vector<char> vec;
		for (int i = 0; i < text.length(); i++)
		{
			char l;
			for (int j = 0; j < key.length(); j++)
			{
				l = static_cast<char>(text[i] - (key[j]));
			}
			vec.push_back(l);
		}
		std::string returnStr = "";
		int size = static_cast<int>(vec.size());
		for (int i = 0; i < size; i++)
		{
			returnStr += vec[i];
		}
		return returnStr;
	}

	std::vector<char> DATA_NESA0(std::vector<char> data, std::string key)
	{
		std::vector<char> vec;
		for (int i = 0; i < data.size(); i++)
		{
			char l;
			for (int j = 0; j < key.length(); j++)
			{
				l = (data[i] + (2 * key[j] * pow(key[j], 2) + (8 * key[j])));
			}
			vec.push_back(l);
		}
		return vec;
	}

	std::vector<char> DATA_NESA1(std::vector<char> data, std::string key)
	{
		std::vector<char> vec;
		for (int i = 0; i < data.size(); i++)
		{
			char l;
			for (int j = 0; j <  key.length(); j++)
			{
				l = (data[i] - (2 * key[j] * pow(key[j], 2) + (8 * key[j])));
			}
			vec.push_back(l);
		}
		return vec;
	}

	std::vector<char> DATA_NESB0(std::vector<char> data, std::string key)
	{
		std::vector<char> vec;
		for (int i = 0; i < data.size(); i++)
		{
			char l;
			for (int j = 0; j < key.length(); j++)
			{
				l = static_cast<char>(data[i] + (2 * key[j]) + (key[j] / 2));
			}
			vec.push_back(l);
		}
		return data;
	}

	std::vector<char> DATA_NESB1(std::vector<char> data, std::string key)
	{
		std::vector<char> vec;
		for (int i = 0; i <  data.size(); i++)
		{
			char l;
			for (int j = 0; j < key.length(); j++)
			{
				l = static_cast<char>(data[i] - (2 * key[j]) + (key[j] / 2));
			}
			vec.push_back(l);
		}
		return vec;
	}

	std::vector<char> DATA_NESC0(std::vector<char> data, std::string key)
	{
		std::vector<char> vec;
		for (int i = 0; i <  data.size(); i++)
		{
			char l;
			for (int j = 0; j <  key.length(); j++)
			{
				l = static_cast<char>(data[i] + (key[j]));
			}
			vec.push_back(l);
		}
		return vec;
	}

	std::vector<char> DATA_NESC1(std::vector<char> data, std::string key)
	{
		std::vector<char> vec;
		for (int i = 0; i < data.size(); i++)
		{
			char l;
			for (int j = 0; j < key.length(); j++)
			{
				l = static_cast<char>(data[i] - (key[j]));
			}
			vec.push_back(l);
		}
		return vec;
	}
}