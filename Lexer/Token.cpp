#include "Token.h"
#include "TokenKind.h"

Token::Token(const _TCHAR* data)
    : str(data)
{
    this->ParseKind();
}

Token::~Token()
{
}

void Token::ParseKind()
{
    this->kind = TokenMatcher::GetMe().GetTokenKind(this->str.c_str());
}
