#ifndef __INCLUDE_STMT_H__
#define __INCLUDE_STMT_H__
#include "Stmt.h"
#include "Lexer\TokenStream.h"

class IncludeStmt : public Stmt
{
public:
    IncludeStmt(TokenStream &tokenStream, const Stmt* parent);
    virtual const StmtKind GetKind() const
    {
        return SK_IncludeStmt;
    }
    virtual const wstring GetName() const;
    virtual bool IsMe() const;
    virtual Stmt* Parse();

protected:
    wstring includedFile;
};

#endif

