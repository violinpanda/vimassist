#include "SourceFile.h"
#include <fstream>
#include <streambuf>
#include "TokenKind.h"

SourceFile::SourceFile(const string path)
    :path(path)
{
    this-> ParseFile();
}

SourceFile::~SourceFile(void)
{
    for (int i = 0; i < this->tokens.size(); i++)
    {
        delete this->tokens[i];
    }
}

void SourceFile::ParseFile()
{
    wifstream fileStream(this->path);
    wstring fileStr((istreambuf_iterator<_TCHAR>(fileStream)), istreambuf_iterator<_TCHAR>());
    const TokenMatcher& tokenMatcher = TokenMatcher::GetMe();
    for (int beginPos, endPos = 0; endPos < fileStr.size();)
    {
        beginPos = endPos;
        TokenKind beginPosTokenKind = tokenMatcher.GetTokenKind(fileStr[beginPos]);
        if (tokenMatcher.IsDelimiterToken(beginPosTokenKind))
        {
            endPos++;
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
        Token* newToken = new Token(tokenChars);
        this->tokens.push_back(newToken);
        wcout <<tokenChars <<endl;
    }
}
