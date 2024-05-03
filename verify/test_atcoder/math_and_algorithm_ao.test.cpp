#define PROBLEM "https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_ao"
#include "my_template.hpp"
#include "graph/is_bipartite.hpp"

void solve()
{
    int n, m; cin >> n >> m;
    Graph g(n); g.mkg(m);
    cout << (is_bipartite(g) ? "Yes" : "No");
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}