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
    const Token* GetCurrentToken() const;
    const Token* GetNextToken() const;
    const Token* GetPrevToken() const;
    const Token* GotoStart();
    const Token* MoveToNextToken();
    const Token* MoveToPrevToken();

private:
    void SkipWhitespaces(const wstring &stream, int &pos, int &spaceCount, int &tabCount);
    const Token* GetToken(int index) const;
    const wstring path;
    vector<Token*> tokens;
    int currentIndex;
};

#endif
