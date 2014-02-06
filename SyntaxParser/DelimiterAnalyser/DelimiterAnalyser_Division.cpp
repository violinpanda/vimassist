#include "DelimiterAnalyser_Division.h"
#include "SyntaxParser\Stmt\LineCommentStmt.h"

Stmt* DelimiterAnalyser_Division::InnerAnalyze(TokenStream& stream, const Stmt* parent)
{
    Stmt* stmt = NULL;
    if (LineCommentStmt(stream, parent).IsMe())
    {
        stmt = (new LineCommentStmt(stream, parent))->Parse();
        delete stmt;
        stmt = NULL;
    }

    return stmt;
}
