---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/tree/tree_base.hpp
    title: graph/tree/tree_base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/tree/CompressTree.hpp
    title: graph/tree/CompressTree.hpp
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
  bundledCode: "#line 2 \"graph/tree/EulerTour.hpp\"\n\n#line 2 \"graph/tree/tree_base.hpp\"\
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
    \ i, z); }\n        }\n    }\n};\n#line 4 \"graph/tree/EulerTour.hpp\"\n\n/*\n\
    \u6728\u4E0A\u3067Euler Tour\u3092\u884C\u3046\ntuple<vector<int>, vector<int>,\
    \ vector<pair<int, int>>>\n= {in, out, {depth, \u9802\u70B9}}\n*/\ntemplate <class\
    \ TREE>\ntuple<vector<int>, vector<int>, vector<pair<int, int>>>\nEulerTour(const\
    \ TREE& g)\n{\n    const int n = g.n, m = g.m;\n    vector<int> in(n), out(n);\n\
    \    vector<pair<int, int>> v;\n\n    function<void(int, int, int)> dfs = [&](int\
    \ U, int V, int depth) -> void\n    {\n        assert(U >= 0 && U < n);\n    \
    \    in[U] = v.size();\n        v.emplace_back(depth, U);\n        for(auto [from,\
    \ to, _, __] : g[U])\n        {\n            if(to == V) continue;\n         \
    \   dfs(to, from, depth + 1);\n        }\n        out[U] = v.size();\n       \
    \ v.emplace_back(depth - 1, V);\n    };\n\n    dfs(g.root, -1, 0);\n    return\
    \ { in, out, v };\n}\n"
  code: "#pragma once\n\n#include \"graph/tree/tree_base.hpp\"\n\n/*\n\u6728\u4E0A\
    \u3067Euler Tour\u3092\u884C\u3046\ntuple<vector<int>, vector<int>, vector<pair<int,\
    \ int>>>\n= {in, out, {depth, \u9802\u70B9}}\n*/\ntemplate <class TREE>\ntuple<vector<int>,\
    \ vector<int>, vector<pair<int, int>>>\nEulerTour(const TREE& g)\n{\n    const\
    \ int n = g.n, m = g.m;\n    vector<int> in(n), out(n);\n    vector<pair<int,\
    \ int>> v;\n\n    function<void(int, int, int)> dfs = [&](int U, int V, int depth)\
    \ -> void\n    {\n        assert(U >= 0 && U < n);\n        in[U] = v.size();\n\
    \        v.emplace_back(depth, U);\n        for(auto [from, to, _, __] : g[U])\n\
    \        {\n            if(to == V) continue;\n            dfs(to, from, depth\
    \ + 1);\n        }\n        out[U] = v.size();\n        v.emplace_back(depth -\
    \ 1, V);\n    };\n\n    dfs(g.root, -1, 0);\n    return { in, out, v };\n}"
  dependsOn:
  - graph/tree/tree_base.hpp
  isVerificationFile: false
  path: graph/tree/EulerTour.hpp
  requiredBy:
  - graph/tree/lca.hpp
  - graph/tree/CompressTree.hpp
  timestamp: '2024-05-03 01:16:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/Lowest_Common_Ancestor.test.cpp
documentation_of: graph/tree/EulerTour.hpp
layout: document
redirect_from:
- /library/graph/tree/EulerTour.hpp
- /library/graph/tree/EulerTour.hpp.html
title: graph/tree/EulerTour.hpp
---
