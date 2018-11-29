//© 2018 NIREX ALL RIGHTS RESERVED

#include "NES.h"
#include "NTime.h"
#include "NRandom.h"

namespace NES
{
	std::string NESA0(std::string text, std::string key)
	{
		std::vector<unsigned char> time = NTime::DataFromEpoch(NTime::GrabEpoch());

		 time[0] *= NRandom::GetNumber(100, 200, 1);
		 time[1] *= NRandom::GetNumber(200, 300, 2);
		 time[2] *= NRandom::GetNumber(300, 400, 3);
		 time[3] *= NRandom::GetNumber(400, 500, 4);
		
		std::vector<unsigned char> vec;
		int TimeIterator = 0;

		for (int i = 0; i < (int)time.size(); i++)
		{
			vec.push_back(time[i]);
		}

		for (int i = 0; i < (int)text.length(); i++)
		{
			char l;
			unsigned char TimeKey = time[TimeIterator];
			for (int j = 0; j < (int)key.length(); j++)
			{
				l = static_cast<unsigned char>(text[i] + (2 * key[j] * pow(key[j], 2) + TimeKey));
		
			}
			TimeIterator++;
			if (TimeIterator == time.size())
			{
				TimeIterator = 0;
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
				
	std::string NESA1(std::string text, std::string key)
	{
		std::vector<unsigned char> vec;
		std::vector<unsigned char> time;

		int TimeIterator = 0;

		time.push_back(text[0]);
		time.push_back(text[1]);
		time.push_back(text[2]);
		time.push_back(text[3]);

		for (int i = 4; i < (int)text.length(); i++)
		{
			char l;
			unsigned char TimeKey = time[TimeIterator];
			for (int j = 0; j < (int)key.length(); j++)
			{
				l = static_cast<unsigned char>(text[i] - (2 * key[j] * pow(key[j], 2) + TimeKey));
			}
			TimeIterator++;
			if (TimeIterator == time.size())
			{
				TimeIterator = 0;
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

	std::string NESB0(std::string text, std::string key)
	{
		std::vector<unsigned char> time = NTime::DataFromEpoch(NTime::GrabEpoch());

		time[0] *= NRandom::GetNumber(170, 240, 5);
		time[1] *= NRandom::GetNumber(270, 340, 6);
		time[2] *= NRandom::GetNumber(370, 440, 7);
		time[3] *= NRandom::GetNumber(470, 540, 8);

		std::vector<unsigned char> data;
		data.push_back(time[0]);
		data.push_back(time[1]);
		data.push_back(time[2]);
		data.push_back(time[3]);

		unsigned char keyX = 0;
		for (int i = 0; i < (int)key.length(); i++)
		{
			keyX += (unsigned char)key[i];
		}
		keyX += time[0] + time[1] + time[2] + time[3];

		for (int i = 0; i < (int)text.length(); i++)
		{
			unsigned long olmessage = (unsigned char)text[i] * keyX;
			unsigned long numerator = olmessage / 255;
			unsigned long remainder = olmessage % 255;

			unsigned char b1 = (numerator & 0xFF);
			unsigned char b2 = ((numerator >> 8) & 0xFF);
			unsigned char b3 = ((numerator >> 16) & 0xFF);
			unsigned char b4 = ((numerator >> 24) & 0xFF);

			data.push_back((unsigned char)remainder);
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
				
	std::string NESB1(std::string text, std::string key)
	{
		std::vector<unsigned char> data;
		unsigned char keyX = 0;
		for (int i = 0; i < (int)key.length(); i++)
		{
			keyX += (unsigned char)key[i];
		}
		keyX += text[0] + text[1] + text[2] + text[3];

		for (int i = 4; i < (int)text.length(); i += 5)
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
				
	std::string NESC0(std::string text, std::string key)
	{
		std::vector<unsigned char> time = NTime::DataFromEpoch(NTime::GrabEpoch());

		time[0] *= NRandom::GetNumber(170, 240, 5);
		time[1] *= NRandom::GetNumber(270, 340, 6);
		time[2] *= NRandom::GetNumber(370, 440, 7);
		time[3] *= NRandom::GetNumber(470, 540, 8);

		std::vector<unsigned char> data;
		data.push_back(time[0]);
		data.push_back(time[1]);
		data.push_back(time[2]);
		data.push_back(time[3]);

		unsigned char KeyX = 0;
		for (size_t i = 0; i < key.length(); i++)
		{
			KeyX += key[i];
		}
		KeyX += time[0] + time[1] + time[2] + time[3];
		KeyX /= key.length();
		float SqKeyX = sqrt(KeyX);

		for (int i = 0; i < (int)text.length(); i++)
		{
			float SqText = sqrt(text[i]);
			float mainC = (SqText + SqKeyX);
			mainC *= 1000000;
			float mainCX = sqrt(mainC);
			unsigned long long mainCNormalized = (unsigned long long)(mainCX * 1000000);

			unsigned char remainder = mainCNormalized % 255;
			unsigned long numerator = mainCNormalized / 255;

			unsigned char b1 = (numerator & 0xFF);
			unsigned char b2 = ((numerator >> 8) & 0xFF);
			unsigned char b3 = ((numerator >> 16) & 0xFF);
			unsigned char b4 = ((numerator >> 24) & 0xFF);

			data.push_back(remainder);
			data.push_back(b1);
			data.push_back(b2);
			data.push_back(b3);
			data.push_back(b4);
		}
		std::string returnStr = "";
		for (int i = 0; i < (int)data.size(); i++)
		{
			returnStr += data[i];
		}
		return returnStr;
	}
				
	std::string NESC1(std::string text, std::string key)
	{
		std::vector<unsigned char> data;
		std::vector<unsigned char> vecRem;
		std::vector<unsigned long> vecNum;

		unsigned char KeyX = 0;
		for (size_t i = 0; i < key.length(); i++)
		{
			KeyX += key[i];
		}
		KeyX += text[0] + text[1] + text[2] + text[3];
		KeyX /= key.length();
		float SqKeyX = sqrt(KeyX);

		for (size_t i = 4; i < text.length(); i += 5)
		{
			unsigned char remainder = (unsigned char)text[i];

			unsigned long numerator =
				((unsigned long)(((unsigned char)text[i + 4]) << 24)
					| (unsigned long)(((unsigned char)text[i + 3]) << 16)
					| (unsigned long)(((unsigned char)text[i + 2]) << 8)
					| (unsigned long)((unsigned char)text[i + 1]));

			vecRem.push_back(remainder);
			vecNum.push_back(numerator);
		}

		for (size_t i = 0; i < vecRem.size(); i++)
		{
			float currentOperand = ((vecNum[i] * 255) + vecRem[i]);
			unsigned long long currentOperandD = unsigned long long(currentOperand) / 1000000;
			float MixOfTextKeySqrt = currentOperandD * currentOperandD;
			MixOfTextKeySqrt = round(MixOfTextKeySqrt);
			MixOfTextKeySqrt = MixOfTextKeySqrt / 1000000;

			float SqrtOfText = MixOfTextKeySqrt - SqKeyX;
			float TextD = SqrtOfText * SqrtOfText;
			TextD = round(TextD);
			
			unsigned char TextN = (unsigned char)TextD;
			data.push_back(TextN);
		}

		std::string returnStr = "";
		for (int i = 0; i < (int)data.size(); i++)
		{
			returnStr += data[i];
		}
		return returnStr;
	}

	std::vector<BYTE> NESA0(std::vector<BYTE> data, std::string key)
	{
		std::vector<unsigned char> time = NTime::DataFromEpoch(NTime::GrabEpoch());

		time[0] *= NRandom::GetNumber(100, 200, 1);
		time[1] *= NRandom::GetNumber(200, 300, 2);
		time[2] *= NRandom::GetNumber(300, 400, 3);
		time[3] *= NRandom::GetNumber(400, 500, 4);

		std::vector<unsigned char> vec;
		int TimeIterator = 0;

		for (int i = 0; i < (int)time.size(); i++)
		{
			vec.push_back(time[i]);
		}

		for (int i = 0; i < (int)data.size(); i++)
		{
			char l;
			unsigned char TimeKey = time[TimeIterator];
			for (int j = 0; j < (int)key.length(); j++)
			{
				l = static_cast<unsigned char>(data[i] + (2 * key[j] * pow(key[j], 2) + TimeKey));

			}
			TimeIterator++;
			if (TimeIterator == time.size())
			{
				TimeIterator = 0;
			}
			vec.push_back(l);
		}
		return vec;
	}

	std::vector<BYTE> NESA1(std::vector<BYTE> data, std::string key)
	{
		std::vector<unsigned char> vec;
		std::vector<unsigned char> time;

		int TimeIterator = 0;

		time.push_back(data[0]);
		time.push_back(data[1]);
		time.push_back(data[2]);
		time.push_back(data[3]);

		for (int i = 4; i < (int)data.size(); i++)
		{
			char l;
			unsigned char TimeKey = time[TimeIterator];
			for (int j = 0; j < (int)key.length(); j++)
			{
				l = static_cast<unsigned char>(data[i] - (2 * key[j] * pow(key[j], 2) + TimeKey));
			}
			TimeIterator++;
			if (TimeIterator == time.size())
			{
				TimeIterator = 0;
			}
			vec.push_back(l);
		}
		return vec;
	}

	std::vector<BYTE> NESB0(std::vector<BYTE> data, std::string key)
	{
		std::vector<unsigned char> time = NTime::DataFromEpoch(NTime::GrabEpoch());

		time[0] *= NRandom::GetNumber(170, 240, 5);
		time[1] *= NRandom::GetNumber(270, 340, 6);
		time[2] *= NRandom::GetNumber(370, 440, 7);
		time[3] *= NRandom::GetNumber(470, 540, 8);

		std::vector<unsigned char> vec;
		vec.push_back(time[0]);
		vec.push_back(time[1]);
		vec.push_back(time[2]);
		vec.push_back(time[3]);

		unsigned char keyX = 0;
		for (int i = 0; i < (int)key.length(); i++)
		{
			keyX += (unsigned char)key[i];
		}
		keyX += time[0] + time[1] + time[2] + time[3];

		for (int i = 0; i < (int)data.size(); i++)
		{
			unsigned long olmessage = (unsigned char)data[i] * keyX;
			unsigned long numerator = olmessage / 255;
			unsigned long remainder = olmessage % 255;

			unsigned char b1 = (numerator & 0xFF);
			unsigned char b2 = ((numerator >> 8) & 0xFF);
			unsigned char b3 = ((numerator >> 16) & 0xFF);
			unsigned char b4 = ((numerator >> 24) & 0xFF);

			vec.push_back((unsigned char)remainder);
			vec.push_back((unsigned char)b1);
			vec.push_back((unsigned char)b2);
			vec.push_back((unsigned char)b3);
			vec.push_back((unsigned char)b4);
		}

		return vec;
	}

	std::vector<BYTE> NESB1(std::vector<BYTE> data, std::string key)
	{
		std::vector<unsigned char> vec;
		unsigned char keyX = 0;
		for (int i = 0; i < (int)key.length(); i++)
		{
			keyX += (unsigned char)key[i];
		}
		keyX += data[0] + data[1] + data[2] + data[3];

		for (int i = 4; i < (int)data.size(); i += 5)
		{
			unsigned long remainder = (unsigned char)data[i];
			unsigned long numerator
				= ((unsigned long)(((unsigned char)data[i + 4]) << 24)
					| (unsigned long)(((unsigned char)data[i + 3]) << 16)
					| (unsigned long)(((unsigned char)data[i + 2]) << 8)
					| (unsigned long)((unsigned char)data[i + 1]));

			unsigned long olmessage = (numerator * 255) + remainder;
			unsigned char letter = (unsigned char)(olmessage / keyX);
			vec.push_back(letter);
		}

		return vec;
	}

	std::vector<BYTE> NESC0(std::vector<BYTE> data, std::string key)
	{
		std::vector<unsigned char> time = NTime::DataFromEpoch(NTime::GrabEpoch());

		time[0] *= NRandom::GetNumber(170, 240, 5);
		time[1] *= NRandom::GetNumber(270, 340, 6);
		time[2] *= NRandom::GetNumber(370, 440, 7);
		time[3] *= NRandom::GetNumber(470, 540, 8);

		std::vector<unsigned char> vec;
		vec.push_back(time[0]);
		vec.push_back(time[1]);
		vec.push_back(time[2]);
		vec.push_back(time[3]);

		unsigned char KeyX = 0;
		for (size_t i = 0; i < key.length(); i++)
		{
			KeyX += key[i];
		}
		KeyX += time[0] + time[1] + time[2] + time[3];
		KeyX /= key.length();
		float SqKeyX = sqrt(KeyX);

		for (int i = 0; i < (int)data.size(); i++)
		{
			float SqText = sqrt(data[i]);
			float mainC = (SqText + SqKeyX);
			mainC *= 1000000;
			float mainCX = sqrt(mainC);
			unsigned long long mainCNormalized = (unsigned long long)(mainCX * 1000000);

			unsigned char remainder = mainCNormalized % 255;
			unsigned long numerator = mainCNormalized / 255;

			unsigned char b1 = (numerator & 0xFF);
			unsigned char b2 = ((numerator >> 8) & 0xFF);
			unsigned char b3 = ((numerator >> 16) & 0xFF);
			unsigned char b4 = ((numerator >> 24) & 0xFF);

			vec.push_back(remainder);
			vec.push_back(b1);
			vec.push_back(b2);
			vec.push_back(b3);
			vec.push_back(b4);
		}
		
		return vec;
	}

	std::vector<BYTE> NESC1(std::vector<BYTE> data, std::string key)
	{
		std::vector<unsigned char> vec;
		std::vector<unsigned char> vecRem;
		std::vector<unsigned long> vecNum;

		unsigned char KeyX = 0;
		for (size_t i = 0; i < key.length(); i++)
		{
			KeyX += key[i];
		}
		KeyX += data[0] + data[1] + data[2] + data[3];
		KeyX /= key.length();
		float SqKeyX = sqrt(KeyX);

		for (size_t i = 4; i < data.size(); i += 5)
		{
			unsigned char remainder = (unsigned char)data[i];

			unsigned long numerator =
				((unsigned long)(((unsigned char)data[i + 4]) << 24)
					| (unsigned long)(((unsigned char)data[i + 3]) << 16)
					| (unsigned long)(((unsigned char)data[i + 2]) << 8)
					| (unsigned long)((unsigned char)data[i + 1]));

			vecRem.push_back(remainder);
			vecNum.push_back(numerator);
		}

		for (size_t i = 0; i < vecRem.size(); i++)
		{
			float currentOperand = ((vecNum[i] * 255) + vecRem[i]);
			unsigned long long currentOperandD = unsigned long long(currentOperand) / 1000000;
			float MixOfTextKeySqrt = currentOperandD * currentOperandD;
			MixOfTextKeySqrt = round(MixOfTextKeySqrt);
			MixOfTextKeySqrt = MixOfTextKeySqrt / 1000000;

			float SqrtOfText = MixOfTextKeySqrt - SqKeyX;
			float TextD = SqrtOfText * SqrtOfText;
			TextD = round(TextD);

			unsigned char TextN = (unsigned char)TextD;
			vec.push_back(TextN);
		}

		return vec;
	}

}