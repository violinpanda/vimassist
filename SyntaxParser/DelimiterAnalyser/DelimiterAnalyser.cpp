#include <assert.h>
#include "DelimiterAnalyser.h"

DelimiterAnalyser::DelimiterAnalyser(TokenKind delimiter)
    : delimiter(delimiter)
{
}

const Stmt* DelimiterAnalyser::Analyze(const TokenStream& tokenStream)
{
    if (tokenStream.GetCurrentToken()->GetKind() != this->delimiter)
    {
        char errMsg[128] = { 0 };
        sprintf(errMsg, "DelimiterAnalyser can only analyze the specified delimiter, TokenKind = %d", this->delimiter);
    }

    return this->InnerAnalyze(tokenStream);
}

const Stmt* DelimiterAnalyser::InnerAnalyze(const TokenStream&)
{
	return NULL;
}
