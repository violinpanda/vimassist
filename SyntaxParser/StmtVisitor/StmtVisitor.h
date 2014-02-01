#ifndef __STMT_VISITOR_H__
#define __STMT_VISITOR_H__
#include "SyntaxParser\Stmt\Stmt.h"
#include "SyntaxParser\Stmt\IncludeStmt.h"
#include "SyntaxParser\Stmt\ComposedStmt.h"

class StmtVisitor
{
public:
    void Visit(const Stmt *);

protected:
    int GetDepth(const Stmt&) const;

    virtual void Visit(const IncludeStmt &) = 0;
    virtual void Visit(const ComposedStmt &) = 0;
};

#endif
