#define PROBLEM "https://atcoder.jp/contests/abc351/tasks/abc351_f"
#include "my_template.hpp"
#include "data_structure/merge_sort_tree.hpp"

void solve()
{
    ll n; cin >> n;
    vl v(n); cin >> v;
    merge_sort_tree st(v);
    ll sum = accumulate(v.begin(), v.end(), 0LL);
    ll ans = 0;
    rep(i, 0, n)
    {
        sum -= v[i];
        auto [x, y] = st.get(i + 1, n, v[i]);
        ans += (sum - y) - v[i] * (n - 1 - i - x);
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}