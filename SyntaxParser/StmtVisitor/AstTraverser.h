#ifndef __AST_TRAVERSER_H__
#define __AST_TRAVERSER_H__

class AstTraverser : public StmtVisitor
{
protected:
    virtual void Visit(IncludeStmt *);
    virtual void Visit(ComposedStmt *);
}

#endif
