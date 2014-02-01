#ifndef __AST_TRAVERSER_H__
#define __AST_TRAVERSER_H__
#include "SyntaxParser\StmtVisitor\StmtVisitor.h"

class AstPrinter : public StmtVisitor
{
protected:
    virtual void Visit(const IncludeStmt &);
    virtual void Visit(const ComposedStmt &);
    
private:
    const wstring Print(const Stmt&) const;
};

#endif
