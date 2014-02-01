#ifndef __DELIMITER_ANALYSER_SHARP_H__
#define __DELIMITER_ANALYSER_SHARP_H__
#include "DelimiterAnalyser.h"

class DelimiterAnalyser_Sharp : public DelimiterAnalyser
{
public:
	DelimiterAnalyser_Sharp(TokenKind tokenKind)
		: DelimiterAnalyser(tokenKind)
	{
	}

protected:
    virtual Stmt* InnerAnalyze(TokenStream& tokenStream, const Stmt* parent);
};

#endif
