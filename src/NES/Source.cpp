#include "Precompiled.h"
#include "NES.h"
#include "NFile.h"
#include "NString.h"

#include <iostream>

FILL main(INT argc, NStrArray argv) -> INT
{
	if (argc < 5)
	{
		COUT << "E: Invalid Syntax" << ENDL << ENDL;
		COUT << "Syntax: nes <mode> <input> <output> <password>" << ENDL << ENDL;
		COUT << "Mode: E/D" << ENDL;
		COUT << "E: To Encrypt" << ENDL;
		COUT << "D: To Decrypt" << ENDL << ENDL;
		COUT << "Input: path to input file" << ENDL;
		COUT << "Output: path to output file";
		return E_ABORT;
	}
	else
	{
		COUT << "Operation in progress..." << ENDL;

		std::string mode = argv[1];
		std::string input_path = argv[2];
		std::string output_path = argv[3];
		std::string password = argv[4];

		std::string input_text = NFile::ReadAllText(input_path);
		std::string output_text;

		if (NString::ToUpper(mode) == "E")
		{
			output_text = NES::NESEncrypt(input_text, password);
		}
		else if (NString::ToUpper(mode) == "D")
		{
			output_text = NES::NESDecrypt(input_text, password);
		}
		else
		{
			output_text = "ERROR";
		}

		NFile::WriteAllText(output_path, output_text);
		COUT << "Done!" << ENDL;
	}
	return S_OK;
}