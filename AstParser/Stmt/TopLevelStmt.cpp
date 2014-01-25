#include "TopLevelStmt.h"

TopLevelStmt::~TopLevelStmt()
{
    for (int index = 0; index < this->children.size(); index++)
    {
        delete this->children[index];
    }
}

void TopLevelStmt::AddChild(Stmt* child)
{
    this->children.push_back(child);
}

const wstring TopLevelStmt::Print(int level) const
{
    wstring result = NULL;
    wstring printSelf = this->ToString() + NewLineStr;
    result = printSelf;
    for (int index = 0; index < this->children.size(); index++)
    {
        wstring printChild = this->children[index]->Print(level + 1);
        result += printChild;
    }

    return result;
}

const wstring TopLevelStmt::ToString() const
{
    return _T("TopLevelStmt");
}
