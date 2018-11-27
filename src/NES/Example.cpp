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

FILL main(INT argc, NStrArray argv) -> INT
{
	UNREFERENCED_PARAMETER(argc);
	UNREFERENCED_PARAMETER(argv);

	std::string szText;
	std::string szKey;
	std::string szEncrypted;
	std::string szDecrypted;

	COUT << "Text: ";
	LINE(CIN, szText);

	COUT << "Key: ";
	LINE(CIN, szKey);
	
	COUT << ENDL;

	szEncrypted = NES::TEXT_NESA0(szText, szKey);
	szDecrypted = NES::TEXT_NESA1(szEncrypted, szKey);

	COUT << "Encrypted(A): ";
	COUT << szEncrypted << ENDL;
	COUT << "Decrypted(A): ";
	COUT << szDecrypted << ENDL;
	COUT << ENDL;

	szEncrypted = NES::TEXT_NESB0(szText, szKey);
	szDecrypted = NES::TEXT_NESB1(szEncrypted, szKey);

	COUT << "Encrypted(B): "; 
	COUT << szEncrypted << ENDL;
	COUT << "Decrypted(B): "; 
	COUT << szDecrypted << ENDL;
	COUT << ENDL;
							   
	szEncrypted = NES::TEXT_NESC0(szText, szKey);
	szDecrypted = NES::TEXT_NESC1(szEncrypted, szKey);

	COUT << "Encrypted(C): "; 
	COUT << szEncrypted << ENDL;
	COUT << "Decrypted(C): "; 
	COUT << szDecrypted << ENDL;
	COUT << ENDL;

	int x;
	CIN >> x;
	return S_OK;
}