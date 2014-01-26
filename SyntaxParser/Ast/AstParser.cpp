#include "Lexer\Token.h"
#include "Lexer\TokenKind.h"
#include "Lexer\TokenStream.h"
#include "AstParser.h"
#include "SyntaxParser\Stmt\IncludeStmt.h"

AstParser::AstParser(const wstring file)
    : TokenStream(file)
{}

AstParser::~AstParser()
{}

const TopLevelStmt& AstParser::Parse()
{
    this->TokenStream.GotoStart();
    const Token *token = TokenStream.GetCurrentToken();
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
        token = TokenStream.MoveToNextToken();
    }

    return *(this->topLevelStmt);
}

const Stmt* AstParser::OnSharpMet()
{
    if (TokenStream.GetNextToken()->GetKind() == Include)
    {
        return new IncludeStmt(TokenStream);
    }
}

