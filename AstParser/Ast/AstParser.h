#ifndef __AST_PARSER_H__
#define __AST_PARSER_H__
#include "AstParser\Ast\AstTree.h"

class AstParser
{
public:
    AstParser(const wstring file);
    ~AstParser();
    const AstTree& Parse();

private:
    const Stmt* OnSharpMet();
    SourceFile sourceFile;
    AstTree astTree;
};

#endif
