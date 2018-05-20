//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _N_FILE_H_
#define _N_FILE_H_

#include "Precompiled.h"
#include <string>
#include <fstream>
#include <vector>
#include <iostream>

namespace NFile
{
	std::string ReadAllText(std::string file);
	int WriteAllText(std::string file, std::string str);
	std::int32_t FindFirst(std::string file, std::string val);
	
	std::vector<std::string> ReadAllLines(std::string file);
	int WriteAllLines(std::string file, std::vector<std::string> vecstr);
	std::vector<int32_t> FindAll(std::string file, std::string val);
	
	bool SafeFread(void* buffer, int size, int number, FILE* fp);
}

#endif // !_N_FILE_H_
