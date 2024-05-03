#pragma once

template <class _S>
struct Monoid_min
{
    using TYPE = _S;
    static TYPE op(TYPE a, TYPE b)
    {
        return min(a, b);
    };
    static TYPE e() 
    {
        return infty<TYPE>;
    };
};