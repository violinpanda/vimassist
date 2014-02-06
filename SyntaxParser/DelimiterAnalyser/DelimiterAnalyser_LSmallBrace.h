#ifndef __DELIMITER_L_SMALL_BRACE_H__
#define __DELIMITER_L_SMALL_BRACE_H__
#include "DelimiterAnalyser.h"

class DelimiterAnalyser_LSmallBrace : public DelimiterAnalyser
{
public:
	DelimiterAnalyser_LSmallBrace(TokenKind tokenKind)
		: DelimiterAnalyser(tokenKind)
	{
	}

protected:
    virtual Stmt* InnerAnalyze(TokenStream& tokenStream, const Stmt* parent);
};

#endif
