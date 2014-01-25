#ifndef __INCLUDE_STMT_H__
#define __INCLUDE_STMT_H__
#include "Stmt.h"

class IncludeStmt : public Stmt
{
public:
    IncludeStmt(SourceFile sourceFile);
};

#endif

