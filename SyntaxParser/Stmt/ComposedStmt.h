#ifndef __COMPOSED_STMT_H__
#define __COMPOSED_STMT_H__
#include "Stmt.h"
#include "Lexer\TokenStream.h"

class ComposedStmt : public Stmt
{
public:
    ComposedStmt(TokenStream &tokenStream, const Stmt* parent, StmtKind kind)
        : Stmt(tokenStream, parent),
        kind(kind)
    {}
    ~ComposedStmt();

    virtual const StmtKind GetKind() const
    {
        return this->kind;
    }
    virtual const wstring GetName() const;
    virtual bool IsMe() const
    {
        return false;
    }
    virtual Stmt* Parse();

    void AddChild(Stmt *);
    const vector<Stmt*> GetChildren() const;

protected:
    vector<Stmt*> children;

private:
    StmtKind kind;
};

#endif
