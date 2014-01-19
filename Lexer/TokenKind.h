#ifndef __TOKEN_KIND_H__
#define __TOKEN_KIND_H__
#include "Basic\Common.h"
#include <map>
#include "Token.h"
#include <string>

enum TokenKind
{
    TokenKindStart,

    If,
    Else,
    While,
    Do,

    Public,
    Private,
    Protected,
    Const,

    Typedef,
    Int,
    Long,
    Short,
    Ushort,
    Class,
    Struct,

    Sharp,
    // delimiter start;
    DelimiterStart,
    Comma = DelimiterStart,
    Semicolon,
    Dot,
    Space,
    Tab,
    NewLine,
    LParenthesis,
    RParenthesis,
    LBracket,
    RBracket,
    LBrace,
    RBrace,

    Plus,
    Minus,
    Multiple,
    Division,
    Gt,
    Lt,
    QuestionMark,
    Bang,
    And,
    Or,
    DelimiterEnd = Or,
    AndAnd,
    OrOr,
    // delimiter end;

    Identifier,

    TokenKindEnd,
};

class TokenMatcher
{
public:
    static TokenMatcher* s_TokenMatcher;
    static const TokenMatcher& GetMe();
    static void Release();

    ~TokenMatcher();
    TokenKind Match(const _TCHAR* token) const;
    bool IsDelimiterChar(_TCHAR c) const;

private:
    TokenMatcher();
    void BuildTokenKind2TokenMap();
    void BuildToken2TokenKindMap();

    wstring tokenKind2TokenMap[TokenKindEnd];
    map<wstring, TokenKind> token2TokenKindMap;
};
#endif
