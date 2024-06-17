---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/dist_bfs.hpp
    title: graph/dist_bfs.hpp
  - icon: ':warning:'
    path: graph/dist_dijkstra.hpp
    title: graph/dist_dijkstra.hpp
  - icon: ':x:'
    path: graph/is_bipartite.hpp
    title: graph/is_bipartite.hpp
  - icon: ':heavy_check_mark:'
    path: graph/scc.hpp
    title: graph/scc.hpp
  - icon: ':warning:'
    path: graph/tree/CompressTree.hpp
    title: graph/tree/CompressTree.hpp
  - icon: ':x:'
    path: graph/tree/EulerTour.hpp
    title: graph/tree/EulerTour.hpp
  - icon: ':warning:'
    path: graph/tree/Rerooting_dp.hpp
    title: graph/tree/Rerooting_dp.hpp
  - icon: ':x:'
    path: graph/tree/lca.hpp
    title: graph/tree/lca.hpp
  - icon: ':x:'
    path: graph/tree/tree_base.hpp
    title: graph/tree/tree_base.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/library_checker/Lowest_Common_Ancestor.test.cpp
    title: verify/library_checker/Lowest_Common_Ancestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/Strongly_Connected_Components.test.cpp
    title: verify/library_checker/Strongly_Connected_Components.test.cpp
  - icon: ':x:'
    path: verify/test_atcoder/abc327_d.test.cpp
    title: verify/test_atcoder/abc327_d.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/graph_base.hpp\"\n\ntemplate <typename T>\nstruct\
    \ Edge\n{\n    int from, to;\n    T cost;\n    int id;\n    Edge(int from, int\
    \ to, T cost, int id) : from(from), to(to), cost(cost), id(id) {}\n};\n\n/*\n\
    Graph \u30E9\u30A4\u30D6\u30E9\u30EA\nGraph<T = long long, directed = false> (int\
    \ n) : n \u500B\u306E\u9802\u70B9\u3092\u6301\u3064\u30B0\u30E9\u30D5\nT \u306F\
    \u91CD\u307F\u306E\u578B\u3001directed\u306F\u6709\u5411\u304C\u7121\u5411\u304B\
    \ false \u306A\u3089\u7121\u5411\noperator[] \u304C\u5B9A\u7FA9\u3055\u308C\u3066\
    \u3044\u308B G[x] : x \u306E\u96A3\u63A5\u30EA\u30B9\u30C8\nadd(int from, int\
    \ to, T cost = 1, int id = -1) \u8FBA\u3092\u8FFD\u52A0\u3059\u308B\nmkg(int m,\
    \ bool weighted = false, int off = 1) \u5165\u529B\u304B\u3089\u30B0\u30E9\u30D5\
    \u3092\u4F5C\u308B m \u306F\u5909\u6570 off-index\nmkg_ancestor(bool weighted\
    \ = false, int off = 1) n-1\u8FBA\u306E\u30B0\u30E9\u30D5\u3092\u5165\u529B\u304B\
    \u3089\u4F5C\u308B\n*/\ntemplate <typename T = long long, bool directed = false>\n\
    struct Graph\n{\n    using cost_type = T;\n    int n, m;\n    vector<vector<Edge<T>>>\
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
    \   }\n    }\n};\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct Edge\n{\n    int from, to;\n\
    \    T cost;\n    int id;\n    Edge(int from, int to, T cost, int id) : from(from),\
    \ to(to), cost(cost), id(id) {}\n};\n\n/*\nGraph \u30E9\u30A4\u30D6\u30E9\u30EA\
    \nGraph<T = long long, directed = false> (int n) : n \u500B\u306E\u9802\u70B9\u3092\
    \u6301\u3064\u30B0\u30E9\u30D5\nT \u306F\u91CD\u307F\u306E\u578B\u3001directed\u306F\
    \u6709\u5411\u304C\u7121\u5411\u304B false \u306A\u3089\u7121\u5411\noperator[]\
    \ \u304C\u5B9A\u7FA9\u3055\u308C\u3066\u3044\u308B G[x] : x \u306E\u96A3\u63A5\
    \u30EA\u30B9\u30C8\nadd(int from, int to, T cost = 1, int id = -1) \u8FBA\u3092\
    \u8FFD\u52A0\u3059\u308B\nmkg(int m, bool weighted = false, int off = 1) \u5165\
    \u529B\u304B\u3089\u30B0\u30E9\u30D5\u3092\u4F5C\u308B m \u306F\u5909\u6570 off-index\n\
    mkg_ancestor(bool weighted = false, int off = 1) n-1\u8FBA\u306E\u30B0\u30E9\u30D5\
    \u3092\u5165\u529B\u304B\u3089\u4F5C\u308B\n*/\ntemplate <typename T = long long,\
    \ bool directed = false>\nstruct Graph\n{\n    using cost_type = T;\n    int n,\
    \ m;\n    vector<vector<Edge<T>>> G;\n    vector<Edge<T>> edges;\n    vector<int>\
    \ deg, in_deg, out_deg;\n\n    Graph() {}\n    Graph(int N) \n    {\n        n\
    \ = N; m = 0;\n        G = vector<vector<Edge<T>>>(N);\n        deg = vector<int>(N,\
    \ 0);\n        in_deg = vector<int>(N, 0);\n        out_deg = vector<int>(N, 0);\n\
    \    }\n\n    const vector<Edge<T>>& operator[](int x) const { return G[x]; }\n\
    \n    // \u8FBA\u3092\u8FFD\u52A0\n    void add(int from, int to, T cost = 1,\
    \ int id = -1)\\\n    {\n        if(id == -1) id = m++;\n        G[from].emplace_back(from,\
    \ to, cost, id);\n        edges.emplace_back(from, to, cost, id);\n        out_deg[from]++,\
    \ in_deg[to]++;\n        if(directed == false) \n        {\n            G[to].emplace_back(to,\
    \ from, cost, id);\n            out_deg[to]++, in_deg[from]++;\n        }\n  \
    \  }\n\n    void mkg(int M, bool weighted = false, int off = 1)\n    {\n     \
    \   for(int i = 0; i < M; i++)\n        {\n            int x, y; cin >> x >> y;\n\
    \            x -= off, y -= off;\n            if(weighted == false) add(x, y);\n\
    \            else { T z; cin >> z; add(x, y, z); }\n        }\n    }\n\n    void\
    \ mkg_ancestor(bool weighted = false, int off = 1)\n    {\n        for(int i =\
    \ 1; i < n; i++)\n        {\n            int x; cin >> x; x -= off;\n        \
    \    if(weighted == false) add(x, i);\n            else { T z; cin >> z; add(x,\
    \ i, z); }\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_base.hpp
  requiredBy:
  - graph/dist_dijkstra.hpp
  - graph/dist_bfs.hpp
  - graph/is_bipartite.hpp
  - graph/scc.hpp
  - graph/tree/EulerTour.hpp
  - graph/tree/lca.hpp
  - graph/tree/Rerooting_dp.hpp
  - graph/tree/CompressTree.hpp
  - graph/tree/tree_base.hpp
  timestamp: '2024-06-17 21:21:08+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/library_checker/Lowest_Common_Ancestor.test.cpp
  - verify/library_checker/Strongly_Connected_Components.test.cpp
  - verify/test_atcoder/abc327_d.test.cpp
documentation_of: graph/graph_base.hpp
layout: document
redirect_from:
- /library/graph/graph_base.hpp
- /library/graph/graph_base.hpp.html
title: graph/graph_base.hpp
---
