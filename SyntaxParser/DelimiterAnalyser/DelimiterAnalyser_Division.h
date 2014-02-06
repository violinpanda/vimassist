#ifndef __DELIMITER_ANALYSER_DIVISION_H__
#define __DELIMITER_ANALYSER_DIVISION_H__
#include "DelimiterAnalyser.h"

class DelimiterAnalyser_Division : public DelimiterAnalyser
{
public:
	DelimiterAnalyser_Division(TokenKind tokenKind)
		: DelimiterAnalyser(tokenKind)
	{
	}

protected:
    virtual Stmt* InnerAnalyze(TokenStream& tokenStream, const Stmt* parent);
};

#endif

