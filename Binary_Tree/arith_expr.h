#ifndef _ARITH_EXPR_
#define _ARITH_EXPR_

enum class Operator
{
    Add,
    Sub,
    Mult,
    Div
};

enum class DataKind
{
    Operator,
    Number
};

struct ExprData
{
    DataKind kind;
    union{
        Operator oper;
        int number;
    };
};

#endif