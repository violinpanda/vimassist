#include "DelimiterAnalyser_Sharp.h"
#include "SyntaxParser\Stmt\IncludeStmt.h"

Stmt* DelimiterAnalyser_Sharp::InnerAnalyze(TokenStream& stream, const Stmt* parent)
{
    Stmt* stmt = NULL;
    if (IncludeStmt(stream, parent).IsMe())
    {
        stmt = (new IncludeStmt(stream, parent))->Parse();
    }

    return stmt;
}

