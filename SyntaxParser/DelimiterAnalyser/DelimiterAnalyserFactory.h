#ifndef __DELIMITER_ANALYSER_FACTORY_H__
#define __DELIMITER_ANALYSER_FACTORY_H__
#include "Basic\Common.h"
#include "Lexer\TokenKind.h"

class DelimiterAnalyserFactory
{
public:
    static const DelimiterAnalyserFactory& GetMe();
    static void Release();
    const Stmt& Analyze(TokenKind tokenKind);

private:
    DelimiterAnalyserFactory();

    static DelimiterAnalyserFactory* s_DelimiterAnalserFactory;
    map<TokenKind, DelimiterAnalyser> factory;
}

#endif
