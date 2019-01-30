//© 2019 NIREX ALL RIGHTS RESERVED

/************************************************\
Pipeline Guidelines:
A: A0 and A1 are free to use and your go-to methods when you 
want a fast and lite encryption.

B: Do not use B1 when encrypting your data, it will corrupt it.
B1 is only meant for decryption.

C: Do not use C1 when encrypting your data, it will corrupt it
C1 is only meant of decryption.

\************************************************/

#include "Precompiled.h"
#include "NES.h"
#include "NString.h"
#include "NPattern.h"

#include <iostream>

#include "NWin.h"
#include "NTime.h"
#include "NFile.h"

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

		szEncrypted = BMP::BM_A0(szText, szKey);
		Sleep(10);
		szEncrypted01 = BMP::BM_A0(szText, szKey);
		Sleep(10);
		szEncrypted02 = BMP::BM_A0(szText, szKey);
		Sleep(10);
		szEncrypted03 = BMP::BM_A0(szText, szKey);
		szDecrypted = BMP::BM_A1(szEncrypted, szKey);
		szDecrypted01 = BMP::BM_A1(szEncrypted01, szKey);
		szDecrypted02 = BMP::BM_A1(szEncrypted02, szKey);
		szDecrypted03 = BMP::BM_A1(szEncrypted03, szKey);

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

		szEncrypted = BMP::BM_B0(szText, szKey);
		Sleep(10);
		szEncrypted01 = BMP::BM_B0(szText, szKey);
		Sleep(10);
		szEncrypted02 = BMP::BM_B0(szText, szKey);
		Sleep(10);
		szEncrypted03 = BMP::BM_B0(szText, szKey);
		szDecrypted = BMP::BM_B1(szEncrypted, szKey);
		szDecrypted01 = BMP::BM_B1(szEncrypted01, szKey);
		szDecrypted02 = BMP::BM_B1(szEncrypted02, szKey);
		szDecrypted03 = BMP::BM_B1(szEncrypted03, szKey);

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

		szEncrypted = BMP::BM_C0(szText, szKey);
		Sleep(10);
		szEncrypted01 = BMP::BM_C0(szText, szKey);
		Sleep(10);
		szEncrypted02 = BMP::BM_C0(szText, szKey);
		Sleep(10);
		szEncrypted03 = BMP::BM_C0(szText, szKey);
		szDecrypted = BMP::BM_C1(szEncrypted, szKey);
		szDecrypted01 = BMP::BM_C1(szEncrypted01, szKey);
		szDecrypted02 = BMP::BM_C1(szEncrypted02, szKey);
		szDecrypted03 = BMP::BM_C1(szEncrypted03, szKey);

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

		std::string szMegaEncrypted;
		std::string szMegaDecrypted;

		szMegaEncrypted = BMP::BM_A0(szText, szKey);
		szMegaEncrypted = NString::ToHex(szMegaEncrypted);

		szMegaEncrypted = BMP::BM_A0(szMegaEncrypted, szKey);
		szMegaEncrypted = NString::ToHex(szMegaEncrypted);

		szMegaEncrypted = BMP::BM_A0(szMegaEncrypted, szKey);
		szMegaEncrypted = NString::ToHex(szMegaEncrypted);

		szMegaEncrypted = BMP::BM_B0(szMegaEncrypted, szKey);
		szMegaEncrypted = NString::ToHex(szMegaEncrypted);

		szMegaEncrypted = BMP::BM_B0(szMegaEncrypted, szKey);
		szMegaEncrypted = NString::ToHex(szMegaEncrypted);

		szMegaEncrypted = BMP::BM_B0(szMegaEncrypted, szKey);
		szMegaEncrypted = NString::ToHex(szMegaEncrypted);

		szMegaEncrypted = BMP::BM_C0(szMegaEncrypted, szKey);
		szMegaEncrypted = NString::ToHex(szMegaEncrypted);

		szMegaEncrypted = BMP::BM_C0(szMegaEncrypted, szKey);
		szMegaEncrypted = NString::ToHex(szMegaEncrypted);

		szMegaEncrypted = BMP::BM_C0(szMegaEncrypted, szKey);
		NFile::WriteAllText("Normal-Out.bin", szMegaEncrypted);
		
		szMegaEncrypted = NString::ToHex(szMegaEncrypted);
		NFile::WriteAllText("Hex-Out.bin", szMegaEncrypted);

		szMegaEncrypted = NString::FromHex(szMegaEncrypted);
		szMegaDecrypted = BMP::BM_C1(szMegaEncrypted, szKey);

		szMegaDecrypted = NString::FromHex(szMegaDecrypted);
		szMegaDecrypted = BMP::BM_C1(szMegaDecrypted, szKey);

		szMegaDecrypted = NString::FromHex(szMegaDecrypted);
		szMegaDecrypted = BMP::BM_C1(szMegaDecrypted, szKey);

		szMegaDecrypted = NString::FromHex(szMegaDecrypted);
		szMegaDecrypted = BMP::BM_B1(szMegaDecrypted, szKey);

		szMegaDecrypted = NString::FromHex(szMegaDecrypted);
		szMegaDecrypted = BMP::BM_B1(szMegaDecrypted, szKey);

		szMegaDecrypted = NString::FromHex(szMegaDecrypted);
		szMegaDecrypted = BMP::BM_B1(szMegaDecrypted, szKey);

		szMegaDecrypted = NString::FromHex(szMegaDecrypted);
		szMegaDecrypted = BMP::BM_A1(szMegaDecrypted, szKey);

		szMegaDecrypted = NString::FromHex(szMegaDecrypted);
		szMegaDecrypted = BMP::BM_A1(szMegaDecrypted, szKey);

		szMegaDecrypted = NString::FromHex(szMegaDecrypted);
		szMegaDecrypted = BMP::BM_A1(szMegaDecrypted, szKey);

		COUT << "Super Encryption: ";
		COUT << "Super Decryption: ";
		COUT << szMegaDecrypted << ENDL;
		COUT << ENDL;
	}
	return S_OK;
}