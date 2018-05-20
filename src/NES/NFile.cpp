//© 2018 NIREX ALL RIGHTS RESERVED

#include "NFile.h"

namespace NFile
{
	// Simple (std::string)
	std::string ReadAllText(std::string file)
	{
		std::ifstream f(file.c_str());

		std::string str = EMPTY_VAL;
		std::string outstr = EMPTY_VAL;
		int iter = 0;
		while (std::getline(f, str))
		{
			iter++;
			outstr += str;
			outstr += STR_NEWLN;
		}
		f.close();
		return outstr;
	}

	int WriteAllText(std::string file, std::string str)
	{
		std::ofstream f;
		f.open(file);
		f << str;
		f.close();
		return 0;
	}

	std::int32_t FindFirst(std::string file, std::string val)
	{
		std::ifstream f(file.c_str());

		std::string str = EMPTY_VAL;
		int iter = 0;
		while (std::getline(f, str))
		{
			if (val == str)
			{
				return iter;
			}
			iter++;
		}
		f.close();
		return -1;
	}

	// Complex (std::vector)
	std::vector<std::string> ReadAllLines(std::string file)
	{
		std::ifstream f(file.c_str());
		std::vector<std::string> retv;

		std::string str = EMPTY_VAL;
		while (std::getline(f, str))
		{
			retv.push_back(str);
		}

		f.close();
		return retv;
	}

	int WriteAllLines(std::string file, std::vector<std::string> vecstr)
	{
		std::ofstream f;
		f.open(file);

		for (size_t i = 0; i < vecstr.size(); i++)
		{
			f << vecstr[i];
			f << ENV_NEWLN;
		}

		f.close();
		return 0;
	}

	std::vector<int32_t> FindAll(std::string file, std::string val)
	{
		std::ifstream f(file.c_str());
		std::vector<int32_t> retv;

		std::string str = EMPTY_VAL;
		int iter = 0;

		while (std::getline(f, str))
		{
			if (val == str)
			{
				retv.push_back(iter);
			}
			iter++;
		}

		f.close();
		return retv;
	}

	// Misc
	bool SafeFread(void* buffer, int size, int number, FILE* fp)
	{
		using namespace std;
		int ItemsRead;
		if (feof(fp))
		{
			return false;
		}
		ItemsRead = (int)fread(buffer, size, number, fp);
		if (ItemsRead < number)
		{
			return false;
		}
		return true;
	}
}
