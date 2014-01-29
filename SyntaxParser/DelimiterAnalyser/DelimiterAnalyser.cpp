#include <assert.h>
#include "DelimiterAnalyser.h"

DelimiterAnalyser::DelimiterAnalyser(TokenKind delimiter)
    : delimiter(delimiter)
{
}

Stmt* DelimiterAnalyser::Analyze(TokenStream& tokenStream)
{
    if (tokenStream.GetCurrentToken()->GetKind() != this->delimiter)
    {
        char errMsg[128] = { 0 };
        sprintf(errMsg, "DelimiterAnalyser can only analyze the specified delimiter, TokenKind = %d", this->delimiter);
    }

    return this->InnerAnalyze(tokenStream);
}

Stmt* DelimiterAnalyser::InnerAnalyze(TokenStream&)
{
	return NULL;
}
