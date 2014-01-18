// Test.cpp : Defines the entry point for the console application.
//

#include "Basic\Common.h"
#include <vector>
#include "Lexer\Token.h"

int _tmain(int argc, _TCHAR* argv[])
{
	//vector<Token> tokens;
	//tokens.push_back(Token());
	//tokens.push_back(Token());
	//tokens.clear();

	_TCHAR str[10] = _T("abcd");
	cout <<wcslen(str) <<endl;
	cout <<sizeof(str) <<endl;
	
	_TCHAR* dest = new _TCHAR[wcslen(str)];
	wcsncpy(dest, str, wcslen(str));
	wcout <<"haha: " <<str <<". " <<dest <<endl;

	delete[] dest;
	return 0;
}

