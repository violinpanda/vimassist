#ifndef __STMT_VISITOR_H__
#define __STMT_VISITOR_H__
#include "SyntaxParser\Stmt\Stmt.h"
#include "SyntaxParser\Stmt\IncludeStmt.h"
#include "SyntaxParser\Stmt\ComposedStmt.h"

class StmtVisitor
{
public:
    void Visit(Stmt *);

protected:
    virtual void Visit(IncludeStmt *);
    virtual void Visit(ComposedStmt *);
};

#endif
