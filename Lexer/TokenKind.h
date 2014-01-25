#ifndef __TOKEN_KIND_H__
#define __TOKEN_KIND_H__
#include "Basic\Common.h"
#include <map>
#include "Token.h"
#include <string>

enum TokenKind
{
    TokenKindStart,

    // flow control;
    If,
    Else,
    While,
    Do,

    // accessibility;
    Public,
    Private,
    Protected,

    // 
    Const,
    Static,

    // pre-processors;
    IfnDef,
    Define,
    EndIf,

    // types;
    Typedef,
    Int,
    Long,
    Short,
    Ushort,
    Class,
    Struct,

    // delimiter start;
    DelimiterStart,
    Comma = DelimiterStart,
    Semicolon,
    Dot,
    Space,
    Tab,
    NewLine,
    LSmallBrace,
    RSmallBrace,
    LMiddleBrace,
    RMiddleBrace,
    LLargeBrace,
    RLargeBrace,
    Sharp,
    BackSlash,
    Colon,
    DoubleQuota,
    SingleQuota,

    LineCommenter,
    BlockCommenterBegin,
    BlockCommenterEnd,

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
    // delimiter end;

    AndAnd,
    OrOr,

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
    TokenKind GetTokenKind(const _TCHAR* token) const;
    TokenKind GetTokenKind(_TCHAR token) const;
    bool IsDelimiterToken(TokenKind tokenKind) const;

private:
    TokenMatcher();
    void BuildTokenKind2TokenMap();
    void BuildToken2TokenKindMap();

    wstring tokenKind2TokenMap[TokenKindEnd];
    map<wstring, TokenKind> token2TokenKindMap;
};
#endif
