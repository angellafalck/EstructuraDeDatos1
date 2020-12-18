#include <stdexcept>
#include "nuevo.h"

int nuevo::num(Expr *expr)
{
    switch (expr->kind())
    {
        case NodeKind::Add:
            return visit(reinterpret_cast<AddExpr *>(expr));
        case NodeKind::Sub:
            return visit(reinterpret_cast<SubExpr *>(expr));
        case NodeKind::Mul:
            return visit(reinterpret_cast<MulExpr *>(expr));
        case NodeKind::Div:
            return visit(reinterpret_cast<DivExpr *>(expr));
        case NodeKind::Number:
            return visit(reinterpret_cast<NumberExpr *>(expr));
        default:
            throw std::runtime_error("Invalid node");
    }
}

int nuevo::visit(AddExpr *expr)
{
    int lp = num(expr->left);
    int rp = num(expr->right);

    return lp + rp;
}

int nuevo::visit(SubExpr *expr)
{
    int lp = num(expr->left);
    int rp = num(expr->right);

    return lp - rp;

}

int nuevo::visit(MulExpr *expr)
{
    int lp = num(expr->left);
    int rp = num(expr->right);

    return lp * rp;
}

int nuevo::visit(DivExpr *expr)
{
    int lp = num(expr->left);
    int rp = num(expr->right);

    return lp / rp;

}

int nuevo::visit(NumberExpr *expr)
{
    return int (expr->value);
}
