#ifndef __TOP_LEVEL_STMT_H__
#define __TOP_LEVEL_STMT_H__
#include "Stmt.h"
#include "Lexer\TokenStream.h"

class ComposedStmt : public Stmt
{
public:
    ComposedStmt(TokenStream &TokenStream, const Stmt* parent);
    ~ComposedStmt();
    virtual const wstring GetName() const;

    void AddChild(Stmt *);
    const vector<Stmt> GetChildren() const;

private:
    vector<Stmt*> children;
};

#endif
