#ifndef __TOP_LEVEL_STMT_H__
#define __TOP_LEVEL_STMT_H__
#include "Stmt.h"
#include "Lexer\TokenStream.h"

class TopLevelStmt : public Stmt
{
public:
    TopLevelStmt(TokenStream &TokenStream);
    ~TopLevelStmt();
    void AddChild(Stmt *);

public:
    virtual const wstring Print(int level) const;
    virtual const wstring ToString() const;

private:
    vector<Stmt*> children;
};

#endif
