//© 2018 NIREX ALL RIGHTS RESERVED

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

	std::string szSuperEncrypted;
	szSuperEncrypted = NES::TEXT_NESA0(szText, szKey);
	szSuperEncrypted = NES::TEXT_NESA0(szSuperEncrypted, szKey);
	szSuperEncrypted = NES::TEXT_NESB0(szSuperEncrypted, szKey);
	szSuperEncrypted = NES::TEXT_NESB0(szSuperEncrypted, szKey);
	szSuperEncrypted = NES::TEXT_NESA1(szSuperEncrypted, szKey);
	szSuperEncrypted = NES::TEXT_NESC0(szSuperEncrypted, szKey);
	szSuperEncrypted = NES::TEXT_NESC0(szSuperEncrypted, szKey);
	szSuperEncrypted = NES::TEXT_NESA1(szSuperEncrypted, szKey);

	std::string szSuperDecrypted;
	szSuperDecrypted = NES::TEXT_NESA0(szSuperEncrypted, szKey);
	szSuperDecrypted = NES::TEXT_NESC1(szSuperDecrypted, szKey);
	szSuperDecrypted = NES::TEXT_NESC1(szSuperDecrypted, szKey);
	szSuperDecrypted = NES::TEXT_NESA0(szSuperDecrypted, szKey);
	szSuperDecrypted = NES::TEXT_NESB1(szSuperDecrypted, szKey);
	szSuperDecrypted = NES::TEXT_NESB1(szSuperDecrypted, szKey);
	szSuperDecrypted = NES::TEXT_NESA1(szSuperDecrypted, szKey);
	szSuperDecrypted = NES::TEXT_NESA1(szSuperDecrypted, szKey);

	COUT << "Encrypted(Pattern): ";
	COUT << szSuperEncrypted << ENDL;
	COUT << "Decrypted(Pattern): ";
	COUT << szSuperDecrypted << ENDL;
	COUT << ENDL;

	return S_OK;
}