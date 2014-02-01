#ifndef __DELIMITER_ANALYSER_FACTORY_H__
#define __DELIMITER_ANALYSER_FACTORY_H__
#include "Basic\Common.h"
#include "Lexer\TokenKind.h"
#include "SyntaxParser\Stmt\Stmt.h"
#include "SyntaxParser\DelimiterAnalyser\DelimiterAnalyser.h"

class DelimiterAnalyserFactory
{
public:
    static DelimiterAnalyserFactory& GetMe();
    static void Release();
    Stmt* Analyze(TokenKind tokenKind, TokenStream &tokenStream, const Stmt* parent);

private:
    DelimiterAnalyserFactory();
    ~DelimiterAnalyserFactory();

    static DelimiterAnalyserFactory* s_DelimiterAnalyserFactory;
    map<TokenKind, DelimiterAnalyser*> factory;
};

#endif
