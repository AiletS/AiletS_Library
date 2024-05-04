#define PROBLEM "https://atcoder.jp/contests/abc327/tasks/abc327_d"
#include "my_template.hpp"
#include "graph/is_bipartite.hpp"

void solve()
{
    int n, m; cin >> n >> m;
    Graph<int, false> g(n);
    vi a(m), b(m);
    rep(i, 0, m) cin >> a[i], a[i]--;
    rep(i, 0, m) cin >> b[i], b[i]--;
    rep(i, 0, m) g.add(a[i], b[i]);
    bool ok = is_bipartite(g);
    if(ok) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}