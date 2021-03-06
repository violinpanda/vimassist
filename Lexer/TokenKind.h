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

    // modifiers;
    Const,
    Static,
    Virtual,
    Extern,

    // pre-processors;
    IfnDef,
    Define,
    EndIf,
    Include,

    // udt;
    Typedef,
    Class,
    Struct,
    
    // types;
    BuiltInTypeStart,
    Void = BuiltInTypeStart,
    Short,
    Ushort,
    Bool,
    Int,
    Long,
    BuiltInTypeEnd = Long,

    // type casting;
    StaticCast,
    DynamicCast,
    ReinterpretCast,
    ConstCast,
    TypeOf,

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
    TokenKind GetKind(const _TCHAR* token) const;
    TokenKind GetKind(_TCHAR token) const;
    bool IsDelimiter(TokenKind tokenKind) const
    {
        return (tokenKind >= DelimiterStart && tokenKind <= DelimiterEnd);
    }
    bool IsBuiltInType(TokenKind kind) const
    {
        return (kind >= BuiltInTypeStart && kind <= BuiltInTypeEnd);
    }
    bool IsIdentifier(TokenKind kind) const
    {
        return kind == Identifier;
    }

private:
    TokenMatcher();
    void BuildTokenKind2TokenMap();
    void BuildToken2TokenKindMap();

    wstring tokenKind2TokenMap[TokenKindEnd];
    map<wstring, TokenKind> token2TokenKindMap;
};
#endif
