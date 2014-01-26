#ifndef __SOURCE_FILE_H__
#define __SOURCE_FILE_H__
#include "Basic\Common.h"
#include <vector>
#include <string>

class Token;

class TokenStream
{
public:
	TokenStream(const wstring path);
	~TokenStream();

    void ParseFile();
    const Token* GotoStart();
    const Token* GetCurrentToken();
    const Token* GetNextToken();
    const Token* GetPrevToken();
    const Token* MoveToNextToken();
    const Token* MoveToPrevToken();

private:
    void SkipWhitespaces(const wstring &stream, int &pos, int &spaceCount, int &tabCount);
    const Token* GetToken(int index);
    const wstring path;
    vector<Token*> tokens;
    int currentIndex;
};

#endif
