//© 2018 NIREX ALL RIGHTS RESERVED

#include "NES.h"

namespace NES
{
	std::string TEXT_NESA0(std::string text, std::string key)
	{
		int textLen = text.length();
		int keyLen = key.length();
		std::vector<char> vec;
		for (int i = 0; i < textLen; i++)
		{
			char l;
			for (int j = 0; j < keyLen; j++)
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
		int textLen = text.length();
		int keyLen = key.length();
		std::vector<char> vec;
		for (int i = 0; i < textLen; i++)
		{
			char l;
			for (int j = 0; j < keyLen; j++)
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
		int textLen = text.length();
		int keyLen = key.length();
		std::vector<char> vec;
		for (int i = 0; i < textLen; i++)
		{
			char l;
			for (int j = 0; j < keyLen; j++)
			{
				l = static_cast<char>(text[i] + (2 * key[j]) + (key[j] / 2));
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
		int textLen = text.length();
		int keyLen = key.length();
		std::vector<char> vec;
		for (int i = 0; i < textLen; i++)
		{
			char l;
			for (int j = 0; j < keyLen; j++)
			{
				l = static_cast<char>(text[i] - (2 * key[j]) + (key[j] / 2));
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
		int textLen = text.length();
		int keyLen = key.length();
		std::vector<char> vec;
		for (int i = 0; i < textLen; i++)
		{
			char l;
			for (int j = 0; j < keyLen; j++)
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
		int textLen = text.length();
		int keyLen = key.length();
		std::vector<char> vec;
		for (int i = 0; i < textLen; i++)
		{
			char l;
			for (int j = 0; j < keyLen; j++)
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
}