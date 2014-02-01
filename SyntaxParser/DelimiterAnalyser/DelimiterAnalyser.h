#ifndef __DELIMITER_ANALYSER_H__
#define __DELIMITER_ANALYSER_H__
#include "Lexer\TokenKind.h"
#include "Lexer\TokenStream.h"
#include "SyntaxParser\Stmt\Stmt.h"

class DelimiterAnalyser
{
public:
    DelimiterAnalyser(TokenKind delimiter);
    Stmt* Analyze(TokenStream& tokenStream, const Stmt* parent);

protected:
    virtual Stmt* InnerAnalyze(TokenStream& tokenStream, const Stmt* parent);
    TokenKind delimiter;
};

#endif
