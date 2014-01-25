#ifndef __AST_TREE_H__
#define __AST_TREE_H__
#include "Basic\Common.h"
#include "AstParser\Stmt\Stmt.h"
#include "AstParser\Stmt\TopLevelStmt.h"

class AstTree
{
public:
    AstTree();
    ~AstTree();

public:
    void Print() const;

private:
    TopLevelStmt topLevelStmt;
};
#endif
