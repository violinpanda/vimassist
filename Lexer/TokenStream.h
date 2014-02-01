#ifndef __SOURCE_FILE_H__
#define __SOURCE_FILE_H__
#include "Basic\Common.h"
#include <vector>
#include <string>
#include "Lexer\TokenKind.h"

class Token;
enum TokenSearchDirection
{
    Forward,
    Backward,
};

enum TokenSearchScope
{
    SameLine,
    SameStmt,
};

class TokenStream
{
public:
	TokenStream(const wstring path);
	~TokenStream();

    void ParseFile();
    const Token* GetCurrentToken() const;
    const Token* GetTokenByRelativePos(int pos) const;
    const Token* GotoStart();
    const Token* GotoNextToken();
    const Token* GotoPrevToken();
    const Token* GotoTokenByRelativePos(int pos);

    // public search apis for external parsers like SyntaxParser/SementicParser;
    const Token* FindNextTargetTokenInSameStmt(TokenKind tokenKind, int& steps) const;
    const Token* FindNextTargetTokenInSameLine(TokenKind tokenKind, int& steps) const;

    // public move apis for external parsers like SyntaxParser/SementicParser;
    const Token* MoveToNextTargetTokenInSameStmt(TokenKind tokenKind);
    const Token* MoveToNextTargetTokenInSameLine(TokenKind tokenKind);

private:
    const Token* FindTargetTokenInScope(TokenKind kind, int& steps, TokenSearchDirection direction, TokenSearchScope scope) const;

    void SkipWhitespaces(const wstring &stream, int &pos, int &spaceCount, int &tabCount);
    const Token* GetToken(int index) const;
    const wstring path;
    vector<Token*> tokens;
    int currentIndex;
};

#endif
