---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/SparseTable.hpp
    title: data_structure/SparseTable.hpp
  - icon: ':heavy_check_mark:'
    path: graph/graph_base.hpp
    title: graph/graph_base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree/EulerTour.hpp
    title: graph/tree/EulerTour.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree/tree_base.hpp
    title: graph/tree/tree_base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/tree/CompressTree.hpp
    title: graph/tree/CompressTree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/Lowest_Common_Ancestor.test.cpp
    title: verify/library_checker/Lowest_Common_Ancestor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/tree/lca.hpp\"\n\n#line 2 \"graph/tree/tree_base.hpp\"\
    \n\n#line 2 \"graph/graph_base.hpp\"\n\ntemplate <typename T>\nstruct Edge\n{\n\
    \    int from, to;\n    T cost;\n    int id;\n    Edge(int from, int to, T cost,\
    \ int id) : from(from), to(to), cost(cost), id(id) {}\n};\n\n/*\nGraph \u30E9\u30A4\
    \u30D6\u30E9\u30EA\nGraph<T = long long, directed = false> (int n) : n \u500B\u306E\
    \u9802\u70B9\u3092\u6301\u3064\u30B0\u30E9\u30D5\nT \u306F\u91CD\u307F\u306E\u578B\
    \u3001directed\u306F\u6709\u5411\u304C\u7121\u5411\u304B false \u306A\u3089\u7121\
    \u5411\noperator[] \u304C\u5B9A\u7FA9\u3055\u308C\u3066\u3044\u308B G[x] : x \u306E\
    \u96A3\u63A5\u30EA\u30B9\u30C8\nadd(int from, int to, T cost = 1, int id = -1)\
    \ \u8FBA\u3092\u8FFD\u52A0\u3059\u308B\nmkg(int m, bool weighted = false, int\
    \ off = 1) \u5165\u529B\u304B\u3089\u30B0\u30E9\u30D5\u3092\u4F5C\u308B m \u306F\
    \u5909\u6570 off-index\nmkg_ancestor(bool weighted = false, int off = 1) n-1\u8FBA\
    \u306E\u30B0\u30E9\u30D5\u3092\u5165\u529B\u304B\u3089\u4F5C\u308B\n*/\ntemplate\
    \ <typename T = long long, bool directed = false>\nstruct Graph\n{\n    using\
    \ cost_type = T;\n    int n, m;\n    vector<vector<Edge<T>>> G;\n    vector<Edge<T>>\
    \ edges;\n    vector<int> deg, in_deg, out_deg;\n\n    Graph() {}\n    Graph(int\
    \ N)\n    {\n        n = N; m = 0;\n        G = vector<vector<Edge<T>>>(N);\n\
    \        deg = vector<int>(N, 0);\n        in_deg = vector<int>(N, 0);\n     \
    \   out_deg = vector<int>(N, 0);\n    }\n\n    const vector<Edge<T>>& operator[](int\
    \ x) const { return G[x]; }\n\n    // \u8FBA\u3092\u8FFD\u52A0\n    void add(int\
    \ from, int to, T cost = 1, int id = -1)\\\n    {\n        assert(from >= 0 &&\
    \ from < n && to >= 0 && to < n);\n        if(id == -1) id = m++;\n        G[from].emplace_back(from,\
    \ to, cost, id);\n        edges.emplace_back(from, to, cost, id);\n        out_deg[from]++,\
    \ in_deg[to]++;\n        if(directed == false)\n        {\n            G[to].emplace_back(to,\
    \ from, cost, id);\n            out_deg[to]++, in_deg[from]++;\n        }\n  \
    \  }\n\n    void mkg(int M, bool weighted = false, int off = 1)\n    {\n     \
    \   for(int i = 0; i < M; i++)\n        {\n            int x, y; cin >> x >> y;\n\
    \            x -= off, y -= off;\n            if(weighted == false) add(x, y);\n\
    \            else { T z; cin >> z; add(x, y, z); }\n        }\n    }\n\n    void\
    \ mkg_ancestor(bool weighted = false, int off = 1)\n    {\n        for(int i =\
    \ 1; i < n; i++)\n        {\n            int x; cin >> x; x -= off;\n        \
    \    if(weighted == false) add(x, i);\n            else { T z; cin >> z; add(x,\
    \ i, z); }\n        }\n    }\n};\n#line 4 \"graph/tree/tree_base.hpp\"\n\ntemplate\
    \ <class GT>\nstruct Tree\n{\n    using Graph_type = GT;\n    using cost_type\
    \ = typename GT::cost_type;\n    GT& G;\n    int n, root;\n    vector<int> depth,\
    \ parent;\n\n    Tree() {}\n    Tree(GT& G, int root = 0) : G(G), root(root) {\
    \ build(); }\n    const vector<Edge<cost_type>>& operator[](int x) const\n   \
    \     { assert(x >= 0 && x < n); return G[x]; }\n\n    void build()\n    {\n \
    \       n = G.n;\n        depth.assign(n, -1), parent.assign(n, -1);\n       \
    \ dfs(root, -1);\n    }\n\n    void dfs(int U, int V)\n    {\n        parent[U]\
    \ = V;\n        depth[U] = (V == -1 ? 0 : depth[V] + 1);\n        for(auto [from,\
    \ to, _, __] : G[U])\n        {\n            if(to == V) continue;\n         \
    \   dfs(to, from);\n        }\n    }\n};\n#line 2 \"graph/tree/EulerTour.hpp\"\
    \n\n#line 4 \"graph/tree/EulerTour.hpp\"\n\n/*\n\u6728\u4E0A\u3067Euler Tour\u3092\
    \u884C\u3046\ntuple<vector<int>, vector<int>, vector<pair<int, int>>>\n= {in,\
    \ out, {depth, \u9802\u70B9}}\n*/\ntemplate <class TREE>\ntuple<vector<int>, vector<int>,\
    \ vector<pair<int, int>>>\nEulerTour(const TREE& g)\n{\n    const int n = g.n;\n\
    \    vector<int> in(n), out(n);\n    vector<pair<int, int>> v;\n\n    function<void(int,\
    \ int, int)> dfs = [&](int U, int V, int depth) -> void\n    {\n        assert(U\
    \ >= 0 && U < n);\n        in[U] = v.size();\n        v.emplace_back(depth, U);\n\
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
    \    LCA(TREE& _g) : n(_g.n), g(_g), in(n), out(n)\n    {\n        tie(in, out,\
    \ v) = EulerTour(_g);\n        sp = SparseTable<Monoid_LCA<pair<int, int>>>(v);\n\
    \    }\n\n    int get(int x, int y)\n    {\n        assert(x >= 0 && x < n &&\
    \ y >= 0 && y < n);\n        int l = in[x], r = in[y];\n        if(l > r) swap(l,\
    \ r);\n        return sp.get(l, r + 1).second;\n    }\n};\n"
  code: "#pragma once\n\n#include \"graph/tree/tree_base.hpp\"\n#include \"graph/tree/EulerTour.hpp\"\
    \n#include \"data_structure/SparseTable.hpp\"\n\ntemplate <class _S>\nstruct Monoid_LCA\n\
    {\n    using TYPE = _S;\n    static TYPE op(TYPE& a, TYPE& b)\n    {\n       \
    \ if(a.first < b.first) return a;\n        else return b;\n    };\n    static\
    \ TYPE e() { return make_pair(infty<int>, -1); };\n};\n\ntemplate <class TREE>\n\
    struct LCA\n{\n    TREE& g;\n    int n;\n    vector<int> in, out;\n    vector<pair<int,\
    \ int>> v;\n    SparseTable<Monoid_LCA<pair<int, int>>> sp;\n\n    LCA() {}\n\
    \    LCA(TREE& _g) : n(_g.n), g(_g), in(n), out(n)\n    {\n        tie(in, out,\
    \ v) = EulerTour(_g);\n        sp = SparseTable<Monoid_LCA<pair<int, int>>>(v);\n\
    \    }\n\n    int get(int x, int y)\n    {\n        assert(x >= 0 && x < n &&\
    \ y >= 0 && y < n);\n        int l = in[x], r = in[y];\n        if(l > r) swap(l,\
    \ r);\n        return sp.get(l, r + 1).second;\n    }\n};"
  dependsOn:
  - graph/tree/tree_base.hpp
  - graph/graph_base.hpp
  - graph/tree/EulerTour.hpp
  - data_structure/SparseTable.hpp
  isVerificationFile: false
  path: graph/tree/lca.hpp
  requiredBy:
  - graph/tree/CompressTree.hpp
  timestamp: '2024-07-07 18:01:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/Lowest_Common_Ancestor.test.cpp
documentation_of: graph/tree/lca.hpp
layout: document
redirect_from:
- /library/graph/tree/lca.hpp
- /library/graph/tree/lca.hpp.html
title: graph/tree/lca.hpp
---
