#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include "my_template.hpp"
#include "data_structure/FenwickTree.hpp"

void solve()
{
    ll n, q; cin >> n >> q;
    vl a(n); cin >> a;
    FenwickTree b(a);
    while(q--)
    {
        ll l, r; cin >> l >> r;
        cout << b.get(l, r) << '\n';
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