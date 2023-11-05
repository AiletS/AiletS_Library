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
  - icon: ':warning:'
    path: graph/is_bipartite.hpp
    title: graph/is_bipartite.hpp
  - icon: ':warning:'
    path: graph/scc.hpp
    title: graph/scc.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/graph_base.hpp\"\n\ntemplate <typename T>\nstruct\
    \ Edge\n{\n    int from, to;\n    T cost;\n    int id;\n    Edge(int from, int\
    \ to, T cost, int id) : from(from), to(to), cost(cost), id(id) {}\n};\n\ntemplate\
    \ <typename T = long long, bool directed = false>\nstruct Graph\n{\n    using\
    \ cost_type = T;\n    int n, m;\n    vector<vector<Edge<T>>> G;\n    vector<int>\
    \ in_deg, out_deg;\n\n    Graph() {}\n    Graph(int N) \n    {\n        n = N;\n\
    \        G = vector<vector<Edge<T>>>(N);\n        in_deg = vector<int>(N, 0);\n\
    \        out_deg = vector<int>(N, 0);\n    }\n\n    vector<Edge<T>> operator[](int\
    \ x) const { return G[x]; }\n\n    void add(int from, int to, T cost = 1, int\
    \ id = -1)\\\n    {\n        if(id == -1) id = m;\n        G[from].emplace_back(from,\
    \ to, cost, id);\n        out_deg[from]++, in_deg[to]++;\n        if(directed\
    \ == false) \n        {\n            G[to].emplace_back(to, from, cost, id);\n\
    \            out_deg[to]++, in_deg[from]++;\n        }\n        m++;\n    }\n\n\
    \    void mkg(int M, bool weighted = false, int off = 1)\n    {\n        for(int\
    \ i = 0; i < M; i++)\n        {\n            int x, y; cin >> x >> y;\n      \
    \      x -= off, y -= off;\n            if(weighted == false) add(x, y);\n   \
    \         else { T z; cin >> z; add(x, y, z); }\n        }\n    }\n\n    void\
    \ mkg_ancestor(bool weighted = false, int off = 1)\n    {\n        for(int i =\
    \ 1; i < n; i++)\n        {\n            int x; cin >> x; x -= off;\n        \
    \    if(weighted == false) add(x, i);\n            else { T z; cin >> z; add(x,\
    \ i, z); }\n        }\n    }\n};\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct Edge\n{\n    int from, to;\n\
    \    T cost;\n    int id;\n    Edge(int from, int to, T cost, int id) : from(from),\
    \ to(to), cost(cost), id(id) {}\n};\n\ntemplate <typename T = long long, bool\
    \ directed = false>\nstruct Graph\n{\n    using cost_type = T;\n    int n, m;\n\
    \    vector<vector<Edge<T>>> G;\n    vector<int> in_deg, out_deg;\n\n    Graph()\
    \ {}\n    Graph(int N) \n    {\n        n = N;\n        G = vector<vector<Edge<T>>>(N);\n\
    \        in_deg = vector<int>(N, 0);\n        out_deg = vector<int>(N, 0);\n \
    \   }\n\n    vector<Edge<T>> operator[](int x) const { return G[x]; }\n\n    void\
    \ add(int from, int to, T cost = 1, int id = -1)\\\n    {\n        if(id == -1)\
    \ id = m;\n        G[from].emplace_back(from, to, cost, id);\n        out_deg[from]++,\
    \ in_deg[to]++;\n        if(directed == false) \n        {\n            G[to].emplace_back(to,\
    \ from, cost, id);\n            out_deg[to]++, in_deg[from]++;\n        }\n  \
    \      m++;\n    }\n\n    void mkg(int M, bool weighted = false, int off = 1)\n\
    \    {\n        for(int i = 0; i < M; i++)\n        {\n            int x, y; cin\
    \ >> x >> y;\n            x -= off, y -= off;\n            if(weighted == false)\
    \ add(x, y);\n            else { T z; cin >> z; add(x, y, z); }\n        }\n \
    \   }\n\n    void mkg_ancestor(bool weighted = false, int off = 1)\n    {\n  \
    \      for(int i = 1; i < n; i++)\n        {\n            int x; cin >> x; x -=\
    \ off;\n            if(weighted == false) add(x, i);\n            else { T z;\
    \ cin >> z; add(x, i, z); }\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_base.hpp
  requiredBy:
  - graph/is_bipartite.hpp
  - graph/dist_dijkstra.hpp
  - graph/scc.hpp
  - graph/dist_bfs.hpp
  timestamp: '2023-09-16 21:22:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph_base.hpp
layout: document
redirect_from:
- /library/graph/graph_base.hpp
- /library/graph/graph_base.hpp.html
title: graph/graph_base.hpp
---
