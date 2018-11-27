//© 2018 NIREX ALL RIGHTS RESERVED

// Pipeline Guidelines:
// A: A0 and A1 are free to use and your go-to
// B: B0 must only be used before B1 (If you use B1 without B0 your data will be corrupted)
// C: C Pipeline Is under development

#include "Precompiled.h"
#include "NES.h"
#include "NString.h"
#include "NPattern.h"

#include <iostream>
#include <Windows.h>

#include "NTime.h"

FILL main(INT argc, NStrArray argv) -> INT
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

	//COUT << "Text: ";
	//LINE(CIN, szText);

	//COUT << "Key: ";
	//LINE(CIN, szKey);
	
	szText = "The Secret Message!";
	szKey = "The Master Key is: \"Master Secret Key!!!!XXXXXXXXXXXX\"";

	COUT << ENDL;

	szEncrypted = NES::TEXT_NESA0(szText, szKey);
	Sleep(10);
	szEncrypted01 = NES::TEXT_NESA0(szText, szKey);
	Sleep(10);
	szEncrypted02 = NES::TEXT_NESA0(szText, szKey);
	Sleep(10);
	szEncrypted03 = NES::TEXT_NESA0(szText, szKey);
	Sleep(10);
	szDecrypted = NES::TEXT_NESA1(szEncrypted, szKey);
	szDecrypted01 = NES::TEXT_NESA1(szEncrypted01, szKey);
	szDecrypted02 = NES::TEXT_NESA1(szEncrypted02, szKey);
	szDecrypted03 = NES::TEXT_NESA1(szEncrypted03, szKey);

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
	COUT << "Decrypted(A_02): ";
	COUT << szDecrypted01 << ENDL;
	COUT << "Decrypted(A_02): ";
	COUT << szDecrypted02 << ENDL;
	COUT << "Decrypted(A_03): ";
	COUT << szDecrypted03 << ENDL;
	COUT << ENDL;


	szEncrypted = NES::TEXT_NESB0(szText, szKey);
	Sleep(10);
	szEncrypted01 = NES::TEXT_NESB0(szText, szKey);
	Sleep(10);
	szEncrypted02 = NES::TEXT_NESB0(szText, szKey);
	Sleep(10);
	szEncrypted03 = NES::TEXT_NESB0(szText, szKey);
	Sleep(10);
	szDecrypted = NES::TEXT_NESB1(szEncrypted, szKey);
	szDecrypted01 = NES::TEXT_NESB1(szEncrypted01, szKey);
	szDecrypted02 = NES::TEXT_NESB1(szEncrypted02, szKey);
	szDecrypted03 = NES::TEXT_NESB1(szEncrypted03, szKey);


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
	COUT << "Decrypted(B_02): ";
	COUT << szDecrypted01 << ENDL;
	COUT << "Decrypted(B_02): ";
	COUT << szDecrypted02 << ENDL;
	COUT << "Decrypted(B_03): ";
	COUT << szDecrypted03 << ENDL;
	COUT << ENDL;
							   

	int x;
	CIN >> x;


	return S_OK;
}