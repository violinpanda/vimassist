// Test.cpp : Defines the entry point for the console application.
//

#include <string>
#include <fstream>
#include <streambuf>
#include "Lexer\SourceFile.h"

int _tmain(int argc, _TCHAR* argv[])
{
	//_TCHAR str[10] = _T("abcd");
	//cout <<wcslen(str) <<endl;
	//
	//_TCHAR* dest = new _TCHAR[wcslen(str)];
	//wcsncpy(dest, str, wcslen(str));

	//delete[] dest;
    //assert(false, "haha");

    SourceFile srcFile("Test.cpp");
//    srcFile.ParseFile();
}

