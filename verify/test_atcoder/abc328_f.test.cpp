#define PROBLEM "https://atcoder.jp/contests/abc328/tasks/abc328_f"
#include "my_template.hpp"
#include "data_structure/Weighted_UnionFind.hpp"

void solve()
{
    ll n, q; cin >> n >> q;
    Weighted_UnionFind<ll> r(n);
    rep(i, 0, q)
    {
        ll a, b, d; cin >> a >> b >> d; a--, b--;
        if(r.unite(a, b, d)) cout << i + 1 << (i == q - 1 ? '\n' : ' ');
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