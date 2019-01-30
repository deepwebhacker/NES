//© 2019 NIREX ALL RIGHTS RESERVED

#ifndef _N_TIME_H_
#define _N_TIME_H_

#include "Precompiled.h"

#include <string>
#include <vector>
#include <numeric>
#include <chrono>

using EPOCH = unsigned long;
using BYTE = unsigned char;

class NTime
{
public:
	static inline EPOCH GrabEpoch(void)
	{
		std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
		std::chrono::minutes m = std::chrono::duration_cast<std::chrono::minutes>(std::chrono::system_clock::now().time_since_epoch());
		std::chrono::nanoseconds ns = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch());
		std::chrono::seconds s = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch());

		return ((EPOCH)(ms.count() + s.count() + m.count()));
	}
	
	static inline std::vector<BYTE> DataFromEpoch(EPOCH time)
	{
		unsigned int byte0 = time % 256;
		unsigned int byte1 = time % 65536 - byte0;
		unsigned int byte2 = time % 16777216 - (byte0 + byte1);
		unsigned int byte3 = time % 4294967296 - (byte0 + byte1 + byte2);

		std::vector<BYTE> outVec;
		outVec.push_back(byte3);
		outVec.push_back(byte2);
		outVec.push_back(byte1);
		outVec.push_back(byte0);

		return outVec;
	}

	static inline EPOCH EpochFromData(std::vector<BYTE> data)
	{
		return ((EPOCH)(((BYTE)data[0]) << 24)
			| (EPOCH)(((BYTE)data[1]) << 16)
			| (EPOCH)(((BYTE)data[2]) << 8)
			| (EPOCH)((BYTE)data[3]));
	}
};

#endif // !_N_TIME_H_
