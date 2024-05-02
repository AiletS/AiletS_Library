#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include "my_template.hpp"
#include "graph/scc.hpp"

void solve()
{
    int n, m; cin >> n >> m;
    Graph<long long, true> g(n);
    g.mkg(m, false, 0);
    auto res = scc(g);
    cout << res.size() << '\n';
    for(auto p : res)
    {
        cout << p.size() << ' ' << p << '\n';
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