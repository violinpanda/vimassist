#include "DelimiterAnalyser_Sharp.h"
#include "SyntaxParser\Stmt\IncludeStmt.h"

Stmt* DelimiterAnalyser_Sharp::InnerAnalyze(TokenStream& stream)
{
    const Token* nextToken = stream.GetNextToken();
    Stmt* stmt = NULL;
    switch (nextToken->GetKind())
    {
        case Include:
            {
                stmt = new IncludeStmt(stream);
            }
            break;
        default:
            
            break;
    }

    return stmt;
}
