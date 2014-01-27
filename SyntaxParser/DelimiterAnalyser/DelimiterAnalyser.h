#ifndef __DELIMITER_ANALYSER_H__
#define __DELIMITER_ANALYSER_H__

class DelimiterAnalyser
{
public:
    virtual const Stmt& Analyze(const TokenStream&) = 0;
}

#endif
