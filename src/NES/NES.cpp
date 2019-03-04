//© 2019 NIREX ALL RIGHTS RESERVED

#include "NES.h"
#include "NTime.h"
#include "NRandom.h"

namespace BMP
{
	std::string BM_A0(std::string text, std::string key)
	{
		std::vector<unsigned char> time = NTime::DataFromEpoch(NTime::GrabEpoch());

		NRandom nr(100, 200);
		time[0] += nr.GenerateRandom();
		time[1] += nr.GenerateRandom();
		time[2] += nr.GenerateRandom();
		time[3] += nr.GenerateRandom();
	
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
				
	std::string BM_A1(std::string text, std::string key)
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

	std::string BM_B0(std::string text, std::string key)
	{
		std::vector<unsigned char> time = NTime::DataFromEpoch(NTime::GrabEpoch());

		NRandom nr(100, 200);
		time[0] += nr.GenerateRandom();
		time[1] += nr.GenerateRandom();
		time[2] += nr.GenerateRandom();
		time[3] += nr.GenerateRandom();

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

		keyX = data[0] + data[1] + data[2] + data[3];

		if (keyX == 0)
		{
			keyX += 2;
		}

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
				
	std::string BM_B1(std::string text, std::string key)
	{
		std::vector<unsigned char> data;
		unsigned char keyX = 0;
		for (int i = 0; i < (int)key.length(); i++)
		{
			keyX += (unsigned char)key[i];
		}

		keyX = text[0] + text[1] + text[2] + text[3];

		if (keyX == 0)
		{
			keyX += 2;
		}

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
				
	// UNSTABLE
	std::string BM_C0(std::string text, std::string key)
	{
		std::vector<unsigned char> time = NTime::DataFromEpoch(NTime::GrabEpoch());

		NRandom nr(100, 200);
		time[0] += nr.GenerateRandom();
		time[1] += nr.GenerateRandom();
		time[2] += nr.GenerateRandom();
		time[3] += nr.GenerateRandom();

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
				
	std::string BM_C1(std::string text, std::string key)
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

	std::vector<BYTE> BM_A0(std::vector<BYTE> inData, std::string key)
	{
		std::vector<unsigned char> time = NTime::DataFromEpoch(NTime::GrabEpoch());

		NRandom nr(100, 200);
		time[0] += nr.GenerateRandom();
		time[1] += nr.GenerateRandom();
		time[2] += nr.GenerateRandom();
		time[3] += nr.GenerateRandom();

		std::vector<unsigned char> vec;
		int TimeIterator = 0;

		for (int i = 0; i < (int)time.size(); i++)
		{
			vec.push_back(time[i]);
		}

		for (int i = 0; i < (int)inData.size(); i++)
		{
			char l;
			unsigned char TimeKey = time[TimeIterator];
			for (int j = 0; j < (int)key.length(); j++)
			{
				l = static_cast<unsigned char>(inData[i] + (2 * key[j] * pow(key[j], 2) + TimeKey));

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

	std::vector<BYTE> BM_A1(std::vector<BYTE> inData, std::string key)
	{
		std::vector<unsigned char> vec;
		std::vector<unsigned char> time;

		int TimeIterator = 0;

		time.push_back(inData[0]);
		time.push_back(inData[1]);
		time.push_back(inData[2]);
		time.push_back(inData[3]);

		for (int i = 4; i < (int)inData.size(); i++)
		{
			char l;
			unsigned char TimeKey = time[TimeIterator];
			for (int j = 0; j < (int)key.length(); j++)
			{
				l = static_cast<unsigned char>(inData[i] - (2 * key[j] * pow(key[j], 2) + TimeKey));
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

	std::vector<BYTE> BM_B0(std::vector<BYTE> inData, std::string key)
	{
		std::vector<unsigned char> time = NTime::DataFromEpoch(NTime::GrabEpoch());

		NRandom nr(100, 200);
		time[0] += nr.GenerateRandom();
		time[1] += nr.GenerateRandom();
		time[2] += nr.GenerateRandom();
		time[3] += nr.GenerateRandom();

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

		keyX = data[0] + data[1] + data[2] + data[3];

		if (keyX == 0)
		{
			keyX += 2;
		}

		for (int i = 0; i < (int)inData.size(); i++)
		{
			unsigned long olmessage = (unsigned char)inData[i] * keyX;
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

		return data;
	}
  
	std::vector<BYTE> BM_B1(std::vector<BYTE> inData, std::string key)
	{
		std::vector<unsigned char> data;
		unsigned char keyX = 0;
		for (int i = 0; i < (int)key.length(); i++)
		{
			keyX += (unsigned char)key[i];
		}

		keyX = inData[0] + inData[1] + inData[2] + inData[3];

		if (keyX == 0)
		{
			keyX += 2;
		}

		for (int i = 4; i < (int)inData.size(); i += 5)
		{
			unsigned long remainder = (unsigned char)inData[i];
			unsigned long numerator
				= ((unsigned long)(((unsigned char)inData[i + 4]) << 24)
					| (unsigned long)(((unsigned char)inData[i + 3]) << 16)
					| (unsigned long)(((unsigned char)inData[i + 2]) << 8)
					| (unsigned long)((unsigned char)inData[i + 1]));


			unsigned long olmessage = (numerator * 255) + remainder;
			unsigned char letter = (unsigned char)(olmessage / keyX);
			data.push_back(letter);
		}

		return data;
	}
	
	// UNSTABLE
	std::vector<BYTE> BM_C0(std::vector<BYTE> inData, std::string key)
	{
		std::vector<unsigned char> time = NTime::DataFromEpoch(NTime::GrabEpoch());

		NRandom nr(100, 200);
		time[0] += nr.GenerateRandom();
		time[1] += nr.GenerateRandom();
		time[2] += nr.GenerateRandom();
		time[3] += nr.GenerateRandom();

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

		for (int i = 0; i < (int)inData.size(); i++)
		{
			float SqText = sqrt(inData[i]);
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

		return data;
	}
  
	std::vector<BYTE> BM_C1(std::vector<BYTE> inData, std::string key)
	{
		std::vector<unsigned char> data;
		std::vector<unsigned char> vecRem;
		std::vector<unsigned long> vecNum;

		unsigned char KeyX = 0;
		for (size_t i = 0; i < key.length(); i++)
		{
			KeyX += key[i];
		}
		KeyX += inData[0] + inData[1] + inData[2] + inData[3];
		KeyX /= key.length();
		float SqKeyX = sqrt(KeyX);

		for (size_t i = 4; i < inData.size(); i += 5)
		{
			unsigned char remainder = (unsigned char)inData[i];

			unsigned long numerator =
				((unsigned long)(((unsigned char)inData[i + 4]) << 24)
					| (unsigned long)(((unsigned char)inData[i + 3]) << 16)
					| (unsigned long)(((unsigned char)inData[i + 2]) << 8)
					| (unsigned long)((unsigned char)inData[i + 1]));

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

		return data;
	}
}

std::string MOP::MO_A0(std::string in_s)
{
	int perc = (int)(double)((in_s.length() * 80) / 100);
	for (size_t i = 0; i < perc - 1; i++)
	{
		in_s = NString::Replace(in_s, i, i + 1);
	}
	return in_s;
}

std::string MOP::MO_A1(std::string in_s)
{
	in_s = MO_A0(in_s);
	in_s = MO_A0(in_s);
	in_s = MO_A0(in_s);
	in_s = MO_A0(in_s);
	in_s = MO_A0(in_s);
	return in_s;
}