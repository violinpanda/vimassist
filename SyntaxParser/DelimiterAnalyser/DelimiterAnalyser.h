#ifndef __DELIMITER_ANALYSER_H__
#define __DELIMITER_ANALYSER_H__
#include "Lexer\TokenKind.h"
#include "Lexer\TokenStream.h"
#include "SyntaxParser\Stmt\Stmt.h"

class DelimiterAnalyser
{
public:
    DelimiterAnalyser(TokenKind delimiter);
    Stmt* Analyze(TokenStream&);

protected:
    virtual Stmt* InnerAnalyze(TokenStream&);
    TokenKind delimiter;
};

#endif
