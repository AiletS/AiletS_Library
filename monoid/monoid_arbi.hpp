#pragma once

// !!!
// include するのではなく、直接コピペして使うこと
// !!!

struct S
{
    
};

template <class _S>
struct Monoid_Arbi
{
    using TYPE = _S;
    static TYPE op(TYPE a, TYPE b)
    { 
        // write op
    };
    static TYPE e() 
    { 
        // write e
    };
};