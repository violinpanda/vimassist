#ifndef __STMT_H__
#define __STMT_H__
#include "Lexer\SourceFile.h"

class Stmt
{
public:
    Stmt(SourceFile &sourceFile);

public:
    // debug interfaces;
    virtual const wstring Print(int level) const
    {
        return _T("");
    }

    virtual const wstring ToString() const
    {
        return _T("");
    }
};

#endif

