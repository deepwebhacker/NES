//© 2018 NIREX ALL RIGHTS RESERVED

#include "NES.h"

namespace NES
{
	std::string TEXT_NESA0(std::string text, std::string key)
	{
		std::vector<unsigned char> vec;
		for (int i = 0; i < text.length(); i++)
		{
			char l;
			for (int j = 0; j < key.length(); j++)
			{
				l = static_cast<unsigned char>(text[i] + (2 * key[j] * pow(key[j], 2)));
			}
			vec.push_back(l);
		}
		std::string returnStr = "";
		for (int i = 0; i < (int)vec.size(); i++)
		{
			returnStr += (char)vec[i];
		}
		return returnStr;
	}
				
	std::string TEXT_NESA1(std::string text, std::string key)
	{
		std::vector<unsigned char> vec;
		for (int i = 0; i < text.length(); i++)
		{
			char l;
			for (int j = 0; j <  key.length(); j++)
			{
				l = static_cast<unsigned char>(text[i] - (2 * key[j] * pow(key[j], 2)));
			}
			vec.push_back(l);
		}
		std::string returnStr = "";
		for (int i = 0; i < vec.size(); i++)
		{
			returnStr += (char)vec[i];
		}
		return returnStr;
	}
				
	std::string TEXT_NESB0(std::string text, std::string key)
	{
		std::vector<unsigned char> data;
		unsigned long long keyX = 0;
		for (int i = 0; i < key.length(); i++)
		{
			keyX += (unsigned char)key[i];
		}

		for (int i = 0; i < text.length(); i++)
		{
			unsigned long olmessage = (unsigned char)text[i] * keyX;
			unsigned long numerator = olmessage / 255;
			unsigned long remainder = olmessage % 255;

			unsigned char b1 = (numerator & 0xFF);
			unsigned char b2 = ((numerator >> 8) & 0xFF);
			unsigned char b3 = ((numerator >> 16) & 0xFF);
			unsigned char b4 = ((numerator >> 24) & 0xFF);

			data.push_back(remainder);
			data.push_back((unsigned char)b1);
			data.push_back((unsigned char)b2);
			data.push_back((unsigned char)b3);
			data.push_back((unsigned char)b4);
		}

		std::string returnStr = "";
		
		for (int i = 0; i < (int)data.size(); i++)
		{
			returnStr += (char)data[i];
		}
		return returnStr;
	}
				
	std::string TEXT_NESB1(std::string text, std::string key)
	{
		std::vector<unsigned char> data;
		unsigned long long keyX = 0;
		for (int i = 0; i < key.length(); i++)
		{
			keyX += (unsigned char)key[i];
		}

		while (text.length() % 5 != 0)
		{
			text += " ";
		}

		for (int i = 0; i < text.length(); i += 5)
		{
			unsigned long remainder = (unsigned char)text[i];
			unsigned long numerator
				= ((unsigned long)(((unsigned char)text[i + 4]) << 24)
					| (unsigned long)(((unsigned char)text[i + 3]) << 16)
					| (unsigned long)(((unsigned char)text[i + 2]) << 8)
					| (unsigned long)((unsigned char)text[i + 1]));


			unsigned long olmessage = (numerator * 255) + remainder;
			unsigned char letter = (unsigned char)(olmessage / keyX);
			data.push_back(letter);
		}

		std::string returnStr = "";

		for (int i = 0; i < (int)data.size(); i++)
		{
			returnStr += (char)data[i];
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
}