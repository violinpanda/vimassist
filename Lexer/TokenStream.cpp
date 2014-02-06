#include <fstream>
#include <streambuf>
#include "Lexer\TokenStream.h"
#include "TokenKind.h"
#include "Basic\Location.h"

TokenStream::TokenStream(const wstring path)
    :path(path), currentIndex(0)
{
    this->ParseFile();
}

TokenStream::~TokenStream(void)
{
    for (int i = 0; i < this->tokens.size(); i++)
    {
        delete this->tokens[i];
    }
}

const Token* TokenStream::GotoStart()
{
    this->currentIndex = 0;
    return this->GetToken(this->currentIndex);
}

const Token* TokenStream::GetCurrentToken() const
{
    return this->GetToken(this->currentIndex);
}

const Token* TokenStream::GetTokenByRelativePos(int pos) const
{
    return this->GetToken(this->currentIndex + pos);
}

const Token* TokenStream::GetToken(int index) const
{
    if (index < 0 || index >= this->tokens.size())
    {
        return NULL;
    }
    else
    {
        return this->tokens[index];
    }
}

const Token* TokenStream::GotoNextToken()
{
    this->currentIndex++;
    return this->GetCurrentToken();
}

const Token* TokenStream::GotoPrevToken()
{
    this->currentIndex--;
    return this->GetCurrentToken();
}

const Token* TokenStream::GotoTokenByRelativePos(int pos)
{
    this->currentIndex += pos;
    return this->GetCurrentToken();
}

void TokenStream::ParseFile()
{
    wifstream fileStream(this->path);
    wstring fileStr((istreambuf_iterator<_TCHAR>(fileStream)), istreambuf_iterator<_TCHAR>());
    const TokenMatcher& tokenMatcher = TokenMatcher::GetMe();
    int tokenRow = 1;
    int tokenColumn = 1;
    for (int beginPos, endPos = 0; endPos < fileStr.size(); endPos < fileStr.size())
    {
        // skip whitespaces;
        int spaceCount = 0;
        int tabCount = 0;
        this->SkipWhitespaces(fileStr, endPos, spaceCount, tabCount);

        // match a token;
        beginPos = endPos;
        TokenKind beginPosTokenKind = tokenMatcher.GetKind(fileStr[beginPos]);
        bool isNewLine = false;
        if (tokenMatcher.IsDelimiter(beginPosTokenKind))
        {
            endPos++;
            if (beginPosTokenKind == NewLine)
            {
                isNewLine = true;
            }
        }
        else
        {
            while (!tokenMatcher.IsDelimiter(tokenMatcher.GetKind(fileStr[endPos])))
            {
                endPos++;
            }
        }

        // new token found, add it;
        const int maxCharCountInToken = 128;
        _TCHAR tokenChars[maxCharCountInToken] = { 0 };
        fileStr.copy(tokenChars, endPos - beginPos, beginPos);
        Token *newToken = new Token(tokenChars, Location(tokenRow, tokenColumn));
        this->tokens.push_back(newToken);
#ifdef VaDebug
        wcout <<"[" << tokenRow <<", " <<tokenColumn <<"]" <<"\t\t" <<tokenChars <<endl;
#endif
        tokenColumn = tokenColumn + (endPos - beginPos);

        if (isNewLine)
        {
            tokenRow++;
            tokenColumn = 1;
        }
    }
}

void TokenStream::SkipWhitespaces(const wstring &stream, int &pos, int &spaceCount, int &tabCount)
{
    spaceCount = 0;
    tabCount = 0;

    const TokenMatcher &tokenMatcher = TokenMatcher::GetMe();
    TokenKind tokenKind = tokenMatcher.GetKind(stream[pos]);
    while (tokenKind == Space || tokenKind == Tab)
    {
        if (tokenKind == Space)
        {
            spaceCount++;
        }
        else if (tokenKind == Tab)
        {
            tabCount++;
        }

        pos++;
        tokenKind = tokenMatcher.GetKind(stream[pos]);
    }
}


const Token* TokenStream::FindNextTargetTokenInSameStmt(TokenKind tokenKind, int& steps) const
{
    return this->FindTargetTokenInScope(tokenKind, steps, Forward, SameStmt);
}

const Token* TokenStream::FindNextTargetTokenInSameLine(TokenKind tokenKind, int& steps) const
{
    return this->FindTargetTokenInScope(tokenKind, steps, Forward, SameLine);
}

const Token* TokenStream::FindMatchingBrace(TokenKind originKind, int& steps) const
{
    const int rowCount = 3;
    const int columnCount = 2;
    TokenKind matchingBraceTable[3][2] = 
    {
        { LSmallBrace, RSmallBrace, },
        { LMiddleBrace, RMiddleBrace, },
        { LLargeBrace, RLargeBrace, },
    };

    TokenKind targetKind = TokenKindStart;
    int targetRow = -1;
    int targetColumn = -1;
    TokenSearchDirection direction = Forward;
    bool found = false;
    for (int row = 0; row < rowCount; row++)
    {
        if (found)
        {
            break;
        }

        for (int column = 0; column < columnCount; column++)
        {
            if (matchingBraceTable[row][column] == originKind)
            {
                targetRow = row;
                targetColumn = columnCount - 1 - column;
                targetKind = matchingBraceTable[targetRow][targetColumn];
                if (column == 0)
                {
                    direction = Forward;
                }
                else if (column ==1)
                {
                    direction = Backward;
                }
                found = true;
                break;
            }
        }
    }
    if (!found)
    {
        return NULL;
    }

    int stackSize = 1;
    steps = 0;
    const Token* currentToken = this->GetTokenByRelativePos(steps);
    while (currentToken->GetKind() != Semicolon
            && (originKind == LLargeBrace || originKind == RLargeBrace || (currentToken->GetKind() != LLargeBrace && currentToken->GetKind() != RLargeBrace)))
    {
        if (direction == Forward)
        {
            steps++;
        }
        else if (direction == Backward)
        {
            steps--;
        }
        currentToken = this->GetTokenByRelativePos(steps);
        if (currentToken->GetKind() == originKind)
        {
            stackSize++;
        }
        else if (currentToken->GetKind() == targetKind)
        {
            stackSize--;
        }
        if (stackSize == 0)
        {
            return currentToken;
        }
    }

    return NULL;
}

const Token* TokenStream::GotoMatchingBrace(TokenKind kind)
{
    int steps = 0;
    const Token* matchingBrace = this->FindMatchingBrace(kind, steps);
    if (matchingBrace != NULL && steps != 0)
    {
        this->GotoTokenByRelativePos(steps);
    }
    return matchingBrace;
}

const Token* TokenStream::FindTargetTokenInScope(TokenKind kind, int& steps, TokenSearchDirection direction, TokenSearchScope scope) const
{
    const Token* currentToken = this->GetCurrentToken();
    steps = 0;
    do
    {
        if (direction == Forward)
        {
            currentToken = this->GetTokenByRelativePos(steps + 1);
        }
        else if (direction == Backward)
        {
            currentToken = this->GetTokenByRelativePos(-1 * (steps + 1));
        }
        steps++;
    }
    while (currentToken->GetKind() != kind
        && (scope != SameLine || currentToken->GetKind() != NewLine)
        && (scope != SameStmt || currentToken->GetKind() != RLargeBrace)
        && (scope != SameStmt || currentToken->GetKind() != Semicolon));

    if (currentToken->GetKind() == kind)
    {
        return currentToken;
    }
    else
    {
        return NULL;
    }
}


const Token* TokenStream::GotoNextTargetTokenInSameStmt(TokenKind tokenKind)
{
    int steps = 0;
    const Token* target = this->FindNextTargetTokenInSameStmt(tokenKind, steps);
    if (target != NULL)
    {
        return this->GotoTokenByRelativePos(steps);
    }
    else
    {
        return NULL;
    }
}

const Token* TokenStream::GotoNextTargetTokenInSameLine(TokenKind tokenKind)
{
    int steps = 0;
    const Token* target = this->FindNextTargetTokenInSameLine(tokenKind, steps);
    if (target != NULL)
    {
        return this->GotoTokenByRelativePos(steps);
    }
    else
    {
        return NULL;
    }
}

const Token* TokenStream::GotoEol()
{
    const Token* currentToken = this->GetCurrentToken();
    while (currentToken->GetKind() != NewLine)
    {
        currentToken = this->GotoNextToken();
    }
    return currentToken;
}
