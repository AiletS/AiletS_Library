---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structure/Weighted_UnionFind.hpp
    title: data_structure/Weighted_UnionFind.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc328/tasks/abc328_f
    links:
    - https://atcoder.jp/contests/abc328/tasks/abc328_f
  bundledCode: "#line 1 \"verify/test_atcoder/abc328_f.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc328/tasks/abc328_f\"\n#line 2 \"my_template.hpp\"\
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
    \ v) p++; }\n#line 2 \"data_structure/Weighted_UnionFind.hpp\"\n\n/*\nWeighted_UnionFind<T\
    \ = long long>(int n, T off = 0) : \u91CD\u307F\u306F\u6700\u521D off \u306E\u30B5\
    \u30A4\u30BA n \u3067\u751F\u6210\nfind(int x) x \u306E\u4EE3\u8868\u3092\u53D6\
    \u5F97\nweight(int x) x \u304C\u542B\u307E\u308C\u3066\u3044\u308B\u30B0\u30EB\
    \u30FC\u30D7\u306E\u91CD\u307F\u3092\u53D6\u5F97\nunite(int x, int y, T weight)\
    \ x, y \u3092\u91CD\u307F\u304C y - x = weight \u306B\u306A\u308B\u3088\u3046\u306B\
    \u7D50\u5408\nsame(int x, int y) x, y \u304C\u540C\u3058\u30B0\u30EB\u30FC\u30D7\
    \u3067\u3042\u308B\u304B\u3092\u53D6\u5F97\ngroup() \u73FE\u5728\u306E\u30B0\u30EB\
    \u30FC\u30D7\u306E\u500B\u6570\u3092\u53D6\u5F97\nsize(int x) x \u304C\u542B\u307E\
    \u308C\u3066\u3044\u308B\u30B0\u30EB\u30FC\u30D7\u306E\u30B5\u30A4\u30BA\u3092\
    \u53D6\u5F97\ndiff(int x, int y) \u91CD\u307F\u306E\u5DEE weight(y) - weight(x)\
    \ \u3092\u53D6\u5F97\n*/\ntemplate <class T = long long>\nclass Weighted_UnionFind\n\
    {\n  private:\n    vector<int> par, rk, SIZE;\n    vector<T> w;\n    int gr;\n\
    \n  public:\n    Weighted_UnionFind(int n, T off = 0) : gr(n), par(n), rk(n, 0),\
    \ SIZE(n, 1), w(n, off) // initialize\n    {\n        iota(par.begin(), par.end(),\
    \ 0);\n    }\n\n    int find(int x) // find parent\n    {\n        if (par[x]\
    \ == x) return x;\n        else { int r = find(par[x]); w[x] += w[par[x]]; return\
    \ par[x] = r; }\n    }\n\n    T weight(int x) { find(x); return w[x]; }\n\n  \
    \  bool unite(int x, int y, T _weight) // unite two nodes, y - x = _weight\n \
    \   {\n        _weight += weight(x); _weight -= weight(y);\n        x = find(x),\
    \ y = find(y);\n        if (x == y) return diff(x, y) == _weight;\n\n        gr--;\n\
    \        if(rk[x] < rk[y]) swap(x, y) , _weight = -_weight;\n        if(rk[x]\
    \ == rk[y]) rk[x]++;\n        par[y] = x; SIZE[x] += SIZE[y];\n        w[y] =\
    \ _weight;\n        return true;\n    }\n\n    bool same(int x, int y) { return\
    \ find(x) == find(y); }\n    // judge two nodes' parents are the same\n\n    int\
    \ group() { return gr; }\n    // total number of connectivity components\n\n \
    \   int size(int x) { return SIZE[find(x)]; }\n    // number of nodes in the connection\
    \ component containing x\n\n    T diff(int x, int y) { return weight(y) - weight(x);\
    \ }\n    // return weight(y - x)\n};\n#line 4 \"verify/test_atcoder/abc328_f.test.cpp\"\
    \n\nvoid solve()\n{\n    ll n, q; cin >> n >> q;\n    Weighted_UnionFind<ll> r(n);\n\
    \    rep(i, 0, q)\n    {\n        ll a, b, d; cin >> a >> b >> d; a--, b--;\n\
    \        if(r.unite(a, b, d)) cout << i + 1 << (i == q - 1 ? '\\n' : ' ');\n \
    \   }\n}\n\nint main()\n{\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    int t = 1;\n    //cin >> t;\n    while (t--) solve();\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc328/tasks/abc328_f\"\n#include\
    \ \"my_template.hpp\"\n#include \"data_structure/Weighted_UnionFind.hpp\"\n\n\
    void solve()\n{\n    ll n, q; cin >> n >> q;\n    Weighted_UnionFind<ll> r(n);\n\
    \    rep(i, 0, q)\n    {\n        ll a, b, d; cin >> a >> b >> d; a--, b--;\n\
    \        if(r.unite(a, b, d)) cout << i + 1 << (i == q - 1 ? '\\n' : ' ');\n \
    \   }\n}\n\nint main()\n{\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    int t = 1;\n    //cin >> t;\n    while (t--) solve();\n}"
  dependsOn:
  - my_template.hpp
  - data_structure/Weighted_UnionFind.hpp
  isVerificationFile: true
  path: verify/test_atcoder/abc328_f.test.cpp
  requiredBy: []
  timestamp: '2024-05-05 04:16:28+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/test_atcoder/abc328_f.test.cpp
layout: document
redirect_from:
- /verify/verify/test_atcoder/abc328_f.test.cpp
- /verify/verify/test_atcoder/abc328_f.test.cpp.html
title: verify/test_atcoder/abc328_f.test.cpp
---
