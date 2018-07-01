//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _N_NES_H_
#define _N_NES_H_

#include "Precompiled.h"
#include <string>
#include <vector>

namespace NES
{
	//A
	//0
	std::string NESForward(std::string text, std::string key);
	//1
	std::string NESBackward(std::string text, std::string key);

	//B
	//0
	std::string NPLForward(std::string text, std::string key);
	//1
	std::string NPLBackward(std::string text, std::string key);

	//C
	//0
	std::string NSXForward(std::string text, std::string key);
	//1
	std::string NSXBackward(std::string text, std::string key);
}

#endif // !_N_NES_H_