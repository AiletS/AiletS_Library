#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "my_template.hpp"
#include "data_structure/UnionFind.hpp"

void solve()
{
    int n, q; cin >> n >> q;
    UnionFind r(n);
    while(q--)
    {
        int t, u, v; cin >> t >> u >> v;
        if(t == 0) r.unite(u, v);
        else cout << (r.same(u, v) ? 1 : 0) << '\n';
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