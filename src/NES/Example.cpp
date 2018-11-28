//© 2018 NIREX ALL RIGHTS RESERVED

// Pipeline Guidelines:
// A: A0 and A1 are free to use and your go-to methods when you want a fast and lite encryption.
// B: Do not use B1 when encrypting your data, it will corrupt it.
//	: B1 is only meant for decryption.
// C: Do not use C1 when encrypting your data, it will corrupt it
//	: C1 is only meant of decryption.

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
	COUT << "Decrypted(A_01): ";
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
	COUT << "Decrypted(B_01): ";
	COUT << szDecrypted01 << ENDL;
	COUT << "Decrypted(B_02): ";
	COUT << szDecrypted02 << ENDL;
	COUT << "Decrypted(B_03): ";
	COUT << szDecrypted03 << ENDL;
	COUT << ENDL;


	szEncrypted = NES::TEXT_NESC0(szText, szKey);
	Sleep(10);
	szEncrypted01 = NES::TEXT_NESC0(szText, szKey);
	Sleep(10);
	szEncrypted02 = NES::TEXT_NESC0(szText, szKey);
	Sleep(10);
	szEncrypted03 = NES::TEXT_NESC0(szText, szKey);
	szDecrypted = NES::TEXT_NESC1(szEncrypted, szKey);
	szDecrypted01 = NES::TEXT_NESC1(szEncrypted01, szKey);
	szDecrypted02 = NES::TEXT_NESC1(szEncrypted02, szKey);
	szDecrypted03 = NES::TEXT_NESC1(szEncrypted03, szKey);

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


	int x;
	CIN >> x;


	return S_OK;
}