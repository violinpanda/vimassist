#include "AstTree.h"

AstTree::AstTree()
{}

AstTree::~AstTree()
{}

void AstTree::Print() const
{
    wcout <<this->topLevelStmt.Print(0) <<endl;
}