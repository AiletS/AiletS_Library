#pragma once

#include "graph/tree/tree_base.hpp"
#include "graph/tree/EulerTour.hpp"
#include "data_structure/SparseTable.hpp"

template <class _S>
struct Monoid_LCA
{
    using TYPE = _S;
    static TYPE op(TYPE& a, TYPE& b)
    {
        if(a.first < b.first) return a;
        else return b;
    };
    static TYPE e() { return make_pair(infty<int>, -1); };
};

template <class TREE>
struct LCA
{
    TREE& g;
    int n;
    vector<int> in, out;
    vector<pair<int, int>> v;
    SparseTable<Monoid_LCA<pair<int, int>>> sp;

    LCA() {}
    LCA(TREE& _g) : n(_g.n), g(_g), in(n), out(n) 
    {
        tie(in, out, v) = EulerTour(_g);
        sp = SparseTable<Monoid_LCA<pair<int, int>>>(v);
    }

    int get(int x, int y)
    {
        int l = in[x], r = in[y];
        if(l > r) swap(l, r);
        return sp.get(l, r + 1).second;
    }
};