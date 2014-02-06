#ifndef __EXPR_H__
#define __EXPR_H__
#include "SyntaxParser\Stmt\Stmt.h"

class Expr : public Stmt
{
public:
    Expr(TokenStream& tokenStream, const Stmt* parent)
        : Stmt(tokenStream, parent)
    {}
    virtual bool IsMe() const
    {
        return true;
    }
};

#endif
