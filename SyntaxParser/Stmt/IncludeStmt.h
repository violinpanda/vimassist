#ifndef __INCLUDE_STMT_H__
#define __INCLUDE_STMT_H__
#include "Stmt.h"
#include "Lexer\TokenStream.h"

class IncludeStmt : public Stmt
{
public:
    IncludeStmt(TokenStream &TokenStream);
};

#endif

