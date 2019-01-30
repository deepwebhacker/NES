//© 2019 NIREX ALL RIGHTS RESERVED

#include "NFile.h"

namespace NFile
{
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

	std::vector<char> ReadAllBytes(std::string fileName)
	{
		std::ifstream ifs(fileName, std::ios::binary | std::ios::ate);
		std::ifstream::pos_type pos = ifs.tellg();

		std::vector<char>  result(pos);

		ifs.seekg(0, std::ios::beg);
		ifs.read(&result[0], pos);

		return result;
	}

	int WriteAllBytes(std::string fileName, std::vector<char> vecBytes)
	{
		std::ofstream ofs(fileName, std::ios::binary | std::ios::out);
	
		ofs.write(vecBytes.data(), vecBytes.size());
		
		if (ofs.bad())    //bad() function will check for badbit
		{
			return E_UNKNOWN;
		}

		ofs.close();
		return S_OK;
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
