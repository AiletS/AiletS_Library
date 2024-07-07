---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_base.hpp
    title: graph/graph_base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/tree/tree_diameter.hpp
    title: graph/tree/tree_diameter.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/dist_bfs.hpp\"\n\n#line 2 \"graph/graph_base.hpp\"\
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
    \  Graph() {}\n    Graph(int N)\n    {\n        n = N; m = 0;\n        G = vector<vector<Edge<T>>>(N);\n\
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
    \ i, z); }\n        }\n    }\n};\n#line 4 \"graph/dist_bfs.hpp\"\n\n/*\n\u30B0\
    \u30E9\u30D5\u304B\u3089BFS\u3092\u884C\u3046\ndist_bfs<T = long long>(G& g, int\
    \ start, T inf_off = 0)\n[dist, par] \u3092\u8FD4\u3059\ninf_off \u306F 0 \u306E\
    \u3068\u304D infty<T>\u30010 \u3067\u306F\u306A\u3044\u3068\u304D\u6700\u5927\u5024\
    \u3092\u4EFB\u610F\u306B\u8A2D\u5B9A\n*/\ntemplate <class T = long long, class\
    \ G>\npair<vector<T>, vector<int>> dist_bfs(G& g, int start, T inf_off = 0)\n\
    {\n    if(inf_off == 0) inf_off = infty<T>;\n    vector<T> dist(g.n, inf_off);\
    \ dist[start] = 0;\n    vector<int> par(g.n, -1);\n    queue<T> q; q.push(start);\n\
    \    while(q.size())\n    {\n        int a = q.front(); q.pop();\n        for(auto\
    \ p : g[a])\n        {\n            if(dist[a] + p.cost < dist[p.to])\n      \
    \      {\n                dist[p.to] = dist[a] + p.cost;\n                par[p.to]\
    \ = p.from;\n                q.push(p.to);\n            }\n        }\n    }\n\
    \    return { dist, par };\n}\n\n/*\n\u30B0\u30E9\u30D5\u304B\u3089BFS\u3092\u884C\
    \u3046(\u591A\u70B9\u30B9\u30BF\u30FC\u30C8)\ndist_bfs<T = long long>(G& g, int\
    \ start, T inf_off = 0)\n[dist, par, root] \u3092\u8FD4\u3059\nroot \u306F\u305D\
    \u306E\u9802\u70B9\u304C\u3069\u3053\u306E\u9802\u70B9\u304B\u3089\u304D\u305F\
    \u304B\ninf_off \u306F 0 \u306E\u3068\u304D infty<T>\u30010 \u3067\u306F\u306A\
    \u3044\u3068\u304D\u6700\u5927\u5024\u3092\u4EFB\u610F\u306B\u8A2D\u5B9A\n*/\n\
    template <class T = long long, class G>\ntuple<vector<T>, vector<int>, vector<int>>\
    \ dist_bfs(G& g, vector<int>& starts, T inf_off = 0)\n{\n    if(inf_off == 0)\
    \ inf_off = infty<T>;\n    vector<T> dist(g.n, inf_off);\n    vector<int> par(g.n,\
    \ -1), root(g.n, -1);\n    queue<T> q;\n    for(auto p : starts) dist[p] = 0,\
    \ q.push(p), root[p] = p;\n\n    while(q.size())\n    {\n        int a = q.front();\
    \ q.pop();\n        for(auto p : g[a])\n        {\n            if(dist[a] + p.cost\
    \ < dist[p.to])\n            {\n                dist[p.to] = dist[a] + p.cost;\n\
    \                par[p.to] = p.from;\n                root[p.to] = root[p.from];\n\
    \                q.push(p.to);\n            }\n        }\n    }\n    return {\
    \ dist, par, root };\n}\n"
  code: "#pragma once\n\n#include \"graph/graph_base.hpp\"\n\n/*\n\u30B0\u30E9\u30D5\
    \u304B\u3089BFS\u3092\u884C\u3046\ndist_bfs<T = long long>(G& g, int start, T\
    \ inf_off = 0)\n[dist, par] \u3092\u8FD4\u3059\ninf_off \u306F 0 \u306E\u3068\u304D\
    \ infty<T>\u30010 \u3067\u306F\u306A\u3044\u3068\u304D\u6700\u5927\u5024\u3092\
    \u4EFB\u610F\u306B\u8A2D\u5B9A\n*/\ntemplate <class T = long long, class G>\n\
    pair<vector<T>, vector<int>> dist_bfs(G& g, int start, T inf_off = 0)\n{\n   \
    \ if(inf_off == 0) inf_off = infty<T>;\n    vector<T> dist(g.n, inf_off); dist[start]\
    \ = 0;\n    vector<int> par(g.n, -1);\n    queue<T> q; q.push(start);\n    while(q.size())\n\
    \    {\n        int a = q.front(); q.pop();\n        for(auto p : g[a])\n    \
    \    {\n            if(dist[a] + p.cost < dist[p.to])\n            {\n       \
    \         dist[p.to] = dist[a] + p.cost;\n                par[p.to] = p.from;\n\
    \                q.push(p.to);\n            }\n        }\n    }\n    return {\
    \ dist, par };\n}\n\n/*\n\u30B0\u30E9\u30D5\u304B\u3089BFS\u3092\u884C\u3046(\u591A\
    \u70B9\u30B9\u30BF\u30FC\u30C8)\ndist_bfs<T = long long>(G& g, int start, T inf_off\
    \ = 0)\n[dist, par, root] \u3092\u8FD4\u3059\nroot \u306F\u305D\u306E\u9802\u70B9\
    \u304C\u3069\u3053\u306E\u9802\u70B9\u304B\u3089\u304D\u305F\u304B\ninf_off \u306F\
    \ 0 \u306E\u3068\u304D infty<T>\u30010 \u3067\u306F\u306A\u3044\u3068\u304D\u6700\
    \u5927\u5024\u3092\u4EFB\u610F\u306B\u8A2D\u5B9A\n*/\ntemplate <class T = long\
    \ long, class G>\ntuple<vector<T>, vector<int>, vector<int>> dist_bfs(G& g, vector<int>&\
    \ starts, T inf_off = 0)\n{\n    if(inf_off == 0) inf_off = infty<T>;\n    vector<T>\
    \ dist(g.n, inf_off);\n    vector<int> par(g.n, -1), root(g.n, -1);\n    queue<T>\
    \ q;\n    for(auto p : starts) dist[p] = 0, q.push(p), root[p] = p;\n\n    while(q.size())\n\
    \    {\n        int a = q.front(); q.pop();\n        for(auto p : g[a])\n    \
    \    {\n            if(dist[a] + p.cost < dist[p.to])\n            {\n       \
    \         dist[p.to] = dist[a] + p.cost;\n                par[p.to] = p.from;\n\
    \                root[p.to] = root[p.from];\n                q.push(p.to);\n \
    \           }\n        }\n    }\n    return { dist, par, root };\n}"
  dependsOn:
  - graph/graph_base.hpp
  isVerificationFile: false
  path: graph/dist_bfs.hpp
  requiredBy:
  - graph/tree/tree_diameter.hpp
  timestamp: '2024-07-07 18:01:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dist_bfs.hpp
layout: document
redirect_from:
- /library/graph/dist_bfs.hpp
- /library/graph/dist_bfs.hpp.html
title: graph/dist_bfs.hpp
---
