#ifndef __DELIMITER_ANALYSER_H__
#define __DELIMITER_ANALYSER_H__
#include "Lexer\TokenKind.h"
#include "Lexer\TokenStream.h"
#include "SyntaxParser\Stmt\Stmt.h"

class DelimiterAnalyser
{
public:
    DelimiterAnalyser(TokenKind delimiter);
    const Stmt* Analyze(const TokenStream&);

protected:
    virtual const Stmt* InnerAnalyze(const TokenStream&);
    TokenKind delimiter;
};

#endif
