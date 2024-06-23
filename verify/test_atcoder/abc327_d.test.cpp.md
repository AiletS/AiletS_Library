---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_base.hpp
    title: graph/graph_base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/is_bipartite.hpp
    title: graph/is_bipartite.hpp
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
    PROBLEM: https://atcoder.jp/contests/abc327/tasks/abc327_d
    links:
    - https://atcoder.jp/contests/abc327/tasks/abc327_d
  bundledCode: "#line 1 \"verify/test_atcoder/abc327_d.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc327/tasks/abc327_d\"\n#line 2 \"my_template.hpp\"\
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
    \ v) p++; }\n#line 2 \"graph/is_bipartite.hpp\"\n\n#line 2 \"graph/graph_base.hpp\"\
    \n\ntemplate <typename T>\nstruct Edge\n{\n    int from, to;\n    T cost;\n  \
    \  int id;\n    Edge(int from, int to, T cost, int id) : from(from), to(to), cost(cost),\
    \ id(id) {}\n};\n\n/*\nGraph \u30E9\u30A4\u30D6\u30E9\u30EA\nGraph<T = long long,\
    \ directed = false> (int n) : n \u500B\u306E\u9802\u70B9\u3092\u6301\u3064\u30B0\
    \u30E9\u30D5\nT \u306F\u91CD\u307F\u306E\u578B\u3001directed\u306F\u6709\u5411\
    \u304C\u7121\u5411\u304B false \u306A\u3089\u7121\u5411\noperator[] \u304C\u5B9A\
    \u7FA9\u3055\u308C\u3066\u3044\u308B G[x] : x \u306E\u96A3\u63A5\u30EA\u30B9\u30C8\
    \nadd(int from, int to, T cost = 1, int id = -1) \u8FBA\u3092\u8FFD\u52A0\u3059\
    \u308B\nmkg(int m, bool weighted = false, int off = 1) \u5165\u529B\u304B\u3089\
    \u30B0\u30E9\u30D5\u3092\u4F5C\u308B m \u306F\u5909\u6570 off-index\nmkg_ancestor(bool\
    \ weighted = false, int off = 1) n-1\u8FBA\u306E\u30B0\u30E9\u30D5\u3092\u5165\
    \u529B\u304B\u3089\u4F5C\u308B\n*/\ntemplate <typename T = long long, bool directed\
    \ = false>\nstruct Graph\n{\n    using cost_type = T;\n    int n, m;\n    vector<vector<Edge<T>>>\
    \ G;\n    vector<Edge<T>> edges;\n    vector<int> deg, in_deg, out_deg;\n\n  \
    \  Graph() {}\n    Graph(int N) \n    {\n        n = N; m = 0;\n        G = vector<vector<Edge<T>>>(N);\n\
    \        deg = vector<int>(N, 0);\n        in_deg = vector<int>(N, 0);\n     \
    \   out_deg = vector<int>(N, 0);\n    }\n\n    const vector<Edge<T>>& operator[](int\
    \ x) const { return G[x]; }\n\n    // \u8FBA\u3092\u8FFD\u52A0\n    void add(int\
    \ from, int to, T cost = 1, int id = -1)\\\n    {\n        if(id == -1) id = m++;\n\
    \        G[from].emplace_back(from, to, cost, id);\n        edges.emplace_back(from,\
    \ to, cost, id);\n        out_deg[from]++, in_deg[to]++;\n        if(directed\
    \ == false) \n        {\n            G[to].emplace_back(to, from, cost, id);\n\
    \            out_deg[to]++, in_deg[from]++;\n        }\n    }\n\n    void mkg(int\
    \ M, bool weighted = false, int off = 1)\n    {\n        for(int i = 0; i < M;\
    \ i++)\n        {\n            int x, y; cin >> x >> y;\n            x -= off,\
    \ y -= off;\n            if(weighted == false) add(x, y);\n            else {\
    \ T z; cin >> z; add(x, y, z); }\n        }\n    }\n\n    void mkg_ancestor(bool\
    \ weighted = false, int off = 1)\n    {\n        for(int i = 1; i < n; i++)\n\
    \        {\n            int x; cin >> x; x -= off;\n            if(weighted ==\
    \ false) add(x, i);\n            else { T z; cin >> z; add(x, i, z); }\n     \
    \   }\n    }\n};\n#line 4 \"graph/is_bipartite.hpp\"\n\ntemplate <class G>\nbool\
    \ is_bipartite(G &g)\n{\n    int n = g.n;\n    bool res = true;\n    vector<int>\
    \ color(n, -1);\n    auto dfs = [&](auto dfs, int U, int V) -> void\n    {\n \
    \       for(auto [from, to, _, __] : g[U])\n        {\n            if(color[to]\
    \ >= 0)\n            {\n                if(color[from] == color[to]) res = false;\n\
    \                continue;\n            }\n            color[to] = color[from]\
    \ ^ 1;\n            dfs(dfs, to, from);\n        }\n    };\n    for(int i = 0;\
    \ i < n; i++)\n    {\n        if(color[i] >= 0) continue;\n        color[i] =\
    \ 0;\n        dfs(dfs, i, -1);\n    }\n    return res;\n}\n#line 4 \"verify/test_atcoder/abc327_d.test.cpp\"\
    \n\nvoid solve()\n{\n    int n, m; cin >> n >> m;\n    Graph<int, false> g(n);\n\
    \    vi a(m), b(m);\n    rep(i, 0, m) cin >> a[i], a[i]--;\n    rep(i, 0, m) cin\
    \ >> b[i], b[i]--;\n    rep(i, 0, m) g.add(a[i], b[i]);\n    bool ok = is_bipartite(g);\n\
    \    if(ok) cout << \"Yes\" << '\\n';\n    else cout << \"No\" << '\\n';\n}\n\n\
    int main()\n{\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    int t = 1;\n    //cin >> t;\n    while (t--) solve();\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc327/tasks/abc327_d\"\n#include\
    \ \"my_template.hpp\"\n#include \"graph/is_bipartite.hpp\"\n\nvoid solve()\n{\n\
    \    int n, m; cin >> n >> m;\n    Graph<int, false> g(n);\n    vi a(m), b(m);\n\
    \    rep(i, 0, m) cin >> a[i], a[i]--;\n    rep(i, 0, m) cin >> b[i], b[i]--;\n\
    \    rep(i, 0, m) g.add(a[i], b[i]);\n    bool ok = is_bipartite(g);\n    if(ok)\
    \ cout << \"Yes\" << '\\n';\n    else cout << \"No\" << '\\n';\n}\n\nint main()\n\
    {\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n    int t = 1;\n\
    \    //cin >> t;\n    while (t--) solve();\n}"
  dependsOn:
  - my_template.hpp
  - graph/is_bipartite.hpp
  - graph/graph_base.hpp
  isVerificationFile: true
  path: verify/test_atcoder/abc327_d.test.cpp
  requiredBy: []
  timestamp: '2024-06-17 21:21:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/test_atcoder/abc327_d.test.cpp
layout: document
redirect_from:
- /verify/verify/test_atcoder/abc327_d.test.cpp
- /verify/verify/test_atcoder/abc327_d.test.cpp.html
title: verify/test_atcoder/abc327_d.test.cpp
---
