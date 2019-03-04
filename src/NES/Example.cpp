//© 2019 NIREX ALL RIGHTS RESERVED

#include "Precompiled.h"
#include "NES.h"
#include "NString.h"
#include "NPattern.h"

#include <iostream>

#include "NWin.h"
#include "NTime.h"
#include "NFile.h"

std::vector<BYTE> StrToVec(const std::string& in)
{
	std::vector<BYTE> outVec;
	for (size_t i = 0; i < in.length(); i++)
	{
		outVec.push_back(in[i]);
	}
	return outVec;
}

std::string VecToStr(const std::vector<BYTE>& in)
{
	std::string outVal;
	for (size_t i = 0; i < in.size(); i++)
	{
		outVal.push_back(in[i]);
	}
	return outVal;
}

FILL main(NINT argc, NStrArray argv) -> NINT
{
	while (true)
	{
		UNREFERENCED_PARAMETER(argc);
		UNREFERENCED_PARAMETER(argv);

		std::string szText;
		std::string szKey;
		std::string szEncrypted;
		std::string szEncrypted01;
		std::string szEncrypted02;
		std::string szEncrypted03;
				   
		std::string szDecrypted;
		std::string szDecrypted01;
		std::string szDecrypted02;
		std::string szDecrypted03;

		COUT << "Text: ";
		LINE(CIN, szText);

		COUT << "Key: ";
		LINE(CIN, szKey);

		COUT << ENDL;

		szEncrypted = BP::EncryptA(szText, szKey);
		Sleep(10);
		szEncrypted01 = BP::EncryptA(szText, szKey);
		Sleep(10);
		szEncrypted02 = BP::EncryptA(szText, szKey);
		Sleep(10);
		szEncrypted03 = BP::EncryptA(szText, szKey);

		szDecrypted = BP::DecryptA(szEncrypted, szKey);
		szDecrypted01 = BP::DecryptA(szEncrypted01, szKey);
		szDecrypted02 = BP::DecryptA(szEncrypted02, szKey);
		szDecrypted03 = BP::DecryptA(szEncrypted03, szKey);

		COUT << "Encrypted(A_00): ";
		COUT << szEncrypted << ENDL;
		COUT << "Encrypted(A_01): ";
		COUT << szEncrypted01 << ENDL;
		COUT << "Encrypted(A_02): ";
		COUT << szEncrypted02 << ENDL;
		COUT << "Encrypted(A_03): ";
		COUT << szEncrypted03 << ENDL;

		COUT << ENDL;

		COUT << "Decrypted(A_00): ";
		COUT << szDecrypted << ENDL;
		COUT << "Decrypted(A_01): ";
		COUT << szDecrypted01 << ENDL;
		COUT << "Decrypted(A_02): ";
		COUT << szDecrypted02 << ENDL;
		COUT << "Decrypted(A_03): ";
		COUT << szDecrypted03 << ENDL;
		COUT << ENDL;

		szEncrypted = BP::EncryptB(szText, szKey);
		Sleep(10);
		szEncrypted01 = BP::EncryptB(szText, szKey);
		Sleep(10);
		szEncrypted02 = BP::EncryptB(szText, szKey);
		Sleep(10);
		szEncrypted03 = BP::EncryptB(szText, szKey);

		szDecrypted = BP::DecryptB(szEncrypted, szKey);
		szDecrypted01 = BP::DecryptB(szEncrypted01, szKey);
		szDecrypted02 = BP::DecryptB(szEncrypted02, szKey);
		szDecrypted03 = BP::DecryptB(szEncrypted03, szKey);

		COUT << "Encrypted(B_00): ";
		COUT << szEncrypted << ENDL;
		COUT << "Encrypted(B_01): ";
		COUT << szEncrypted01 << ENDL;
		COUT << "Encrypted(B_02): ";
		COUT << szEncrypted02 << ENDL;
		COUT << "Encrypted(B_03): ";
		COUT << szEncrypted03 << ENDL;

		COUT << ENDL;

		COUT << "Decrypted(B_00): ";
		COUT << szDecrypted << ENDL;
		COUT << "Decrypted(B_01): ";
		COUT << szDecrypted01 << ENDL;
		COUT << "Decrypted(B_02): ";
		COUT << szDecrypted02 << ENDL;
		COUT << "Decrypted(B_03): ";
		COUT << szDecrypted03 << ENDL;
		COUT << ENDL;

		szEncrypted = BP::EncryptC(szText, szKey);
		Sleep(10);
		szEncrypted01 = BP::EncryptC(szText, szKey);
		Sleep(10);
		szEncrypted02 = BP::EncryptC(szText, szKey);
		Sleep(10);
		szEncrypted03 = BP::EncryptC(szText, szKey);

		szDecrypted = BP::DecryptC(szEncrypted, szKey);
		szDecrypted01 = BP::DecryptC(szEncrypted01, szKey);
		szDecrypted02 = BP::DecryptC(szEncrypted02, szKey);
		szDecrypted03 = BP::DecryptC(szEncrypted03, szKey);

		COUT << "Encrypted(C_00): ";
		COUT << szEncrypted << ENDL;
		COUT << "Encrypted(C_01): ";
		COUT << szEncrypted01 << ENDL;
		COUT << "Encrypted(C_02): ";
		COUT << szEncrypted02 << ENDL;
		COUT << "Encrypted(C_03): ";
		COUT << szEncrypted03 << ENDL;

		COUT << ENDL;

		COUT << "Decrypted(C_00): ";
		COUT << szDecrypted << ENDL;
		COUT << "Decrypted(C_01): ";
		COUT << szDecrypted01 << ENDL;
		COUT << "Decrypted(C_02): ";
		COUT << szDecrypted02 << ENDL;
		COUT << "Decrypted(C_03): ";
		COUT << szDecrypted03 << ENDL;
		COUT << ENDL;

		std::vector<BYTE> szMegaEncrypted = StrToVec(szText);

		szMegaEncrypted = BP::EncryptA(szMegaEncrypted, szKey);
		szMegaEncrypted = BP::EncryptB(szMegaEncrypted, szKey);
		//szMegaEncrypted = BP::EncryptC(szMegaEncrypted, szKey);

		szMegaEncrypted = BP::EncryptA(szMegaEncrypted, szKey);
		szMegaEncrypted = BP::EncryptB(szMegaEncrypted, szKey);
		//szMegaEncrypted = BP::EncryptC(szMegaEncrypted, szKey);

		std::vector<BYTE> szMegaDecrypted = szMegaEncrypted;

		//szMegaDecrypted = BP::DecryptC(szMegaDecrypted, szKey);
		szMegaDecrypted = BP::DecryptB(szMegaDecrypted, szKey);
		szMegaDecrypted = BP::DecryptA(szMegaDecrypted, szKey);

		//szMegaDecrypted = BP::DecryptC(szMegaDecrypted, szKey);
		szMegaDecrypted = BP::DecryptB(szMegaDecrypted, szKey);
		szMegaDecrypted = BP::DecryptA(szMegaDecrypted, szKey);

		COUT << "Super Decryption: ";
		COUT << VecToStr(szMegaDecrypted) << ENDL;
		COUT << ENDL;
	}
	return S_OK;
}