#ifndef __TOKEN_H__
#define __TOKEN_H__
#include <Basic\Common.h>
#include <string>
#include "SourceLocation.h"
enum TokenKind;

class Token
{
public:
	Token(const _TCHAR*);
    Token(const _TCHAR *content, SourceLocation location);
	~Token();
    SourceLocation Location;
    TokenKind GetKind() const;

private:
    void ParseKind();

private:
    TokenKind kind;
    wstring content;
};

#endif
