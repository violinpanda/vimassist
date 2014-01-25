#include "AstParser.h"
#include "Lexer\SourceFile.h"
#include "Lexer\Token.h"
#include "Lexer\TokenKind.h"
#include "AstParser\Stmt\IncludeStmt.h"

AstParser::AstParser(const wstring file)
    : sourceFile(file)
{
}

const AstTree* AstParser::Parse()
{
    this->sourceFile.GotoStart();
    const Token *token = sourceFile.GetCurrentToken();
    while (token != NULL)
    {
        // process token;
        switch (token->GetKind())
        {
            case Sharp:
                this->OnSharpMet();
                break;
            case LSmallBrace:
                {

                }
                break;
            default:
                break;
        }

        // get next token;
        token = sourceFile.MoveToNextToken();
    }
}

const Stmt* AstParser::OnSharpMet()
{
    if (sourceFile.GetNextToken()->GetKind() == Include)
    {
        return new IncludeStmt(sourceFile);
    }
}

