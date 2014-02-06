#include "FuncDefStmt.h"

const wstring FuncDefStmt::GetName() const
{
    wstring name(_T("FuncDefStmt: "));
    return name;
}

bool FuncDefStmt::IsMe() const
{
    if (this->parent->GetKind() != SK_TopLevelStmt
            && this->parent->GetKind() != SK_ClassStmt)
    {
        return false;
    }

    // func name check;
    const Token* funcName = this->tokenStream.GetTokenByRelativePos(-1);
    if (funcName->GetKind() != Identifier)
    {
        return false;
    }

    // return value check;
    int i = -2;
    const Token* funcRetType = this->tokenStream.GetTokenByRelativePos(i);
    while (funcRetType->GetKind() == Multiple || funcRetType->GetKind() == And)
    {
        i--;
        funcRetType = this->tokenStream.GetTokenByRelativePos(i);
    }
    if (!TokenMatcher::GetMe().IsBuiltInType(funcRetType->GetKind())
            && funcRetType->GetKind() != Identifier)
    {
        return false;
    }

    // parameter check;
    int steps = 0;
    this->tokenStream.FindMatchingBrace(LSmallBrace, steps);
    if (steps == 0)
    {
        return false;
    }

    // func body check;
    steps++;
    const Token* currentToken = this->tokenStream.GetTokenByRelativePos(steps);
    while (currentToken->GetKind() == Identifier
            || currentToken->GetKind() == Const
            || currentToken->GetKind() == NewLine)
    {
        steps++;
        currentToken = this->tokenStream.GetTokenByRelativePos(steps);
    }
    if (currentToken->GetKind() == LLargeBrace)
    {
        return true;
    }

    return false;
}

Stmt* FuncDefStmt::Parse()
{
    this->ParseFuncName();
    this->ParseFuncParams();
    this->ParseFuncBody();
    return this;
}

void FuncDefStmt::ParseFuncName()
{
    const Token* funcName = this->tokenStream.GetTokenByRelativePos(-1);
    this->funcName = funcName->GetContent();
}

void FuncDefStmt::ParseFuncParams()
{
}

void FuncDefStmt::ParseFuncBody()
{

}
