#ifndef __TOKEN_H__
#define __TOKEN_H__
#include <Basic\Common.h>
enum TokenKind;

class Token
{
public:
	Token(const _TCHAR*);
	~Token();

private:
    void ParseKind();

private:
    Token* next;
    Token* prev;
    TokenKind kind;
    _TCHAR* data;
};

#endif
