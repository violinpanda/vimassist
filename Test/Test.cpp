// Test.cpp : Defines the entry point for the console application.
//

#include <string>
#include <fstream>
#include <streambuf>
#include "Lexer\SourceFile.h"
extern void LexerTest();

int _tmain(int argc, _TCHAR* argv[])
{
    SourceFile srcFile(_T("Test.cpp"));
}
