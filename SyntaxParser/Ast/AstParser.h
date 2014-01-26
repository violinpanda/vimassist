#ifndef __AST_PARSER_H__
#define __AST_PARSER_H__
#include "SyntaxParser\Stmt\TopLevelStmt.h"

class AstParser
{
public:
    AstParser(const wstring file);
    ~AstParser();
    const TopLevelStmt& Parse();

private:
    const Stmt* OnSharpMet();
    TokenStream TokenStream;
    TopLevelStmt* topLevelStmt;
};

#endif
