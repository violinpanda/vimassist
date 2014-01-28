#ifndef __STMT_H__
#define __STMT_H__
#include "Lexer\TokenStream.h"

class Stmt
{
public:
    Stmt(TokenStream &TokenStream);

    virtual const wstring GetName() const = 0;

protected:
    TokenStream &tokenStream;
};

#endif

