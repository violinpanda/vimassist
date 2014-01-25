#include "SourceFile.h"
#include <fstream>
#include <streambuf>
#include "TokenKind.h"
#include "SourceLocation.h"

SourceFile::SourceFile(const wstring path)
    :path(path), currentIndex(0)
{
    this->ParseFile();
}

SourceFile::~SourceFile(void)
{
    for (int i = 0; i < this->tokens.size(); i++)
    {
        delete this->tokens[i];
    }
}

const Token* SourceFile::GotoStart()
{
    this->currentIndex = 0;
    return this->GetToken(this->currentIndex);
}

const Token* SourceFile::GetCurrentToken()
{
    return this->GetToken(this->currentIndex);
}

const Token* SourceFile::GetNextToken()
{
    return this->GetToken(this->currentIndex + 1);
}

const Token* SourceFile::GetPrevToken()
{
    return this->GetToken(this->currentIndex - 1);
}

const Token* SourceFile::GetToken(int index)
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

const Token* SourceFile::MoveToNextToken()
{
    this->currentIndex++;
    return this->GetCurrentToken();
}

const Token* SourceFile::MoveToPrevToken()
{
    this->currentIndex--;
    return this->GetCurrentToken();
}

void SourceFile::ParseFile()
{
    wifstream fileStream(this->path);
    wstring fileStr((istreambuf_iterator<_TCHAR>(fileStream)), istreambuf_iterator<_TCHAR>());
    const TokenMatcher& tokenMatcher = TokenMatcher::GetMe();
    int tokenRow = 1;
    int tokenColumn = 1;
    const int spaceWidth = 1;
    const int tabWidth = 4;
    for (int beginPos, endPos = 0; endPos < fileStr.size(); endPos < fileStr.size())
    {
        // skip whitespaces;
        int spaceCount, tabCount = 0;
        this->SkipWhitespaces(fileStr, endPos, spaceCount, tabCount);
        tokenColumn = tokenColumn + spaceCount * spaceWidth + tabCount * tabWidth;

        // match a token;
        beginPos = endPos;
        TokenKind beginPosTokenKind = tokenMatcher.GetTokenKind(fileStr[beginPos]);
        bool isNewLineHit = false;
        if (tokenMatcher.IsDelimiterToken(beginPosTokenKind))
        {
            endPos++;
            if (beginPosTokenKind == NewLine)
            {
                isNewLineHit = true;
            }
        }
        else
        {
            while (!tokenMatcher.IsDelimiterToken(tokenMatcher.GetTokenKind(fileStr[endPos])))
            {
                endPos++;
            }
        }

        // new token found, add it;
        const int maxCharCountInToken = 128;
        _TCHAR tokenChars[maxCharCountInToken] = { 0 };
        fileStr.copy(tokenChars, endPos - beginPos, beginPos);
        Token *newToken = new Token(tokenChars, SourceLocation(tokenRow, tokenColumn));
        this->tokens.push_back(newToken);
#ifdef VaDebug
        wcout <<"[" << tokenRow <<", " <<tokenColumn <<"]" <<"\t\t" <<tokenChars <<endl;
#endif
        tokenColumn = tokenColumn + (endPos - beginPos);

        if (isNewLineHit)
        {
            tokenRow++;
            tokenColumn = 1;
        }
    }
}

void SourceFile::SkipWhitespaces(const wstring &stream, int &pos, int &spaceCount, int &tabCount)
{
    spaceCount = 0;
    tabCount = 0;

    const TokenMatcher &tokenMatcher = TokenMatcher::GetMe();
    TokenKind tokenKind = tokenMatcher.GetTokenKind(stream[pos]);
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
        tokenKind = tokenMatcher.GetTokenKind(stream[pos]);
    }
}
