#include "nat.h"
#include <iostream>


Nat Nat::operator+(const Nat& rhs)
{
    return Nat(i+rhs.i);
}

Nat Nat::operator-(const Nat& rhs)
{
    return Nat(i-rhs.i);
}


std::ostream& operator<<(std::ostream& out, const Nat& nat)
{
    out <<nat.i;
    return out;
}