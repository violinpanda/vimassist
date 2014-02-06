#include "IncludeStmt.h"

IncludeStmt::IncludeStmt(TokenStream& tokenStream, const Stmt* parent)
    : Stmt(tokenStream, parent)
{
}

const wstring IncludeStmt::GetName() const
{
    wstring name(_T("IncludeStmt: "));
    name += this->includedFile;
    return name;
}

bool IncludeStmt::IsMe() const
{
    int steps = 0;
    return this->tokenStream.FindNextTargetTokenInSameLine(Include, steps) != NULL;
}

Stmt* IncludeStmt::Parse()
{
    this->includedFile.clear();
    bool isIncludedFileInQuota = false;
    int steps = 0;
    if (this->tokenStream.FindNextTargetTokenInSameLine(DoubleQuota, steps) != NULL)
    {
        isIncludedFileInQuota = true;
    }
    else if (this->tokenStream.FindNextTargetTokenInSameLine(Lt, steps) != NULL)
    {
        isIncludedFileInQuota = false;
    }
    const Token* currentToken = this->tokenStream.GotoTokenByRelativePos(steps + 1);
    while (currentToken->GetKind() != DoubleQuota
            && currentToken->GetKind() != Lt
            && currentToken->GetKind() != NewLine)
    {
        this->includedFile += currentToken->GetContent();
        currentToken = this->tokenStream.GotoNextToken();
    }

    return this;
}
