#ifndef __TOP_LEVEL_STMT_H__
#define __TOP_LEVEL_STMT_H__
#include "SyntaxParser\Stmt\Stmt.h"
#include "SyntaxParser\Stmt\ComposedStmt.h"
#include "Lexer\TokenStream.h"

class TopLevelStmt : public ComposedStmt
{
public:
    TopLevelStmt(TokenStream &tokenStream, const Stmt* parent)
        : ComposedStmt(tokenStream, parent, SK_TopLevelStmt)
    {}
    ~TopLevelStmt()
    {
    }
    virtual const StmtKind GetKind() const
    {
        return SK_TopLevelStmt;
    }
    virtual const wstring GetName() const
    {
        wstring name = _T("TopLevelStmt: ");
        name += this->tokenStream.GetFilePath();
        return name;
    }
};
#endif
