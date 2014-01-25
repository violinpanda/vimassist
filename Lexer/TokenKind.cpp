#include "TokenKind.h"

TokenMatcher* TokenMatcher::s_TokenMatcher = NULL;

const TokenMatcher& TokenMatcher::GetMe()
{
    if (s_TokenMatcher == NULL)
    {
        s_TokenMatcher = new TokenMatcher();
    }

    return *s_TokenMatcher;
}

void TokenMatcher::Release()
{
    delete s_TokenMatcher;
}

TokenMatcher::TokenMatcher()
{
    this->BuildTokenKind2TokenMap();
    this->BuildToken2TokenKindMap();
}

TokenMatcher::~TokenMatcher()
{}

void TokenMatcher::BuildTokenKind2TokenMap()
{
    this->tokenKind2TokenMap[If] = _T("if");
    this->tokenKind2TokenMap[Else] = _T("else");
    this->tokenKind2TokenMap[While] = _T("while");
    this->tokenKind2TokenMap[Do] = _T("do");
    this->tokenKind2TokenMap[Public] = _T("public");
    this->tokenKind2TokenMap[Private] = _T("private");
    this->tokenKind2TokenMap[Protected] = _T("protected");
    this->tokenKind2TokenMap[Const] = _T("const");
    this->tokenKind2TokenMap[Typedef] = _T("typedef");
    this->tokenKind2TokenMap[Int] = _T("int");
    this->tokenKind2TokenMap[Long] = _T("long");
    this->tokenKind2TokenMap[Short] = _T("short");
    this->tokenKind2TokenMap[Ushort] = _T("ushort");
    this->tokenKind2TokenMap[Class] = _T("class");
    this->tokenKind2TokenMap[Struct] = _T("struct");
    this->tokenKind2TokenMap[Comma] = _T(",");
    this->tokenKind2TokenMap[Semicolon] = _T(";");
    this->tokenKind2TokenMap[Dot] = _T(".");
    this->tokenKind2TokenMap[Space] = _T(" ");
    this->tokenKind2TokenMap[Tab] = _T("\t");
    this->tokenKind2TokenMap[NewLine] = _T("\n");
    this->tokenKind2TokenMap[Plus] = _T("+");
    this->tokenKind2TokenMap[Minus] = _T("-");
    this->tokenKind2TokenMap[Multiple] = _T("*");
    this->tokenKind2TokenMap[Division] = _T("/");
    this->tokenKind2TokenMap[Gt] = _T(">");
    this->tokenKind2TokenMap[Lt] = _T("<");
    this->tokenKind2TokenMap[And] = _T("&");
    this->tokenKind2TokenMap[Sharp] = _T("#");
    this->tokenKind2TokenMap[Bang] = _T("!");
    this->tokenKind2TokenMap[QuestionMark] = _T("?");
    this->tokenKind2TokenMap[Or] = _T("|");
    this->tokenKind2TokenMap[AndAnd] = _T("&&");
    this->tokenKind2TokenMap[OrOr] = _T("||");
    this->tokenKind2TokenMap[LSmallBrace] = _T("(");
    this->tokenKind2TokenMap[RSmallBrace] = _T(")");
    this->tokenKind2TokenMap[LMiddleBrace] = _T("[");
    this->tokenKind2TokenMap[RMiddleBrace] = _T("]");
    this->tokenKind2TokenMap[LLargeBrace] = _T("{");
    this->tokenKind2TokenMap[RLargeBrace] = _T("}");
    this->tokenKind2TokenMap[BackSlash] = _T("\\");
    this->tokenKind2TokenMap[LineCommenter] = _T("//");
    this->tokenKind2TokenMap[BlockCommenterBegin] = _T("/*");
    this->tokenKind2TokenMap[BlockCommenterEnd] = _T("*/");
    this->tokenKind2TokenMap[Static] = _T("static");
    this->tokenKind2TokenMap[IfnDef] = _T("ifndef");
    this->tokenKind2TokenMap[Define] = _T("define");
    this->tokenKind2TokenMap[EndIf] = _T("endif");
    this->tokenKind2TokenMap[Colon] = _T(":");
    this->tokenKind2TokenMap[DoubleQuota] = _T("\"");
    this->tokenKind2TokenMap[SingleQuota] = _T("\'");
    this->tokenKind2TokenMap[Include] = _T("include");
}

void TokenMatcher::BuildToken2TokenKindMap()
{
    for (int kind = TokenKindStart + 1; kind < TokenKindEnd; kind++)
    {
        wstring token = this->tokenKind2TokenMap[kind];
        if (token.length() == 0 && kind != Identifier)
        {
            char errMsg[128] = { 0 };
            sprintf(errMsg, "Token has no content, TokenKind = %d", kind);
            assert(false, errMsg);
        }
        this->token2TokenKindMap[token] = (TokenKind) kind;
    }
}

TokenKind TokenMatcher::GetTokenKind(const _TCHAR* token) const
{
    map<wstring, TokenKind>::const_iterator it = this->token2TokenKindMap.find(token);
    if (it != this->token2TokenKindMap.cend())
    {
        return it->second;
    }
    else
    {
        return Identifier;
    }
}

TokenKind TokenMatcher::GetTokenKind(_TCHAR token) const
{
    TCHAR tokenStr[2] = { token, 0 };
    return this->GetTokenKind(tokenStr);
}

bool TokenMatcher::IsDelimiterToken(TokenKind tokenKind) const
{
    return (tokenKind >= DelimiterStart && tokenKind <= DelimiterEnd);
}

