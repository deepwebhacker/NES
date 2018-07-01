//© 2018 NIREX ALL RIGHTS RESERVED

#include "NES.h"

namespace NES
{
	std::string NESForward(std::string text, std::string key)
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

	std::string NESBackward(std::string text, std::string key)
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
	std::string NPLForward(std::string text, std::string key)
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
	std::string NPLBackward(std::string text, std::string key)
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
	std::string NSXForward(std::string text, std::string key)
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
	std::string NSXBackward(std::string text, std::string key)
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