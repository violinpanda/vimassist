#include "DelimiterAnalyserFactory.h"

static DelimiterAnalyserFactory* DelimiterAnalyserFactory::s_DelimiterAnalserFactory = NULL;

static const DelimiterAnalyserFactory& GetMe()
{
    if (s_DelimiterAnalserFactory == NULL)
    {
        s_DelimiterAnalserFactory = new DelimiterAnalyserFactory();
    }

    return *s_DelimiterAnalserFactory;
}

static const void Release()
{
    delete s_DelimiterAnalserFactory;
}

DelimiterAnalyserFactory::DelimiterAnalyserFactory()
{
    this->factory[Sharp] = DelimiterAnalyser_Sharp();
}

const Stmt& DelimiterAnalyserFactory::Analyze(TokenKind tokenKind)
{
    return this->factory[tokenKind].Analyze();
}
