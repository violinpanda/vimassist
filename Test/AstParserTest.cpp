// Test.cpp : Defines the entry point for the console application.
//

#include <string>
#include <fstream>
#include <streambuf>
#include "AstParser\Ast\AstTree.h"
#include "AstParser\Ast\AstParser.h"

void AstParserTest()
{
    AstParser astParser(_T("Test.cpp"));
    const AstTree& astTree = astParser.Parse();
    astTree.Print();
}