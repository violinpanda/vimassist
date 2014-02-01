#include <assert.h>
#include "DelimiterAnalyser.h"

DelimiterAnalyser::DelimiterAnalyser(TokenKind delimiter)
    : delimiter(delimiter)
{
}

Stmt* DelimiterAnalyser::Analyze(TokenStream& tokenStream, const Stmt* parent)
{
    if (tokenStream.GetCurrentToken()->GetKind() != this->delimiter)
    {
        char errMsg[128] = { 0 };
        sprintf(errMsg, "DelimiterAnalyser can only analyze the specified delimiter, TokenKind = %d", this->delimiter);
    }

    return this->InnerAnalyze(tokenStream, parent);
}

Stmt* DelimiterAnalyser::InnerAnalyze(TokenStream& tokenStream, const Stmt* parent)
{
	return NULL;
}
