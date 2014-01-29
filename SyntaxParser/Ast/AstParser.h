#ifndef __AST_PARSER_H__
#define __AST_PARSER_H__
#include "SyntaxParser\Stmt\ComposedStmt.h"

class AstParser
{
public:
    AstParser(const wstring file);
    ~AstParser();
    ComposedStmt* Parse();

private:
    TokenStream tokenStream;
    ComposedStmt* topLevelStmt;
};

#endif
