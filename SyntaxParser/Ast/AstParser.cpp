#include "Lexer\Token.h"
#include "Lexer\TokenKind.h"
#include "Lexer\TokenStream.h"
#include "AstParser.h"
#include "SyntaxParser\Stmt\IncludeStmt.h"
#include "SyntaxParser\DelimiterAnalyser\DelimiterAnalyserFactory.h"

AstParser::AstParser(const wstring file)
    : tokenStream(file),
    topLevelStmt(new ComposedStmt(tokenStream, NULL))
{}

AstParser::~AstParser()
{
    delete this->topLevelStmt;
}

ComposedStmt* AstParser::Parse()
{
    this->tokenStream.GotoStart();
    const Token *token = this->tokenStream.GetCurrentToken();
    while (token != NULL)
    {
        Stmt* stmt = DelimiterAnalyserFactory::GetMe().Analyze(token->GetKind(), this->tokenStream, this->topLevelStmt);
        if (stmt != NULL)
        {
            this->topLevelStmt->AddChild(stmt);
        }
        token = this->tokenStream.GotoNextToken();
    }

    return this->topLevelStmt;
}
