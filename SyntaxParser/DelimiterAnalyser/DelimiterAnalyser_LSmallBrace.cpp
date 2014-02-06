#include "DelimiterAnalyser_LSmallBrace.h"
#include "SyntaxParser\Stmt\FuncDefStmt.h"

Stmt* DelimiterAnalyser_LSmallBrace::InnerAnalyze(TokenStream& stream, const Stmt* parent)
{
    Stmt* stmt = NULL;
    if (FuncDefStmt(stream, parent).IsMe())
    {
        stmt = (new FuncDefStmt(stream, parent))->Parse();
    }

    return stmt;
}

