#pragma once

// !!!
// include するのではなく、直接コピペして使うこと
// !!!

struct S
{
    
};

struct F
{
    
};

template <class _S, class _F>
struct OperatorMonoid_Arbi
{
    using TYPE_S = _S;
    using TYPE_F = _F;
    static TYPE_S op(TYPE_S L, TYPE_S R)
    {

    }
    static TYPE_S e()
    {

    }
    static TYPE_S mapping(TYPE_F f, TYPE_S a)
    {

    }
    static TYPE_F composition(TYPE_F l, TYPE_F r)
    {

    }
    static TYPE_F id()
    {

    }
};