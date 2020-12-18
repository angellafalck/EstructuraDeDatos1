#ifndef _NUEVO_H
#define _NUEVO_H

#include <string>
#include "expr_binary_tree.h"

class nuevo
{
public:
    nuevo() = default;

    int num(Expr *expr);

private:
    int visit(AddExpr *expr);
    int visit(SubExpr *expr);
    int visit(MulExpr *expr);
    int visit(DivExpr *expr);
    int visit(NumberExpr *expr);
};

#endif