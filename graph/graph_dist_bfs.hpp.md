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
  bundledCode: "#line 2 \"graph/graph_dist_bfs.hpp\"\n\n#line 2 \"graph/graph_base.hpp\"\
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
    \ i, z); }\n        }\n    }\n};\n#line 4 \"graph/graph_dist_bfs.hpp\"\n\ntemplate\
    \ <class T, class G>\nvector<T> dist_bfs(G& g, int start, T inf_off = 0)\n{\n\
    \    if(inf_off == 0) inf_off = numeric_limits<T>::max();\n    vector<T> dist(g.n,\
    \ inf_off); dist[start] = 0;\n    queue<T> q; q.push(start);\n    while(q.size())\n\
    \    {\n        int a = q.front(); q.pop();\n        for(auto p : g[a])\n    \
    \    {\n            if(dist[a] + p.cost < dist[p.to])\n            {\n       \
    \         dist[p.to] = dist[a] + p.cost;\n                q.push(p.to);\n    \
    \        }\n        }\n    }\n    return dist;\n}\n\ntemplate <class T, class\
    \ G>\nvector<T> dist_bfs(G& g, vector<int>& starts, T inf_off = 0)\n{\n    if(inf_off\
    \ == 0) inf_off = numeric_limits<T>::max();\n    vector<T> dist(g.n, inf_off);\
    \ \n    queue<T> q;\n    for(auto p : starts) dist[p] = 0, q.push(p);\n    \n\
    \    while(q.size())\n    {\n        int a = q.front(); q.pop();\n        for(auto\
    \ p : g[a])\n        {\n            if(dist[a] + p.cost < dist[p.to])\n      \
    \      {\n                dist[p.to] = dist[a] + p.cost;\n                q.push(p.to);\n\
    \            }\n        }\n    }\n    return dist;\n}\n"
  code: "#pragma once\n\n#include \"/home/ailets/AiletS_Library/graph/graph_base.hpp\"\
    \n\ntemplate <class T, class G>\nvector<T> dist_bfs(G& g, int start, T inf_off\
    \ = 0)\n{\n    if(inf_off == 0) inf_off = numeric_limits<T>::max();\n    vector<T>\
    \ dist(g.n, inf_off); dist[start] = 0;\n    queue<T> q; q.push(start);\n    while(q.size())\n\
    \    {\n        int a = q.front(); q.pop();\n        for(auto p : g[a])\n    \
    \    {\n            if(dist[a] + p.cost < dist[p.to])\n            {\n       \
    \         dist[p.to] = dist[a] + p.cost;\n                q.push(p.to);\n    \
    \        }\n        }\n    }\n    return dist;\n}\n\ntemplate <class T, class\
    \ G>\nvector<T> dist_bfs(G& g, vector<int>& starts, T inf_off = 0)\n{\n    if(inf_off\
    \ == 0) inf_off = numeric_limits<T>::max();\n    vector<T> dist(g.n, inf_off);\
    \ \n    queue<T> q;\n    for(auto p : starts) dist[p] = 0, q.push(p);\n    \n\
    \    while(q.size())\n    {\n        int a = q.front(); q.pop();\n        for(auto\
    \ p : g[a])\n        {\n            if(dist[a] + p.cost < dist[p.to])\n      \
    \      {\n                dist[p.to] = dist[a] + p.cost;\n                q.push(p.to);\n\
    \            }\n        }\n    }\n    return dist;\n}"
  dependsOn:
  - graph/graph_base.hpp
  isVerificationFile: false
  path: graph/graph_dist_bfs.hpp
  requiredBy: []
  timestamp: '2023-09-16 21:22:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph_dist_bfs.hpp
layout: document
redirect_from:
- /library/graph/graph_dist_bfs.hpp
- /library/graph/graph_dist_bfs.hpp.html
title: graph/graph_dist_bfs.hpp
---
