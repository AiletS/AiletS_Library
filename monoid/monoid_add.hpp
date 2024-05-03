#pragma once

template <class _S>
struct Monoid_add
{
    using TYPE = _S;
    static TYPE op(TYPE a, TYPE b)
    {
        return a + b;
    };
    static TYPE e() 
    {
        return 0;
    };
};