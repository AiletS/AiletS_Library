---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: graph/graph_base.hpp
    title: graph/graph_base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/is_bipartite.hpp\"\n\n#line 2 \"graph/graph_base.hpp\"\
    \n\ntemplate <typename T>\nstruct Edge\n{\n    int from, to;\n    T cost;\n  \
    \  int id;\n    Edge(int from, int to, T cost, int id) : from(from), to(to), cost(cost),\
    \ id(id) {}\n};\n\ntemplate <typename T = long long, bool directed = false>\n\
    struct Graph\n{\n    using cost_type = T;\n    int n, m;\n    vector<vector<Edge<T>>>\
    \ G;\n    vector<int> in_deg, out_deg;\n\n    Graph() {}\n    Graph(int N) \n\
    \    {\n        n = N;\n        G = vector<vector<Edge<T>>>(N);\n        in_deg\
    \ = vector<int>(N, 0);\n        out_deg = vector<int>(N, 0);\n    }\n\n    vector<Edge<T>>\
    \ operator[](int x) const { return G[x]; }\n\n    void add(int from, int to, T\
    \ cost = 1, int id = -1)\\\n    {\n        if(id == -1) id = m;\n        G[from].emplace_back(from,\
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
    \ i, z); }\n        }\n    }\n};\n#line 4 \"graph/is_bipartite.hpp\"\n\ntemplate\
    \ <class G>\nbool is_bipartite(G &g)\n{\n    int n = g.n;\n    bool res = true;\n\
    \    vector<int> color(n, -1);\n    auto dfs = [&](auto dfs, int U, int V) ->\
    \ void\n    {\n        for(auto [from, to, _, __] : g[U])\n        {\n       \
    \     if(color[to] >= 0)\n            {\n                if(color[from] == color[to])\
    \ res = false;\n                continue;\n            }\n            color[to]\
    \ = color[from] ^ 1;\n            dfs(dfs, to, from);\n        }\n    };\n   \
    \ for(int i = 0; i < n; i++)\n    {\n        if(color[i] >= 0) continue;\n   \
    \     color[i] = 0;\n        dfs(dfs, i, -1);\n    }\n    return res;\n}\n"
  code: "#pragma once\n\n#include \"/home/ailets/AiletS_Library/graph/graph_base.hpp\"\
    \n\ntemplate <class G>\nbool is_bipartite(G &g)\n{\n    int n = g.n;\n    bool\
    \ res = true;\n    vector<int> color(n, -1);\n    auto dfs = [&](auto dfs, int\
    \ U, int V) -> void\n    {\n        for(auto [from, to, _, __] : g[U])\n     \
    \   {\n            if(color[to] >= 0)\n            {\n                if(color[from]\
    \ == color[to]) res = false;\n                continue;\n            }\n     \
    \       color[to] = color[from] ^ 1;\n            dfs(dfs, to, from);\n      \
    \  }\n    };\n    for(int i = 0; i < n; i++)\n    {\n        if(color[i] >= 0)\
    \ continue;\n        color[i] = 0;\n        dfs(dfs, i, -1);\n    }\n    return\
    \ res;\n}"
  dependsOn:
  - graph/graph_base.hpp
  isVerificationFile: false
  path: graph/is_bipartite.hpp
  requiredBy: []
  timestamp: '2023-11-04 23:05:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/is_bipartite.hpp
layout: document
redirect_from:
- /library/graph/is_bipartite.hpp
- /library/graph/is_bipartite.hpp.html
title: graph/is_bipartite.hpp
---
