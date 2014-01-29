#include "DelimiterAnalyserFactory.h"
#include "SyntaxParser\DelimiterAnalyser\DelimiterAnalyser_Sharp.h"
#include "Lexer\TokenKind.h"

DelimiterAnalyserFactory* DelimiterAnalyserFactory::s_DelimiterAnalyserFactory = NULL;

DelimiterAnalyserFactory& DelimiterAnalyserFactory::GetMe()
{
    if (s_DelimiterAnalyserFactory == NULL)
    {
        s_DelimiterAnalyserFactory = new DelimiterAnalyserFactory();
    }

    return *s_DelimiterAnalyserFactory;
}

void DelimiterAnalyserFactory::Release()
{
    delete s_DelimiterAnalyserFactory;
}

DelimiterAnalyserFactory::DelimiterAnalyserFactory()
{
    this->factory[Sharp] = new DelimiterAnalyser(Sharp);
}

Stmt* DelimiterAnalyserFactory::Analyze(TokenKind tokenKind, TokenStream &tokenStream)
{
    return this->factory[tokenKind]->Analyze(tokenStream);
}
