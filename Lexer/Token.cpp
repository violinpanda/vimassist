#include "Token.h"
#include "TokenKind.h"

Token::Token(const _TCHAR* data)
{
    int length = wcslen(data);
    wcsncpy(this->data, data, length);
    this->ParseKind();
}

Token::~Token()
{
    delete[] this->data;
}
