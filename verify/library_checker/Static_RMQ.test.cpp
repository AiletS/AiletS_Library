#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "my_template.hpp"
#include "data_structure/segtree.hpp"
#include "monoid/monoid_min.hpp"

void solve()
{
    int n, q; cin >> n >> q;
    vi a(n); cin >> a;
    segtree<Monoid_min<int>> seg(a);
    while(q--)
    {
        int l, r; cin >> l >> r;
        cout << seg.get(l, r) << '\n';
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