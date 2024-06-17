#pragma once

#include "graph/graph_base.hpp"

template <class GT>
struct Tree
{
    using Graph_type = GT;
    using cost_type = typename GT::cost_type;
    GT& G;
    int n, root;
    vector<int> depth, parent;

    Tree() {}
    Tree(GT& G, int root = 0) : G(G), root(root) { build(); }
    const vector<Edge<cost_type>>& operator[](int x) const { return G[x]; }

    void build()
    {
        n = G.n;
        depth.assign(n, -1), parent.assign(n, -1);
        dfs(root, -1);
    }

    void dfs(int U, int V)
    {
        parent[U] = V;
        depth[U] = (V == -1 ? 0 : depth[V] + 1);
        for(auto [from, to, _, __] : G[U])
        {
            if(to == V) continue;
            dfs(to, from);
        }
    }
};