#pragma once

template <class _S>
struct monoid_max
{
    using TYPE = _S;
    static TYPE op(TYPE a, TYPE b)
    {
        return max(a, b);
    };
    static TYPE e() 
    {
        return -infty<TYPE>;
    };
};