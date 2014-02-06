#include "SyntaxParser\Stmt\LineCommentStmt.h"
#include "Lexer\TokenKind.h"

bool LineCommentStmt::IsMe() const
{
    return this->tokenStream.GetCurrentToken()->GetKind() == Division
        && this->tokenStream.GetTokenByRelativePos(1)->GetKind() == Division;
}

Stmt* LineCommentStmt::Parse()
{
    this->tokenStream.GotoEol();
    return this;
}
