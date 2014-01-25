#include "Token.h"
#include "TokenKind.h"

Token::Token(const _TCHAR* content)
    : content(content)
{
    this->ParseKind();
}

Token::Token(const _TCHAR *content, SourceLocation location)
    : content(content)
{
    this->ParseKind();
    this->Location = location;
}

Token::~Token()
{
}

void Token::ParseKind()
{
    this->kind = TokenMatcher::GetMe().GetTokenKind(this->content.c_str());
}
