#ifndef __TOKEN_H__
#define __TOKEN_H__
#include "Basic\Common.h"
#include "Basic\Location.h"
enum TokenKind;

class Token
{
public:
	Token(const _TCHAR*);
    Token(const _TCHAR *content, Location location);
	~Token();
    TokenKind GetKind() const;
    const wstring GetContent() const
    {
        return this->content;
    }

private:
    void ParseKind();

private:
    TokenKind kind;
    Location location;
    wstring content;
};

#endif
