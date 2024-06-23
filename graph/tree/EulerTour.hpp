#pragma once

#include "graph/tree/tree_base.hpp"

/*
木上でEuler Tourを行う
tuple<vector<int>, vector<int>, vector<pair<int, int>>>
= {in, out, {depth, 頂点}}
*/
template <class TREE>
tuple<vector<int>, vector<int>, vector<pair<int, int>>>
EulerTour(const TREE& g)
{
    const int n = g.n;
    vector<int> in(n), out(n);
    vector<pair<int, int>> v;

    function<void(int, int, int)> dfs = [&](int U, int V, int depth) -> void
    {
        assert(U >= 0 && U < n);
        in[U] = v.size();
        v.emplace_back(depth, U);
        for(auto [from, to, _, __] : g[U])
        {
            if(to == V) continue;
            dfs(to, from, depth + 1);
        }
        out[U] = v.size();
        v.emplace_back(depth - 1, V);
    };

    dfs(g.root, -1, 0);
    return { in, out, v };
}