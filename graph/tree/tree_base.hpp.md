---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/tree/CompressTree.hpp
    title: graph/tree/CompressTree.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree/EulerTour.hpp
    title: graph/tree/EulerTour.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree/lca.hpp
    title: graph/tree/lca.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/Lowest_Common_Ancestor.test.cpp
    title: verify/library_checker/Lowest_Common_Ancestor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/tree/tree_base.hpp\"\n\ntemplate <typename T>\nstruct\
    \ Edge\n{\n    int from, to;\n    T cost;\n    int id;\n    Edge(int from, int\
    \ to, T cost, int id) : from(from), to(to), cost(cost), id(id) {}\n};\n\ntemplate\
    \ <typename T = long long, bool directed = false>\nstruct Tree\n{\n    using cost_type\
    \ = T;\n    int n, m, root;\n    vector<vector<Edge<T>>> G;\n    vector<Edge<T>>\
    \ edges;\n    vector<int> in_deg, out_deg;\n\n    Tree() {}\n    Tree(int N, int\
    \ ROOT = 0) \n    {\n        n = N; m = 0, root = ROOT;\n        G = vector<vector<Edge<T>>>(N);\n\
    \        in_deg = vector<int>(N, 0);\n        out_deg = vector<int>(N, 0);\n \
    \   }\n\n    vector<Edge<T>> operator[](int x) const { return G[x]; }\n\n    void\
    \ add(int from, int to, T cost = 1, int id = -1)\n    {\n        assert(from >=\
    \ 0 && from < n && to >= 0 && to < n);\n        if(id == -1) id = m++;\n     \
    \   G[from].emplace_back(from, to, cost, id);\n        edges.emplace_back(from,\
    \ to, cost, id);\n        out_deg[from]++, in_deg[to]++;\n        if(directed\
    \ == false) \n        {\n            G[to].emplace_back(to, from, cost, id);\n\
    \            out_deg[to]++, in_deg[from]++;\n        }\n    }\n\n    void mkg(bool\
    \ weighted = false, int off = 1)\n    {\n        for(int i = 0; i < n - 1; i++)\n\
    \        {\n            int x, y; cin >> x >> y;\n            x -= off, y -= off;\n\
    \            if(weighted == false) add(x, y);\n            else { T z; cin >>\
    \ z; add(x, y, z); }\n        }\n    }\n\n    void mkg_ancestor(bool weighted\
    \ = false, int off = 1)\n    {\n        for(int i = 1; i < n; i++)\n        {\n\
    \            int x; cin >> x; x -= off;\n            if(weighted == false) add(x,\
    \ i);\n            else { T z; cin >> z; add(x, i, z); }\n        }\n    }\n};\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct Edge\n{\n    int from, to;\n\
    \    T cost;\n    int id;\n    Edge(int from, int to, T cost, int id) : from(from),\
    \ to(to), cost(cost), id(id) {}\n};\n\ntemplate <typename T = long long, bool\
    \ directed = false>\nstruct Tree\n{\n    using cost_type = T;\n    int n, m, root;\n\
    \    vector<vector<Edge<T>>> G;\n    vector<Edge<T>> edges;\n    vector<int> in_deg,\
    \ out_deg;\n\n    Tree() {}\n    Tree(int N, int ROOT = 0) \n    {\n        n\
    \ = N; m = 0, root = ROOT;\n        G = vector<vector<Edge<T>>>(N);\n        in_deg\
    \ = vector<int>(N, 0);\n        out_deg = vector<int>(N, 0);\n    }\n\n    vector<Edge<T>>\
    \ operator[](int x) const { return G[x]; }\n\n    void add(int from, int to, T\
    \ cost = 1, int id = -1)\n    {\n        assert(from >= 0 && from < n && to >=\
    \ 0 && to < n);\n        if(id == -1) id = m++;\n        G[from].emplace_back(from,\
    \ to, cost, id);\n        edges.emplace_back(from, to, cost, id);\n        out_deg[from]++,\
    \ in_deg[to]++;\n        if(directed == false) \n        {\n            G[to].emplace_back(to,\
    \ from, cost, id);\n            out_deg[to]++, in_deg[from]++;\n        }\n  \
    \  }\n\n    void mkg(bool weighted = false, int off = 1)\n    {\n        for(int\
    \ i = 0; i < n - 1; i++)\n        {\n            int x, y; cin >> x >> y;\n  \
    \          x -= off, y -= off;\n            if(weighted == false) add(x, y);\n\
    \            else { T z; cin >> z; add(x, y, z); }\n        }\n    }\n\n    void\
    \ mkg_ancestor(bool weighted = false, int off = 1)\n    {\n        for(int i =\
    \ 1; i < n; i++)\n        {\n            int x; cin >> x; x -= off;\n        \
    \    if(weighted == false) add(x, i);\n            else { T z; cin >> z; add(x,\
    \ i, z); }\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree/tree_base.hpp
  requiredBy:
  - graph/tree/EulerTour.hpp
  - graph/tree/CompressTree.hpp
  - graph/tree/lca.hpp
  timestamp: '2024-05-03 01:16:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/Lowest_Common_Ancestor.test.cpp
documentation_of: graph/tree/tree_base.hpp
layout: document
redirect_from:
- /library/graph/tree/tree_base.hpp
- /library/graph/tree/tree_base.hpp.html
title: graph/tree/tree_base.hpp
---
