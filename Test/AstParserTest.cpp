// Test.cpp : Defines the entry point for the console application.
//

#include <string>
#include <fstream>
#include <streambuf>
#include "SyntaxParser\Ast\AstParser.h"

void AstParserTest()
{
    AstParser astParser(_T("Test.cpp"));
    ComposedStmt* topLevelStmt = astParser.Parse();
}
