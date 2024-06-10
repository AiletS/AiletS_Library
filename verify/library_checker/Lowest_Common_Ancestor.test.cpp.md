---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/SparseTable.hpp
    title: data_structure/SparseTable.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree/EulerTour.hpp
    title: graph/tree/EulerTour.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree/lca.hpp
    title: graph/tree/lca.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree/tree_base.hpp
    title: graph/tree/tree_base.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"verify/library_checker/Lowest_Common_Ancestor.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#line 2 \"my_template.hpp\"\
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
    \ v) p++; }\n#line 2 \"graph/tree/lca.hpp\"\n\n#line 2 \"graph/tree/tree_base.hpp\"\
    \n\ntemplate <typename T>\nstruct Edge\n{\n    int from, to;\n    T cost;\n  \
    \  int id;\n    Edge(int from, int to, T cost, int id) : from(from), to(to), cost(cost),\
    \ id(id) {}\n};\n\ntemplate <typename T = long long, bool directed = false>\n\
    struct Tree\n{\n    using cost_type = T;\n    int n, m, root;\n    vector<vector<Edge<T>>>\
    \ G;\n    vector<Edge<T>> edges;\n    vector<int> in_deg, out_deg;\n\n    Tree()\
    \ {}\n    Tree(int N, int ROOT = 0) \n    {\n        n = N; m = 0, root = ROOT;\n\
    \        G = vector<vector<Edge<T>>>(N);\n        in_deg = vector<int>(N, 0);\n\
    \        out_deg = vector<int>(N, 0);\n    }\n\n    vector<Edge<T>> operator[](int\
    \ x) const { return G[x]; }\n\n    void add(int from, int to, T cost = 1, int\
    \ id = -1)\n    {\n        assert(from >= 0 && from < n && to >= 0 && to < n);\n\
    \        if(id == -1) id = m++;\n        G[from].emplace_back(from, to, cost,\
    \ id);\n        edges.emplace_back(from, to, cost, id);\n        out_deg[from]++,\
    \ in_deg[to]++;\n        if(directed == false) \n        {\n            G[to].emplace_back(to,\
    \ from, cost, id);\n            out_deg[to]++, in_deg[from]++;\n        }\n  \
    \  }\n\n    void mkg(bool weighted = false, int off = 1)\n    {\n        for(int\
    \ i = 0; i < n - 1; i++)\n        {\n            int x, y; cin >> x >> y;\n  \
    \          x -= off, y -= off;\n            if(weighted == false) add(x, y);\n\
    \            else { T z; cin >> z; add(x, y, z); }\n        }\n    }\n\n    void\
    \ mkg_ancestor(bool weighted = false, int off = 1)\n    {\n        for(int i =\
    \ 1; i < n; i++)\n        {\n            int x; cin >> x; x -= off;\n        \
    \    if(weighted == false) add(x, i);\n            else { T z; cin >> z; add(x,\
    \ i, z); }\n        }\n    }\n};\n#line 2 \"graph/tree/EulerTour.hpp\"\n\n#line\
    \ 4 \"graph/tree/EulerTour.hpp\"\n\n/*\n\u6728\u4E0A\u3067Euler Tour\u3092\u884C\
    \u3046\ntuple<vector<int>, vector<int>, vector<pair<int, int>>>\n= {in, out, {depth,\
    \ \u9802\u70B9}}\n*/\ntemplate <class TREE>\ntuple<vector<int>, vector<int>, vector<pair<int,\
    \ int>>>\nEulerTour(const TREE& g)\n{\n    const int n = g.n, m = g.m;\n    vector<int>\
    \ in(n), out(n);\n    vector<pair<int, int>> v;\n\n    function<void(int, int,\
    \ int)> dfs = [&](int U, int V, int depth) -> void\n    {\n        assert(U >=\
    \ 0 && U < n);\n        in[U] = v.size();\n        v.emplace_back(depth, U);\n\
    \        for(auto [from, to, _, __] : g[U])\n        {\n            if(to == V)\
    \ continue;\n            dfs(to, from, depth + 1);\n        }\n        out[U]\
    \ = v.size();\n        v.emplace_back(depth - 1, V);\n    };\n\n    dfs(g.root,\
    \ -1, 0);\n    return { in, out, v };\n}\n#line 2 \"data_structure/SparseTable.hpp\"\
    \n\n/*\n\u51AA\u7B49\u306A Monoid \u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B\
    \ (f(f(x)) = f(x))\n\u51AA\u7B49\u6027\u3068\u7D50\u5408\u6E2C\u304C\u6E80\u305F\
    \u3055\u308C\u308C\u3070\u826F\u3044\n\nSparseTable\nSparseTable<monoid>(vector<monoid::TYPE>\
    \ v)\nget(int l, int r) [l, r) \u306E\u7D50\u679C\u3092\u53D6\u5F97\n*/\ntemplate\
    \ <class Monoid>\nstruct SparseTable\n{\n    using T = typename Monoid::TYPE;\n\
    \    SparseTable() {}\n    SparseTable(const vector<T>& _v) : n(_v.size()), w(n\
    \ + 1)\n    {\n        for (int i = 2; i < n + 1; i++) w[i] = w[i >> 1] + 1;\n\
    \t\tv = vector<vector<T>>(w[n] + 1, vector<T>(n, Monoid::e()));\n\t\tfor (int\
    \ i = 0; i < n; i++) v[0][i] = _v[i];\n\t\tfor (int i = 1; (1 << i) <= n; i++)\n\
    \t\t\tfor (int j = 0; j + (1 << i) <= n; j++)\n\t\t\t{\n\t\t\t\tv[i][j] = Monoid::op(v[i\
    \ - 1][j], v[i - 1][j + (1 << (i - 1))]);\n\t\t\t}\n    }\n\n    T get(int l,\
    \ int r)\n    {\n        assert(l <= r && l >= 0 && l < n && r >= 0 && r <= n);\n\
    \        int k = w[r - l];\n\t\treturn Monoid::op(v[k][l], v[k][r - (1 << k)]);\n\
    \    }\n\nprivate:\n    int n;\n    vector<int> w;\n    vector<vector<T>> v;\n\
    };\n#line 6 \"graph/tree/lca.hpp\"\n\ntemplate <class _S>\nstruct Monoid_LCA\n\
    {\n    using TYPE = _S;\n    static TYPE op(TYPE& a, TYPE& b)\n    {\n       \
    \ if(a.first < b.first) return a;\n        else return b;\n    };\n    static\
    \ TYPE e() { return make_pair(infty<int>, -1); };\n};\n\ntemplate <class TREE>\n\
    struct LCA\n{\n    TREE& g;\n    int n;\n    vector<int> in, out;\n    vector<pair<int,\
    \ int>> v;\n    SparseTable<Monoid_LCA<pair<int, int>>> sp;\n\n    LCA() {}\n\
    \    LCA(TREE& _g) : n(_g.n), g(_g), in(n), out(n) \n    {\n        tie(in, out,\
    \ v) = EulerTour(_g);\n        sp = SparseTable<Monoid_LCA<pair<int, int>>>(v);\n\
    \    }\n\n    int get(int x, int y)\n    {\n        int l = in[x], r = in[y];\n\
    \        if(l > r) swap(l, r);\n        return sp.get(l, r + 1).second;\n    }\n\
    };\n#line 4 \"verify/library_checker/Lowest_Common_Ancestor.test.cpp\"\n\nvoid\
    \ solve()\n{\n    int n, q; cin >> n >> q;\n    Tree g(n); g.mkg_ancestor(false,\
    \ 0);\n    LCA lca(g);\n    while(q--)\n    {\n        int u, v; cin >> u >> v;\n\
    \        cout << lca.get(u, v) << '\\n';\n    }\n}\n\nint main()\n{\n    ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    int t = 1;\n    //cin >> t;\n    while (t--)\
    \ solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include \"my_template.hpp\"\
    \n#include \"graph/tree/lca.hpp\"\n\nvoid solve()\n{\n    int n, q; cin >> n >>\
    \ q;\n    Tree g(n); g.mkg_ancestor(false, 0);\n    LCA lca(g);\n    while(q--)\n\
    \    {\n        int u, v; cin >> u >> v;\n        cout << lca.get(u, v) << '\\\
    n';\n    }\n}\n\nint main()\n{\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    int t = 1;\n    //cin >> t;\n    while (t--) solve();\n}"
  dependsOn:
  - my_template.hpp
  - graph/tree/lca.hpp
  - graph/tree/tree_base.hpp
  - graph/tree/EulerTour.hpp
  - data_structure/SparseTable.hpp
  isVerificationFile: true
  path: verify/library_checker/Lowest_Common_Ancestor.test.cpp
  requiredBy: []
  timestamp: '2024-05-03 18:59:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/Lowest_Common_Ancestor.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/Lowest_Common_Ancestor.test.cpp
- /verify/verify/library_checker/Lowest_Common_Ancestor.test.cpp.html
title: verify/library_checker/Lowest_Common_Ancestor.test.cpp
---
