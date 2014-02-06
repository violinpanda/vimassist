#ifndef __FUNC_DEF_STMT_H__
#define __FUNC_DEF_STMT_H__
#include "Stmt.h"
#include "Lexer\TokenStream.h"
#include "SyntaxParser\Stmt\ComposedStmt.h"
#include "SyntaxParser\Stmt\Expr\VarDefExpr.h"

class FuncDefStmt : public Stmt
{
public:
    FuncDefStmt(TokenStream &tokenStream, const Stmt* parent)
        : Stmt(tokenStream, parent),
        funcName(_T("")),
        funcParams(new VarDefExpr(tokenStream, this)),
        funcBody(new ComposedStmt(tokenStream, this, SK_FuncDefStmt))
    {
    }

    ~FuncDefStmt()
    {
        delete this->funcBody;
    }

    virtual const StmtKind GetKind() const
    {
        return SK_FuncDefStmt;
    }
    virtual const wstring GetName() const;
    virtual bool IsMe() const;
    virtual Stmt* Parse();
    
protected:
    wstring funcName;
    VarDefExpr* funcParams;
    ComposedStmt* funcBody;

private:
    void ParseFuncName();
    void ParseFuncParams();
    void ParseFuncBody();
};

#endif

