#include "AstPrinter.h"

const wstring AstPrinter::Print(const Stmt& stmt) const
{
    int depth = this->GetDepth(stmt);
    int leadingSpaceCount = depth * TabWidth;
    wstring s;
    for (int i = 0; i < leadingSpaceCount; i++)
    {
        s += _T(" ");
    }
    s += stmt.GetName();

    // behavior;
    wcout <<s <<endl;

    return s;
}

void AstPrinter::Visit(const IncludeStmt &stmt)
{
    this->Print(stmt);
}

void AstPrinter::Visit(const ComposedStmt &stmt)
{
    this->Print(stmt);
}
