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
    const wstring GetFilePath() const
    {
        return this->path;
    }

    // public query apis;
    const Token* GetCurrentToken() const;
    const Token* GetTokenByRelativePos(int pos) const;

    // public search apis;
    const Token* FindNextTargetTokenInSameStmt(TokenKind tokenKind, int& steps) const;
    const Token* FindNextTargetTokenInSameLine(TokenKind tokenKind, int& steps) const;
    const Token* FindMatchingBrace(TokenKind tokenKind, int& steps) const;

    // public move apis;
    const Token* GotoStart();
    const Token* GotoNextToken();
    const Token* GotoPrevToken();
    const Token* GotoTokenByRelativePos(int pos);
    const Token* GotoNextTargetTokenInSameStmt(TokenKind tokenKind);
    const Token* GotoNextTargetTokenInSameLine(TokenKind tokenKind);
    const Token* GotoEol();
    const Token* GotoMatchingBrace(TokenKind kind);

private:
    const Token* FindTargetTokenInScope(TokenKind kind, int& steps, TokenSearchDirection direction, TokenSearchScope scope) const;

    void SkipWhitespaces(const wstring &stream, int &pos, int &spaceCount, int &tabCount);
    const Token* GetToken(int index) const;
    const wstring path;
    vector<Token*> tokens;
    int currentIndex;
};

#endif
