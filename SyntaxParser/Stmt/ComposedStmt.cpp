#include "ComposedStmt.h"

ComposedStmt::~ComposedStmt()
{
    for (int index = 0; index < this->children.size(); index++)
    {
        delete this->children[index];
    }
    this->children.clear();
}

void ComposedStmt::AddChild(Stmt* child)
{
    this->children.push_back(child);
}

const vector<Stmt*> ComposedStmt::GetChildren() const
{
    return this->children;
}

const wstring ComposedStmt::GetName() const
{
    return _T("ComposedStmt");
}

Stmt* ComposedStmt::Parse()
{
    return NULL;
}

