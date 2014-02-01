// Test.cpp : Defines the entry point for the console application.
//

#include <string>
#include <fstream>
#include <streambuf>
#include "SyntaxParser\Ast\AstParser.h"
#include "SyntaxParser\StmtVisitor\AstPrinter.h"

void AstParserTest()
{
    AstParser astParser(_T("D:\\Projects\\Compilers\\VimAssist\\Test\\Test.cpp"));
    const Stmt* topLevelStmt = astParser.Parse();

    StmtVisitor* astPrinter = new AstPrinter();
    astPrinter->Visit(topLevelStmt);
    delete astPrinter;
}
