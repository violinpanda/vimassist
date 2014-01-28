#include "IncludeStmt.h"

IncludeStmt::IncludeStmt(TokenStream& tokenStream)
    : Stmt(tokenStream)
{
}

const wstring IncludeStmt::GetName() const
{
	return _T("IncludeStmt");
}
