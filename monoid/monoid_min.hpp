#pragma once

template <class _S>
struct monoid_min
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