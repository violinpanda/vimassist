#include "Lexer\TokenKind.h"
#include "DelimiterAnalyserFactory.h"
#include "SyntaxParser\DelimiterAnalyser\DelimiterAnalyser_Sharp.h"
#include "SyntaxParser\DelimiterAnalyser\DelimiterAnalyser_Division.h"
#include "SyntaxParser\DelimiterAnalyser\DelimiterAnalyser_LSmallBrace.h"


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
    this->factory[Sharp] = new DelimiterAnalyser_Sharp(Sharp);
    this->factory[Division] = new DelimiterAnalyser_Division(Division);
    this->factory[LSmallBrace] = new DelimiterAnalyser_LSmallBrace(LSmallBrace);
}

DelimiterAnalyserFactory::~DelimiterAnalyserFactory()
{
    map<TokenKind, DelimiterAnalyser*>::const_iterator it = this->factory.begin();
    while (it != this->factory.end())
    {
        delete it->second;
    }
    this->factory.clear();
}

Stmt* DelimiterAnalyserFactory::Analyze(TokenKind tokenKind, TokenStream &tokenStream, const Stmt* parent)
{
    map<TokenKind, DelimiterAnalyser*>::const_iterator it = this->factory.find(tokenKind);
    if (it != this->factory.cend())
    {
        return this->factory[tokenKind]->Analyze(tokenStream, parent);
    }
    return NULL;
}
