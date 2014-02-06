#include "StmtVisitor.h"
#include <assert.h>

void StmtVisitor::Visit(const Stmt* stmt)
{
    switch (stmt->GetKind())
    {
        case SK_IncludeStmt:
            {
                const IncludeStmt* includeStmt = dynamic_cast<const IncludeStmt*>(stmt);
                if (includeStmt != NULL)
                {
                    this->Visit(*includeStmt);
                }
            }
            break;
        case SK_FuncBodyStmt:
            {
                const ComposedStmt* composedStmt = dynamic_cast<const ComposedStmt*>(stmt);
                if (composedStmt != NULL)
                {
                    this->Visit(*composedStmt);
                    const vector<Stmt*> children = composedStmt->GetChildren();
                    for (int index = 0; index < children.size(); index++)
                    {
                        this->Visit(children[index]);
                    }
                }
            }
            break;
        default:
            assert(false, "please update here if new StmtKind added");
            break;
    }
}

int StmtVisitor::GetDepth(const Stmt& stmt) const
{
    int depth = 0;
    const Stmt* parent = stmt.GetParent();
    while (parent != NULL)
    {
        depth++;
        parent = parent->GetParent();
    }

    return depth;
}
