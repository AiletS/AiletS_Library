#pragma once

#include "graph/tree/lca.hpp"

// Compress Tree or Auxiliary Tree
// CompressTree(Tree g), get(vector<int> X)
// 頂点集合 X をもとに圧縮した木を返す :
// [V, Tree] V は Tree の頂点の番号に対応している
// |Tree| <= 2|X| - 1, 生成に O(|X|(log|X| + log|N|))
template <class TREE>
struct CompressTree
{
    CompressTree() {}
    CompressTree(TREE& _g) : g(_g), n(g.n)
    {
        lca = LCA(g);
        pre_ord.resize(n);
        int now = 0;
        dfs(g.root, -1, now);
    }

    pair<vector<int>, TREE> get(vector<int> X)
    {
        int tn = X.size();
        sort(X.begin(), X.end(), [&](int& l, int& r) { return pre_ord[l] < pre_ord[r]; });
        for(int i = 0; i < tn - 1; i++) X.push_back(lca.get(X[i], X[i + 1]));
        sort(X.begin(), X.end(), [&](int& l, int& r) { return pre_ord[l] < pre_ord[r]; });
        X.erase(unique(X.begin(), X.end()), X.end());
        tn = X.size();

        Graph _g(tn);
        TREE res(_g);
        stack<int> S; S.push(0);
        for(int i = 1; i < tn; i++)
        {
            while(S.size() && lca.out[X[S.top()]] < lca.in[X[i]]) S.pop();
            res.add(S.top(), i);
            S.push(i);
        }
        return {X, res};
    }

  private:
    TREE& g;
    int n;
    vector<int> pre_ord;
    LCA<TREE> lca;

    function<void(int, int, int&)> dfs = [&](int U, int V, int& now) -> void
    {
        assert(U >= 0 && U < n);
        pre_ord[U] = now++;
        for(auto [from, to, _, __] : g[U])
        {
            if(to == V) continue;
            dfs(to, from, now);
        }
    };
};