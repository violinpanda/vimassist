#ifndef __STMT_H__
#define __STMT_H__
#include "Lexer\TokenStream.h"

enum StmtKind
{
    SK_IncludeStmt,
    SK_ComposedStmt,
    SK_WhileStmt,
    SK_IfStmt,
};

class Stmt
{
public:
    Stmt(TokenStream& TokenStream, const Stmt* parent);

    virtual const wstring GetName() const = 0;
    virtual const StmtKind GetKind() const = 0;
    virtual bool IsMe() const = 0;
    const Stmt* GetParent() const;

protected:
    virtual void Parse() = 0;
    TokenStream &tokenStream;
    const Stmt* parent;
};

#endif

