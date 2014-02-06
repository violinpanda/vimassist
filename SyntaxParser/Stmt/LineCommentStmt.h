#ifndef __LINE_COMMENT_STMT_H__
#define __LINE_COMMENT_STMT_H__
#include "SyntaxParser\Stmt\Stmt.h"

class LineCommentStmt : public Stmt
{
public:
    LineCommentStmt(TokenStream &tokenStream, const Stmt* parent)
        : Stmt(tokenStream, parent)
    {
    }
    virtual const StmtKind GetKind() const
    {
        return SK_LineCommentStmt;
    }
    virtual const wstring GetName() const
    {
        return _T("LineCommentStmt");
    }
    virtual bool IsMe() const;
    virtual Stmt* Parse();
};

#endif
