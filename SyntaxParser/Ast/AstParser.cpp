#include "Lexer\Token.h"
#include "Lexer\TokenKind.h"
#include "Lexer\TokenStream.h"
#include "AstParser.h"
#include "SyntaxParser\Stmt\IncludeStmt.h"
#include "SyntaxParser\DelimiterAnalyser\DelimiterAnalyserFactory.h"

AstParser::AstParser(const wstring file)
    : tokenStream(file)
{}

AstParser::~AstParser()
{}

const TopLevelStmt& AstParser::Parse()
{
    this->tokenStream.GotoStart();
    const Token *token = this->tokenStream.GetCurrentToken();
    while (token != NULL)
    {
		const Stmt& stmt = DelimiterAnalyserFactory::GetMe().Analyze(token->GetKind());
        this->topLevelStmt.AddChild(stmt);
        token = this->tokenStream.MoveToNextToken();
    }

    return *(this->topLevelStmt);
}

