#include "ComposedStmt.h"

ComposedStmt::ComposedStmt(TokenStream &tokenStream, const Stmt* parent)
	: Stmt(tokenStream, parent)
{}

ComposedStmt::~ComposedStmt()
{
    for (int index = 0; index < this->children.size(); index++)
    {
        delete this->children[index];
    }
}

void ComposedStmt::AddChild(Stmt* child)
{
    this->children.push_back(child);
}

const vector<Stmt> ComposedStmt::GetChildren() const
{
    return this->children;
}

//const wstring ComposedStmt::Print(int level) const
//{
//    wstring result = NULL;
//    wstring printSelf = this->ToString() + NewLineStr;
//    result = printSelf;
//    for (int index = 0; index < this->children.size(); index++)
//    {
//        wstring printChild = this->children[index]->Print(level + 1);
//        result += printChild;
//    }
//
//    return result;
//}

const wstring ComposedStmt::GetName() const
{
    return _T("ComposedStmt");
}
