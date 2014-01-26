#ifndef __STMT_H__
#define __STMT_H__
#include "Lexer\TokenStream.h"

class Stmt
{
public:
    Stmt(TokenStream &TokenStream);

public:
    // debug interfaces;
    virtual const wstring Print(int level) const
    {
        return _T("");
    }

    virtual const wstring ToString() const
    {
        return _T("");
    }
};

#endif

