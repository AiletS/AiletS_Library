#define PROBLEM "https://atcoder.jp/contests/abc356/tasks/abc356_f"
#include "my_template.hpp"
#include "data_structure/range_set.hpp"
#include "data_structure/Coordinate_Compression.hpp"
#include "data_structure/segtree.hpp"

template <class _S>
struct monoid_arbi
{
    using TYPE = _S;
    static TYPE op(TYPE a, TYPE b)
    {
        return a + b;
    };
    static TYPE e()
    {
        return 0;
    };
};

void solve()
{
    ll q, k; cin >> q >> k;
    vl t(q), x(q);
    CC<ll> cc;
    rep(i, 0, q) cin >> t[i] >> x[i];
    rep(i, 0, q) if(t[i] == 1) cc.add(x[i]);
    ll n = cc.size();
    segtree<monoid_arbi<ll>> seg(n);
    range_set rs;
    set<ll> S;
    S.insert(-infty<ll>), S.insert(infty<ll>);

    auto add = [&](ll a) -> void
    {
        S.insert(a);
        seg.add(cc(a), 1);
        if(rs.covered(a, a + 1)) return;
        rs.insert(a, a + 1);
        auto itr = S.find(a);
        ll l = *prev(itr), r = *next(itr);
        if(l != -infty<ll> && l + k >= a) rs.insert(l, a + 1);
        if(r != infty<ll> && a + k >= r) rs.insert(a, r + 1);
    };

    auto del = [&](ll a) -> void
    {
        S.erase(a);
        seg.add(cc(a), -1);
        rs.erase(a, a + 1);
        auto itr = S.upper_bound(a);
        ll l = *prev(itr), r = *itr;
        if(l == -infty<ll>) l += 10;
        if(r == infty<ll>) r -= 10;

        if(l + k >= r) rs.insert(l, r + 1);
        else
        {
            if(l + k >= a) rs.erase(l + 1, a + 1);
            if(a + k >= r) rs.erase(a, r);
        }
    };

    auto query = [&](ll a) -> void
    {
        if(k == 0) { cout << 1 << '\n'; return; }
        auto [l, r] = rs.covered_by(a, a + 1);
        //rs.dump();
        //cout << l << ' ' << r << '\n';
        //cout << cc(l) << ' ' << cc(r - 1) << '\n';
        ll ans = seg.get(cc(l), cc(r - 1) + 1);
        cout << ans << '\n';
    };


    rep(i, 0, q)
    {
        if(t[i] == 1)
        {
            if(S.find(x[i]) == S.end()) add(x[i]);
            else del(x[i]);
        }
        else query(x[i]);
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