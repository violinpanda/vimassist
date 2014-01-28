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
    virtual const wstring GetName() const;

private:
    vector<Stmt*> children;
};

#endif
