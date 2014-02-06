#ifndef __VAR_DEF_EXPR_H__
#define __VAR_DEF_EXPR_H__
#include "SyntaxParser\Stmt\Expr\Expr.h"

class VarDefExpr : public Expr
{
public:
    VarDefExpr(TokenStream& tokenStream, const Stmt* parent)
        : Expr(tokenStream, parent)
    {}
    virtual const wstring GetName() const;
    virtual const StmtKind GetKind() const
    {
        return EK_VarDefExpr;
    }
    virtual Stmt* Parse();

private:
    VarDefExpr* next;

    wstring type;
    wstring name;
    bool isPointer;
    bool isRef;
    bool isArray;
};

#endif
