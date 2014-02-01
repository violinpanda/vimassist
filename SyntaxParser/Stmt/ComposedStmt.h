#ifndef __TOP_LEVEL_STMT_H__
#define __TOP_LEVEL_STMT_H__
#include "Stmt.h"
#include "Lexer\TokenStream.h"

class ComposedStmt : public Stmt
{
public:
    ComposedStmt(TokenStream &TokenStream, const Stmt* parent);
    ~ComposedStmt();
    virtual const StmtKind GetKind() const
    {
        return SK_ComposedStmt;
    }
    virtual const wstring GetName() const;
    virtual bool IsMe() const
    {
        return false;
    }

    void AddChild(Stmt *);
    const vector<Stmt*> GetChildren() const;

protected:
    virtual void Parse();

private:
    vector<Stmt*> children;
};

#endif
