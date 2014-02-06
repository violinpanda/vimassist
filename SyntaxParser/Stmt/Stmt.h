#ifndef __STMT_H__
#define __STMT_H__
#include "Lexer\TokenStream.h"

enum StmtKind
{
    EK_VarDefExpr,


    SK_LineCommentStmt,
    SK_BlockCommentStmt,
    SK_IncludeStmt,
    SK_WhileStmt,
    SK_IfStmt,
    SK_TopLevelStmt,
    SK_ClassStmt,
    SK_FuncDefStmt,
    SK_FuncBodyStmt,
};

class Stmt
{
public:
    Stmt(TokenStream& tokenStream, const Stmt* parent);

    virtual const wstring GetName() const = 0;
    virtual const StmtKind GetKind() const = 0;
    virtual bool IsMe() const = 0;
    virtual Stmt* Parse() = 0;
    const Stmt* GetParent() const;

protected:
    TokenStream &tokenStream;
    const Stmt* parent;
};

#endif

