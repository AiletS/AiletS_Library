#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "my_template.hpp"
#include "graph/tree/lca.hpp"

void solve()
{
    int n, q; cin >> n >> q;
    Graph g(n); g.mkg_ancestor(false, 0);
    Tree<decltype(g)> tree(g);
    LCA lca(tree);
    while(q--)
    {
        int u, v; cin >> u >> v;
        cout << lca.get(u, v) << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}