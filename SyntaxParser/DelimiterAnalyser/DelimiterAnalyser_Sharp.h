#ifndef __DELIMITER_ANALYSER_SHARP_H__
#define __DELIMITER_ANALYSER_SHARP_H__
#include "DelimiterAnalyser.h"

class DelimiterAnalyser_Sharp
{
    virtual const Stmt* InnerAnalyze(const TokenStream&);
}

#endif
