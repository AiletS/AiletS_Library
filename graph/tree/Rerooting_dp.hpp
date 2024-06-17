#pragma once

#include "graph/tree/tree_base.hpp"

/*
Rerooting_dp<decltype(g), S, e, fee, fev> dp(g);
struct S : 型
S e() : Sの単位限
S fee(S, S) : 部分木の結合
S fev(S, int) : 辺 e から頂点 v に
*/
template <class TREE, class S, S (*e)(), S (*fee)(S, S), S (*fev)(S, int)>
struct Rerooting_dp
{
    TREE& g;
    int n;
    vector<S> subtree;
    vector<S> rev_subtree;
    vector<S> ans;

    Rerooting_dp() {}
    Rerooting_dp(TREE& _g) : g(_g), n(_g.n) { build(); }

    S& operator[](int i) { return ans[i]; }

    void build()
    {
        subtree.assign(n, e());
        rev_subtree.assign(n, e());
        int root = g.root;
        dfs(root);
        dfs2(root);
    }

    S dfs(int U)
    {
        S res = e();
        int m = g[U].size();
        for(int i = 0; i < m; i++)
        {
            auto [from, to, _, __] = g[U][i];
            if(to == g.parent[U]) continue;
            res = fee(res, dfs(to));
        }
        return subtree[U] = fev(res, U);        
    }

    void dfs2(int U)
    {
        int m = g[U].size();
        vector<S> l(m + 1, e()), r(m + 1, e());
        for(int i = 0; i < m; i++)
        {
            auto [from, to, _, __] = g[U][i];
            if(to == g.parent[from]) l[i + 1] = fee(l[i], rev_subtree[from]);
            else l[i + 1] = fee(l[i], subtree[to]);
        }
        for(int i = m - 1; i >= 0; i--)
        {
            auto [from, to, _, __] = g[U][i];
            if(to == g.parent[U]) r[i] = fee(r[i + 1], rev_subtree[from]);
            else r[i] = fee(r[i + 1], subtree[to]);
        }
        for(int i = 0; i < m; i++)
        {
            auto [from, to, _, __] = g[U][i];
            if(to == g.parent[U]) continue;
            rev_subtree[to] = fev(fee(l[i], r[i + 1]), U);
            dfs2(to);
        }
    }

    vector<S> get()
    {
        ans.assign(n, e());
        for(int i = 0; i < n; i++)
        {
            int m = g[i].size();
            for(int j = 0; j < m; j++)
            {
                if(g[i][j].to == g.parent[i]) ans[i] = fee(ans[i], rev_subtree[i]);
                else ans[i] = fee(ans[i], subtree[g[i][j].to]);
            }
            ans[i] = fev(ans[i], i);
        }
        return ans;
    }
};