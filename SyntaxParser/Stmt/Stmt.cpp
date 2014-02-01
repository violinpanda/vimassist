#include "Stmt.h"

Stmt::Stmt(TokenStream &tokenStream, const Stmt* parent)
    : tokenStream(tokenStream),
    parent(parent)
{}

const Stmt* Stmt::GetParent() const
{
    return this->parent;
}
