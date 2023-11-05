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
  bundledCode: "#line 2 \"graph/scc.hpp\"\n\n#line 2 \"graph/graph_base.hpp\"\n\n\
    template <typename T>\nstruct Edge\n{\n    int from, to;\n    T cost;\n    int\
    \ id;\n    Edge(int from, int to, T cost, int id) : from(from), to(to), cost(cost),\
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
    \ i, z); }\n        }\n    }\n};\n#line 4 \"graph/scc.hpp\"\n\ntemplate <class\
    \ G>\nvector<vector<int>> scc(G& g)\n{\n    int n = g.n, m = g.m;\n    const int\
    \ inf = 1001001001;\n\n    auto get_ids = [&]() -> pair<int, vector<int>>\n  \
    \  {\n\t\tint now_ord = 0, now_id = 0;\n\t\tvector<int> low(n), ord(n, -1), id(n);\n\
    \t\tstack<int> visited;\n\t\tauto dfs = [&](auto dfs, int v) -> void\n\t\t{\n\t\
    \t\tlow[v] = ord[v] = now_ord++;\n\t\t\tvisited.push(v);\n\t\t\tfor (auto [_,\
    \ p, __, ___] : g[v])\n\t\t\t{\n\t\t\t\tif (ord[p] == -1)\n\t\t\t\t{\n\t\t\t\t\
    \tdfs(dfs, p);\n\t\t\t\t\tlow[v] = min(low[v], low[p]);\n\t\t\t\t}\n\t\t\t\telse\
    \ low[v] = min(low[v], ord[p]);\n\t\t\t}\n\n\t\t\tif (low[v] == ord[v])\n\t\t\t\
    {\n\t\t\t\twhile (true)\n\t\t\t\t{\n\t\t\t\t\tint u = visited.top(); visited.pop();\n\
    \t\t\t\t\tord[u] = inf;\n\t\t\t\t\tid[u] = now_id;\n\t\t\t\t\tif (u == v) break;\n\
    \t\t\t\t}\n\t\t\t\tnow_id++;\n\t\t\t}\n\t\t};\n\n\t\tfor (int i = 0; i < n; i++)\n\
    \t\t{\n\t\t\tif (ord[i] == -1) dfs(dfs, i);\n\t\t}\n\t\tfor (auto& p : id) p =\
    \ now_id - 1 - p;\n\t\treturn { now_id, id };\n    };\n\n    auto ids = get_ids();\n\
    \    vector<vector<int>> res(ids.first);\n    for(int i = 0; i < n; i++) res[ids.second[i]].push_back(i);\n\
    \    return res;\n}\n"
  code: "#pragma once\n\n#include \"/home/ailets/AiletS_Library/graph/graph_base.hpp\"\
    \n\ntemplate <class G>\nvector<vector<int>> scc(G& g)\n{\n    int n = g.n, m =\
    \ g.m;\n    const int inf = 1001001001;\n\n    auto get_ids = [&]() -> pair<int,\
    \ vector<int>>\n    {\n\t\tint now_ord = 0, now_id = 0;\n\t\tvector<int> low(n),\
    \ ord(n, -1), id(n);\n\t\tstack<int> visited;\n\t\tauto dfs = [&](auto dfs, int\
    \ v) -> void\n\t\t{\n\t\t\tlow[v] = ord[v] = now_ord++;\n\t\t\tvisited.push(v);\n\
    \t\t\tfor (auto [_, p, __, ___] : g[v])\n\t\t\t{\n\t\t\t\tif (ord[p] == -1)\n\t\
    \t\t\t{\n\t\t\t\t\tdfs(dfs, p);\n\t\t\t\t\tlow[v] = min(low[v], low[p]);\n\t\t\
    \t\t}\n\t\t\t\telse low[v] = min(low[v], ord[p]);\n\t\t\t}\n\n\t\t\tif (low[v]\
    \ == ord[v])\n\t\t\t{\n\t\t\t\twhile (true)\n\t\t\t\t{\n\t\t\t\t\tint u = visited.top();\
    \ visited.pop();\n\t\t\t\t\tord[u] = inf;\n\t\t\t\t\tid[u] = now_id;\n\t\t\t\t\
    \tif (u == v) break;\n\t\t\t\t}\n\t\t\t\tnow_id++;\n\t\t\t}\n\t\t};\n\n\t\tfor\
    \ (int i = 0; i < n; i++)\n\t\t{\n\t\t\tif (ord[i] == -1) dfs(dfs, i);\n\t\t}\n\
    \t\tfor (auto& p : id) p = now_id - 1 - p;\n\t\treturn { now_id, id };\n    };\n\
    \n    auto ids = get_ids();\n    vector<vector<int>> res(ids.first);\n    for(int\
    \ i = 0; i < n; i++) res[ids.second[i]].push_back(i);\n    return res;\n}"
  dependsOn:
  - graph/graph_base.hpp
  isVerificationFile: false
  path: graph/scc.hpp
  requiredBy: []
  timestamp: '2023-09-16 21:22:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/scc.hpp
layout: document
redirect_from:
- /library/graph/scc.hpp
- /library/graph/scc.hpp.html
title: graph/scc.hpp
---
