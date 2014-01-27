#include "DelimiterAnalyserFactory.h"

DelimiterAnalyserFactory::DelimiterAnalyserFactory()
{
    this->factory[Sharp] = DelimiterAnalyser_Sharp();
}
