---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/UnionFind.hpp
    title: data_structure/UnionFind.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"verify/library_checker/Unionfind.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/unionfind\"\n#line 2 \"my_template.hpp\"\n\
    #pragma GCC optimize(\"O3\")\n#include <bits/stdc++.h>\nusing namespace std;\n\
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
    \ v) p++; }\n#line 2 \"data_structure/UnionFind.hpp\"\n\n/* \nUnionFind\nUnionfind(int\
    \ n) \u30B5\u30A4\u30BA n \u3067\u751F\u6210\nfind(int x) x \u306E\u4EE3\u8868\
    \u3092\u53D6\u5F97\nunite(int x, int y) x, y \u3092\u7D50\u5408\nsame(int x, int\
    \ y) x, y \u304C\u540C\u3058\u30B0\u30EB\u30FC\u30D7\u3067\u3042\u308B\u304B\u3092\
    \u53D6\u5F97\ngroup() \u73FE\u5728\u306E\u30B0\u30EB\u30FC\u30D7\u306E\u500B\u6570\
    \u3092\u53D6\u5F97\nsize(int x) x \u304C\u542B\u307E\u308C\u3066\u3044\u308B\u30B0\
    \u30EB\u30FC\u30D7\u306E\u30B5\u30A4\u30BA\u3092\u53D6\u5F97\n*/\nstruct UnionFind\n\
    {\n\tUnionFind(int n) : gr(n), par(n), rk(n, 0), SIZE(n, 1) // initialize\n\t\
    {\n\t\tiota(par.begin(), par.end(), 0);\n\t}\n\n\tint find(int x) // find parent\n\
    \t{\n\t\tif (par[x] == x) return x;\n\t\telse return par[x] = find(par[x]);\n\t\
    }\n\n\tbool unite(int x, int y) // unite two nodes\n\t{\n\t\tx = find(x), y =\
    \ find(y);\n\t\tif (x == y) return false;\n\n\t\tgr--;\n\t\tif (rk[x] < rk[y])\
    \ { par[x] = y, SIZE[y] += SIZE[x]; }\n\t\telse\n\t\t{\n\t\t\tpar[y] = x; SIZE[x]\
    \ += SIZE[y];\n\t\t\tif (rk[x] == rk[y]) rk[x]++;\n\t\t}\n\t\treturn true;\n\t\
    }\n\n\tbool same(int x, int y) { return find(x) == find(y); }\n\t// judge two\
    \ nodes' parents are the same\n\n\tint group() { return gr; }\n\t// total number\
    \ of connectivity components\n\n\tint size(int x) { return SIZE[find(x)]; }\n\t\
    // number of nodes in the connection component containing x  \n\nprivate:\n\t\
    vector<int> par, rk, SIZE;\n\tint gr;\n};\n#line 4 \"verify/library_checker/Unionfind.test.cpp\"\
    \n\nvoid solve()\n{\n    int n, q; cin >> n >> q;\n    UnionFind r(n);\n    while(q--)\n\
    \    {\n        int t, u, v; cin >> t >> u >> v;\n        if(t == 0) r.unite(u,\
    \ v);\n        else cout << (r.same(u, v) ? 1 : 0) << '\\n';\n    }\n}\n\nint\
    \ main()\n{\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n  \
    \  int t = 1;\n    //cin >> t;\n    while (t--) solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include \"\
    my_template.hpp\"\n#include \"data_structure/UnionFind.hpp\"\n\nvoid solve()\n\
    {\n    int n, q; cin >> n >> q;\n    UnionFind r(n);\n    while(q--)\n    {\n\
    \        int t, u, v; cin >> t >> u >> v;\n        if(t == 0) r.unite(u, v);\n\
    \        else cout << (r.same(u, v) ? 1 : 0) << '\\n';\n    }\n}\n\nint main()\n\
    {\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n    int t = 1;\n\
    \    //cin >> t;\n    while (t--) solve();\n}"
  dependsOn:
  - my_template.hpp
  - data_structure/UnionFind.hpp
  isVerificationFile: true
  path: verify/library_checker/Unionfind.test.cpp
  requiredBy: []
  timestamp: '2024-05-03 18:59:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/Unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/Unionfind.test.cpp
- /verify/verify/library_checker/Unionfind.test.cpp.html
title: verify/library_checker/Unionfind.test.cpp
---
