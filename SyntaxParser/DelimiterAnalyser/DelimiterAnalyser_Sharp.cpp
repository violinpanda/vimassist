#include "DelimiterAnalyser_Sharp.h"

virtual const Stmt* DelimiterAnalyser_Sharp::InnerAnalyze(const TokenStream& stream)
{
    const Token& nextToken = stream.GetNextToken();
    Stmt* stmt = NULL;
    switch (nextToken.GetTokenKind())
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
