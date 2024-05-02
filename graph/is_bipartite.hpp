#pragma once

#include "graph/graph_base.hpp"

template <class G>
bool is_bipartite(G &g)
{
    int n = g.n;
    bool res = true;
    vector<int> color(n, -1);
    auto dfs = [&](auto dfs, int U, int V) -> void
    {
        for(auto [from, to, _, __] : g[U])
        {
            if(color[to] >= 0)
            {
                if(color[from] == color[to]) res = false;
                continue;
            }
            color[to] = color[from] ^ 1;
            dfs(dfs, to, from);
        }
    };
    for(int i = 0; i < n; i++)
    {
        if(color[i] >= 0) continue;
        color[i] = 0;
        dfs(dfs, i, -1);
    }
    return res;
}