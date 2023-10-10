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
  bundledCode: "#line 2 \"graph/graph_dist_dijkstra.hpp\"\n\n#line 2 \"graph/graph_base.hpp\"\
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
    \ i, z); }\n        }\n    }\n};\n#line 4 \"graph/graph_dist_dijkstra.hpp\"\n\n\
    template <class T, class G>\npair<vector<T>, vector<int>> dijkstra(G& g, int start,\
    \ T inf_off = 0)\n{\n    if(inf_off == 0) inf_off = numeric_limits<T>::max();\n\
    \    vector<T> dist(g.n, inf_off);\n    vector<int> pre(g.n, -1);\n    \n    dist[start]\
    \ = 0;\n    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T,\
    \ int>>> q;\n    q.emplace(dist[start], start);\n\n    while(q.size())\n    {\n\
    \        auto [d, a] = q.top(); q.pop();\n        if(dist[a] < d) continue;\n\
    \        for(auto p : g[a])\n        {\n            if(d + p.cost < dist[p.to])\n\
    \            {\n                dist[p.to] = d + p.cost;\n                pre[p.to]\
    \ = a;\n                q.emplace(dist[p.to], p.to);\n            }\n        }\n\
    \    }\n    return { dist, pre };\n}\n\nvector<int> route(int x, vector<int>&\
    \ pre) // route restoration\n{\n    vector<int> path;\n    for(int i = x; i !=\
    \ -1; i = pre[i]) path.push_back(i);\n    reverse(path.begin(), path.end());\n\
    \    return path;\n}\n"
  code: "#pragma once\n\n#include \"/home/ailets/AiletS_Library/graph/graph_base.hpp\"\
    \n\ntemplate <class T, class G>\npair<vector<T>, vector<int>> dijkstra(G& g, int\
    \ start, T inf_off = 0)\n{\n    if(inf_off == 0) inf_off = numeric_limits<T>::max();\n\
    \    vector<T> dist(g.n, inf_off);\n    vector<int> pre(g.n, -1);\n    \n    dist[start]\
    \ = 0;\n    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T,\
    \ int>>> q;\n    q.emplace(dist[start], start);\n\n    while(q.size())\n    {\n\
    \        auto [d, a] = q.top(); q.pop();\n        if(dist[a] < d) continue;\n\
    \        for(auto p : g[a])\n        {\n            if(d + p.cost < dist[p.to])\n\
    \            {\n                dist[p.to] = d + p.cost;\n                pre[p.to]\
    \ = a;\n                q.emplace(dist[p.to], p.to);\n            }\n        }\n\
    \    }\n    return { dist, pre };\n}\n\nvector<int> route(int x, vector<int>&\
    \ pre) // route restoration\n{\n    vector<int> path;\n    for(int i = x; i !=\
    \ -1; i = pre[i]) path.push_back(i);\n    reverse(path.begin(), path.end());\n\
    \    return path;\n}"
  dependsOn:
  - graph/graph_base.hpp
  isVerificationFile: false
  path: graph/graph_dist_dijkstra.hpp
  requiredBy: []
  timestamp: '2023-09-16 21:22:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph_dist_dijkstra.hpp
layout: document
redirect_from:
- /library/graph/graph_dist_dijkstra.hpp
- /library/graph/graph_dist_dijkstra.hpp.html
title: graph/graph_dist_dijkstra.hpp
---
