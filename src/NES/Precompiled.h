//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _N_PRECOMPILED_H_
#define _N_PRECOMPILED_H_

// Special Propertoes
#define EMPTY_VAL		""
#define PLHDR_VAL		""
#define STR_NEWLN		10
#define ENV_NEWLN		std::endl
#define STR_CPRGT		"//© 2018 NIREX ALL RIGHTS RESERVED"

// iostream 
#define ENDL			std::endl
#define COUT			std::cout
#define CIN				std::cin
#define LINE			std::getline

// Custom Types
typedef char**			NStrArray;
typedef int				INT;
typedef bool			BOOL;

// Custom Definitions
#define FILL			auto
#define FALSE			0
#define TRUE			1

// Error Codes
#define E_ERR			-1
#define S_OK			0
#define E_ABORT			1
#define E_NOTIMPL		2
#define E_UNKNOWN		3

// Custom Macros
#define	UNREFERENCED_PARAMETER(P) P

#endif // !_N_PRECOMPILED_H_