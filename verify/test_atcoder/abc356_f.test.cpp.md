---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/Coordinate_Compression.hpp
    title: data_structure/Coordinate_Compression.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/range_set.hpp
    title: data_structure/range_set.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/segtree.hpp
    title: data_structure/segtree.hpp
  - icon: ':heavy_check_mark:'
    path: my_template.hpp
    title: my_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc356/tasks/abc356_f
    links:
    - https://atcoder.jp/contests/abc356/tasks/abc356_f
  bundledCode: "#line 1 \"verify/test_atcoder/abc356_f.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc356/tasks/abc356_f\"\n#line 2 \"my_template.hpp\"\
    \n#pragma GCC optimize(\"O3\")\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long; using ld = long double;\nusing P = pair<int, int>; using\
    \ Pll = pair<ll, ll>;\nusing vi = vector<int>; using vvi = vector<vector<int>>;\
    \ using vvvi = vector<vvi>;\nusing vl = vector<ll>; using vvl = vector<vector<ll>>;\
    \ using vvvl = vector<vvl>;\nusing vld = vector<ld>; using vvld = vector<vector<vld>>;\
    \ using vvvld = vector<vvld>;\nusing vp = vector<P>; using vpll = vector<Pll>;\
    \ using vvp = vector<vector<P>>;\nusing vs = vector<string>;\ntemplate <typename\
    \ T> using pq = priority_queue<T, vector<T>, greater<T>>;\n#define rep(i, s, n)\
    \ for (long long i = (s); i < (long long)(n); i++)\n#define drep(i, s, n) for\
    \ (long long i = (s); i >= (long long)(n); i--)\ntemplate <typename T> bool chmax(T&\
    \ a, const T& b) { if (a < b) { a = b; return true; } return false; }\ntemplate\
    \ <typename T> bool chmin(T& a, const T& b) { if (a > b) { a = b; return true;\
    \ } return false; }\ntemplate <typename T = long long> T floor(T x, T m) { return\
    \ (x - ((x % m + m) % m)) / m; }\ntemplate <typename T = long long> T ceil(T x,\
    \ T m) { return floor(x + m - 1, m); }\n\ntemplate <class T> constexpr T infty\
    \ = 0;\ntemplate<> constexpr int infty<int> = 1001001001;\ntemplate<> constexpr\
    \ long long infty<long long> = 9e18;\ntemplate<> constexpr double infty<double>\
    \ = infty<long long>;\ntemplate<> constexpr long double infty<long double> = infty<long\
    \ long>;\n\ntemplate<class T> istream& operator >> (istream& i, vector<T>& v)\
    \ { for(T& p : v) cin >> p; return i; }\ntemplate<class T> ostream& operator <<\
    \ (ostream& o, vector<T>& v) { for(T& p : v) cout << p << \" \"; return o; }\n\
    template<class T> istream& operator >> (istream& i, vector<vector<T>>& v) { for(vector<T>&\
    \ p : v) cin >> p; return i; }\ntemplate<class T> ostream& operator << (ostream&\
    \ o, vector<vector<T>>& v) { for(vector<T>& p : v) cout << p << '\\n'; return\
    \ o; }\ntemplate<class T> void operator -- (vector<T>& v, int) { for(T& p : v)\
    \ p--; }\ntemplate<class T> void operator ++ (vector<T>& v, int) { for(T& p :\
    \ v) p++; }\n#line 2 \"data_structure/range_set.hpp\"\n\n\n/*\nrange_set\nrange_set<T\
    \ = long long>()\nbool covered(T l, T r) [l, r) \u304C\u30AB\u30D0\u30FC\u3055\
    \u308C\u3066\u3044\u308B\u304B\npair<T, T> covered_by(T l, T r) [l, r) \u304C\u30AB\
    \u30D0\u30FC\u3055\u308C\u3066\u3044\u308B\u533A\u9593\u3092\u8FD4\u3059\nT insert(T\
    \ l, T r) [l, r) \u3092\u633F\u5165\u3059\u308B\u3002\u5897\u52A0\u5206\u3092\u8FD4\
    \u3059\nT erase(T l, T r) [l, r) \u3092\u6D88\u3059\u3002\u6E1B\u5C11\u5206\u3092\
    \u8FD4\u3059\nint size() \u533A\u9593\u306E\u500B\u6570\u3092\u8FD4\u3059\nT mex(T\
    \ x = 0) mex \u3092\u8FD4\u3059\nT sum_all() \u3059\u3079\u3066\u306E\u533A\u9593\
    \u306E\u548C(\u7D76\u5BFE\u5024)\u3092\u8FD4\u3059\nset<pair<T, T>> get() \u533A\
    \u9593(set)\u3092\u305D\u306E\u307E\u307E\u8FD4\u3059\nvoid dump() \u30C7\u30D0\
    \u30C3\u30B0\u7528\n*/\ntemplate <class T = long long>\nclass range_set\n{\n \
    \ private:\n    const T inf = infty<T>;\n    T sum;\n    set<pair<T, T>> S;\n\
    \  public:\n    range_set() : sum(0)\n    {   // [-inf, -inf) ... [inf, inf)\n\
    \        S.emplace(-inf, -inf);\n        S.emplace(inf, inf);\n    }\n\n    //\
    \ [l, r) is covered?\n    bool covered(const T l, const T r)\n    {\n        assert(l\
    \ <= r);\n        if(l == r) return true;\n        auto itr = prev(S.upper_bound({l,\
    \ inf}));\n        return itr->first <= l && r <= itr->second;\n    }\n\n    //\
    \ return section which covers[l, r)\n    // if not exists, return [-inf, inf)\n\
    \    pair<T, T> covered_by(const T l, const T r)\n    {\n        assert(l <= r);\n\
    \        if(l == r) return {-inf, -inf};\n        auto itr = prev(S.upper_bound({l,\
    \ inf}));\n        if(itr->first <= l && r <= itr->second) return *itr;\n    \
    \    return {-inf, -inf};\n    }\n\n    // insert[l, r), and return increment\n\
    \    T insert(T l, T r)\n    {\n        assert(l <= r);\n        if(l == r) return\
    \ T(0);\n        auto itr = prev(S.upper_bound({l, inf}));\n        if(itr->first\
    \ <= l && r <= itr->second) return T(0);\n        T sum_erased = T(0);\n     \
    \   if(itr->first <= l && l <= itr->second)\n        {\n            l = itr->first;\n\
    \            sum_erased += itr->second - itr->first;\n            itr = S.erase(itr);\n\
    \        }\n        else itr = next(itr);\n        while(r > itr->second)\n  \
    \      {\n            sum_erased += itr->second - itr->first;\n            itr\
    \ = S.erase(itr);\n        }\n\t\tif(itr->first <= r) \n        {\n\t\t\tsum_erased\
    \ += itr->second - itr->first;\n\t\t\tr = itr->second;\n\t\t\tS.erase(itr);\n\t\
    \t}\n\t\tS.emplace(l, r);\n\t\tsum += r - l - sum_erased;\n\t\treturn r - l -\
    \ sum_erased;\n    }\n\n    // erase [l, r), and return decrement\n\tT erase(const\
    \ T l, const T r) \n    {\n\t\tassert(l <= r);\n\t\tif(l == r) return T(0);\n\t\
    \tauto itr = prev(S.upper_bound({l, inf}));\n\t\tif(itr->first <= l and r <= itr->second)\
    \ \n        {\n\t\t\tif(itr->first < l) S.emplace(itr->first, l);\n\t\t\tif(r\
    \ < itr->second) S.emplace(r, itr->second);\n\t\t\tS.erase(itr);\n\t\t\tsum -=\
    \ r - l;\n\t\t\treturn r - l;\n\t\t}\n\t\tT ret = T(0);\n\t\tif(itr->first <=\
    \ l and l < itr->second) \n        {\n\t\t\tret += itr->second - l;\n\t\t\tif(itr->first\
    \ < l) S.emplace(itr->first, l);\n\t\t\titr = S.erase(itr);\n\t\t} \n        else\
    \ itr = next(itr);\n\t\twhile(itr->second <= r) \n        {\n\t\t\tret += itr->second\
    \ - itr->first;\n\t\t\titr = S.erase(itr);\n\t\t}\n\t\tif(itr->first < r) \n \
    \       {\n\t\t\tret += r - itr->first;\n\t\t\tS.emplace(r, itr->second);\n\t\t\
    \tS.erase(itr);\n\t\t}\n\t\tsum -= ret;\n\t\treturn ret;\n\t}\n\n    int size()\
    \ const { return (int)S.size() - 2; }\n\n    \n\tT mex(const T x = 0) const \n\
    \    {\n\t\tauto itr = prev(S.upper_bound({x, inf}));\n\t\tif(itr->first <= x\
    \ and x < itr->second)\n\t\t\treturn itr->second;\n\t\telse\n\t\t\treturn x;\n\
    \t}\n\n    T sum_all() const { return sum; }\n\n    // get set\n\tset<pair<T,\
    \ T>> get() const \n    {\n\t\tset<pair<T, T>> res;\n\t\tfor(auto &p : S) {\n\t\
    \t\tif(abs(p.first) == inf) continue;\n\t\t\tres.emplace(p.first, p.second);\n\
    \t\t}\n\t\treturn res;\n\t}\n\n    // debug\n\tvoid dump() const \n    {\n\t\t\
    cout << \"range_set:\";\n\t\tfor(auto &p : S) {\n\t\t\tif(abs(p.first) == inf)\
    \ continue;\n\t\t\tcout << \"[\" << p.first << \",\" << p.second << \"),\";\n\t\
    \t}\n\t\tcout << '\\n';\n\t}\n};\n#line 2 \"data_structure/Coordinate_Compression.hpp\"\
    \n\n\n// Coordinate Comporession (\u5EA7\u6A19\u5727\u7E2E)\n// CC<T = long long>(),\
    \ CC<T = long long>(vector<T> v)\n// add(T x) \u3067\u8981\u7D20\u3092\u8FFD\u52A0\
    \n// operator [i] \u3067\u5727\u7E2E\u5F8C\u306E i \u756A\u76EE\u306E\u8981\u7D20\
    \u3092\u53D6\u5F97\n// operator (i) \u3067\u5727\u7E2E\u5F8C\u306E i \u304C\u4F55\
    \u756A\u76EE\u304B\u3092\u53D6\u5F97\ntemplate <typename T = long long>\nclass\
    \ CC\n{\n  public:\n\tCC() : CC(vector<T>(0)) {}\n\tCC(const vector<T>& _v)\n\t\
    {\n\t\tis_build = false;\n\t\tfor(T x : _v) add(x);\n\t}\n\n\tvoid add(T x) {\
    \ v.push_back(x); is_build = false; }\n\n\tint operator() (T x)\n\t{\n\t\tif (!is_build)\
    \ init();\n\t\treturn upper_bound(v.begin(), v.end(), x) - v.begin() - 1;\n\t\
    }\n\n\tT operator[] (int i)\n\t{\n\t\tassert(i >= 0 && i < v.size());\n\t\tif\
    \ (!is_build) init();  return v[i];\n\t}\n\n\tint size()\n\t{\n\t\tif (!is_build)\
    \ init(); return v.size();\n\t}\n\n  private:\n\tbool is_build;\n\tvector<T> v;\n\
    \tvoid init()\n\t{\n\t\tsort(v.begin(), v.end());\n\t\tv.erase(unique(v.begin(),\
    \ v.end()), v.end());\n\t\tis_build = true;\n\t}\n};\n#line 2 \"data_structure/segtree.hpp\"\
    \n\n/*\nMonoid\u304C\u5FC5\u8981\nsegtree(), segtree(int k), segtree(vector<Monoid::TYPE>\
    \ v)\n1,2\u756A\u76EE\u306F operator[i]\u3067\u8FFD\u52A0\u3057\u3066 init()\u304C\
    \u5FC5\u8981\nvoid set(int i, T x) [i] \u3092 x \u306B\u8A2D\u5B9A\nvoid add(int\
    \ i, T x) [i] \u306B x \u3092\u8DB3\u3059(Monoid \u306E op \u3092\u9069\u7528\u3059\
    \u308B)\nT get(int l, int r) [l, r) \u306E\u6F14\u7B97\u7D50\u679C\u3092\u5F97\
    \u308B\n*/\ntemplate <class Monoid>\nstruct segtree\n{\n  private:\n\tusing T\
    \ = typename Monoid::TYPE;\n\tint n;\n\tvector<T> v;\n\t\n\tvoid upd(int i) {\
    \ v[i] = Monoid::op(v[i << 1], v[i << 1 | 1]); }\n\n  public:\n\tsegtree() : segtree(vector<T>(0)){}\n\
    \tsegtree(int k) : segtree(vector<T>(k, Monoid::e())) {}\n\tsegtree(const vector<T>&\
    \ _v)\n\t{\n\t\tint k = _v.size();\n\t\tn = 1; while(n < k) n <<= 1;\n\t\tv =\
    \ vector<T>(n << 1, Monoid::e());\n\t\tfor(int i = 0; i < k; i++) v[i + n] = _v[i];\n\
    \t\tinit();\n\t}\n\n\tT& operator[](int i) { return v[i + n]; }\n\n\tvoid init()\
    \ { for (int i = n - 1; i; i--) upd(i); }\n\n\tvoid set(int i, T x) { for (i +=\
    \ n, v[i] = x, i >>= 1; i; i >>= 1) upd(i); }\n\n\tvoid add(int i, T x) { for\
    \ (i += n, v[i] += x, i >>= 1; i; i >>= 1) upd(i); }\n\n\tT get(int l, int r)\
    \ // [l, r)\n\t{\n\t\tT ls = Monoid::e(), rs = Monoid::e();\n\t\tl += n; r +=\
    \ n;\n\n\t\twhile (l < r) {\n\t\t\tif (l & 1) ls = Monoid::op(ls, v[l++]);\n\t\
    \t\tif (r & 1) rs = Monoid::op(v[--r], rs);\n\t\t\tl >>= 1; r >>= 1;\n\t\t}\n\t\
    \treturn Monoid::op(ls, rs);\n\t}\n};\n#line 6 \"verify/test_atcoder/abc356_f.test.cpp\"\
    \n\ntemplate <class _S>\nstruct monoid_arbi\n{\n    using TYPE = _S;\n    static\
    \ TYPE op(TYPE a, TYPE b)\n    {\n        return a + b;\n    };\n    static TYPE\
    \ e()\n    {\n        return 0;\n    };\n};\n\nvoid solve()\n{\n    ll q, k; cin\
    \ >> q >> k;\n    vl t(q), x(q);\n    CC<ll> cc;\n    rep(i, 0, q) cin >> t[i]\
    \ >> x[i];\n    rep(i, 0, q) if(t[i] == 1) cc.add(x[i]);\n    ll n = cc.size();\n\
    \    segtree<monoid_arbi<ll>> seg(n);\n    range_set rs;\n    set<ll> S;\n   \
    \ S.insert(-infty<ll>), S.insert(infty<ll>);\n\n    auto add = [&](ll a) -> void\n\
    \    {\n        S.insert(a);\n        seg.add(cc(a), 1);\n        if(rs.covered(a,\
    \ a + 1)) return;\n        rs.insert(a, a + 1);\n        auto itr = S.find(a);\n\
    \        ll l = *prev(itr), r = *next(itr);\n        if(l != -infty<ll> && l +\
    \ k >= a) rs.insert(l, a + 1);\n        if(r != infty<ll> && a + k >= r) rs.insert(a,\
    \ r + 1);\n    };\n\n    auto del = [&](ll a) -> void\n    {\n        S.erase(a);\n\
    \        seg.add(cc(a), -1);\n        rs.erase(a, a + 1);\n        auto itr =\
    \ S.upper_bound(a);\n        ll l = *prev(itr), r = *itr;\n        if(l == -infty<ll>)\
    \ l += 10;\n        if(r == infty<ll>) r -= 10;\n\n        if(l + k >= r) rs.insert(l,\
    \ r + 1);\n        else\n        {\n            if(l + k >= a) rs.erase(l + 1,\
    \ a + 1);\n            if(a + k >= r) rs.erase(a, r);\n        }\n    };\n\n \
    \   auto query = [&](ll a) -> void\n    {\n        if(k == 0) { cout << 1 << '\\\
    n'; return; }\n        auto [l, r] = rs.covered_by(a, a + 1);\n        //rs.dump();\n\
    \        //cout << l << ' ' << r << '\\n';\n        //cout << cc(l) << ' ' <<\
    \ cc(r - 1) << '\\n';\n        ll ans = seg.get(cc(l), cc(r - 1) + 1);\n     \
    \   cout << ans << '\\n';\n    };\n\n\n    rep(i, 0, q)\n    {\n        if(t[i]\
    \ == 1)\n        {\n            if(S.find(x[i]) == S.end()) add(x[i]);\n     \
    \       else del(x[i]);\n        }\n        else query(x[i]);\n    }\n}\n\nint\
    \ main()\n{\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n  \
    \  int t = 1;\n    //cin >> t;\n    while (t--) solve();\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc356/tasks/abc356_f\"\n#include\
    \ \"my_template.hpp\"\n#include \"data_structure/range_set.hpp\"\n#include \"\
    data_structure/Coordinate_Compression.hpp\"\n#include \"data_structure/segtree.hpp\"\
    \n\ntemplate <class _S>\nstruct monoid_arbi\n{\n    using TYPE = _S;\n    static\
    \ TYPE op(TYPE a, TYPE b)\n    {\n        return a + b;\n    };\n    static TYPE\
    \ e()\n    {\n        return 0;\n    };\n};\n\nvoid solve()\n{\n    ll q, k; cin\
    \ >> q >> k;\n    vl t(q), x(q);\n    CC<ll> cc;\n    rep(i, 0, q) cin >> t[i]\
    \ >> x[i];\n    rep(i, 0, q) if(t[i] == 1) cc.add(x[i]);\n    ll n = cc.size();\n\
    \    segtree<monoid_arbi<ll>> seg(n);\n    range_set rs;\n    set<ll> S;\n   \
    \ S.insert(-infty<ll>), S.insert(infty<ll>);\n\n    auto add = [&](ll a) -> void\n\
    \    {\n        S.insert(a);\n        seg.add(cc(a), 1);\n        if(rs.covered(a,\
    \ a + 1)) return;\n        rs.insert(a, a + 1);\n        auto itr = S.find(a);\n\
    \        ll l = *prev(itr), r = *next(itr);\n        if(l != -infty<ll> && l +\
    \ k >= a) rs.insert(l, a + 1);\n        if(r != infty<ll> && a + k >= r) rs.insert(a,\
    \ r + 1);\n    };\n\n    auto del = [&](ll a) -> void\n    {\n        S.erase(a);\n\
    \        seg.add(cc(a), -1);\n        rs.erase(a, a + 1);\n        auto itr =\
    \ S.upper_bound(a);\n        ll l = *prev(itr), r = *itr;\n        if(l == -infty<ll>)\
    \ l += 10;\n        if(r == infty<ll>) r -= 10;\n\n        if(l + k >= r) rs.insert(l,\
    \ r + 1);\n        else\n        {\n            if(l + k >= a) rs.erase(l + 1,\
    \ a + 1);\n            if(a + k >= r) rs.erase(a, r);\n        }\n    };\n\n \
    \   auto query = [&](ll a) -> void\n    {\n        if(k == 0) { cout << 1 << '\\\
    n'; return; }\n        auto [l, r] = rs.covered_by(a, a + 1);\n        //rs.dump();\n\
    \        //cout << l << ' ' << r << '\\n';\n        //cout << cc(l) << ' ' <<\
    \ cc(r - 1) << '\\n';\n        ll ans = seg.get(cc(l), cc(r - 1) + 1);\n     \
    \   cout << ans << '\\n';\n    };\n\n\n    rep(i, 0, q)\n    {\n        if(t[i]\
    \ == 1)\n        {\n            if(S.find(x[i]) == S.end()) add(x[i]);\n     \
    \       else del(x[i]);\n        }\n        else query(x[i]);\n    }\n}\n\nint\
    \ main()\n{\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n  \
    \  int t = 1;\n    //cin >> t;\n    while (t--) solve();\n}"
  dependsOn:
  - my_template.hpp
  - data_structure/range_set.hpp
  - data_structure/Coordinate_Compression.hpp
  - data_structure/segtree.hpp
  isVerificationFile: true
  path: verify/test_atcoder/abc356_f.test.cpp
  requiredBy: []
  timestamp: '2024-06-17 21:21:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/test_atcoder/abc356_f.test.cpp
layout: document
redirect_from:
- /verify/verify/test_atcoder/abc356_f.test.cpp
- /verify/verify/test_atcoder/abc356_f.test.cpp.html
title: verify/test_atcoder/abc356_f.test.cpp
---
