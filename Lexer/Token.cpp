#include "Lexer\TokenKind.h"
#include "Lexer\TokenStream.h"
#include "Lexer\Token.h"

Token::Token(const _TCHAR* content)
    : content(content)
{
    this->ParseKind();
}

Token::Token(const _TCHAR *content, Location location)
    : content(content)
{
    this->ParseKind();
    this->location = location;
}

Token::~Token()
{
}

void Token::ParseKind()
{
    this->kind = TokenMatcher::GetMe().GetKind(this->content.c_str());
}

TokenKind Token::GetKind() const
{
    return this->kind;
}

