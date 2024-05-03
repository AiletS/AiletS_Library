---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph_base.hpp
    title: graph/graph_base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/dist_dijkstra.hpp\"\n\n#line 2 \"graph/graph_base.hpp\"\
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
    \ G;\n    vector<Edge<T>> edges;\n    vector<int> in_deg, out_deg;\n\n    Graph()\
    \ {}\n    Graph(int N) \n    {\n        n = N; m = 0;\n        G = vector<vector<Edge<T>>>(N);\n\
    \        in_deg = vector<int>(N, 0);\n        out_deg = vector<int>(N, 0);\n \
    \   }\n\n    vector<Edge<T>> operator[](int x) const { return G[x]; }\n\n    void\
    \ add(int from, int to, T cost = 1, int id = -1)\\\n    {\n        if(id == -1)\
    \ id = m++;\n        G[from].emplace_back(from, to, cost, id);\n        edges.emplace_back(from,\
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
    \   }\n    }\n};\n#line 4 \"graph/dist_dijkstra.hpp\"\n\n\n/*\n\u30C0\u30A4\u30AF\
    \u30B9\u30C8\u30E9\u6CD5 (dist, pre) \u306E pair \u3092\u8FD4\u3059\ndijkstra<int>(g,\
    \ 0) \u306E\u3088\u3046\u306B\u547C\u3076\n*/\ntemplate <class T = long long,\
    \ class GT>\npair<vector<T>, vector<int>> dijkstra(GT& g, int start, T inf_off\
    \ = 0)\n{\n    if(inf_off == 0) inf_off = infty<T>;\n    const int n = g.n;\n\
    \    using PT = pair<T, int>;\n\n    vector<T> dist(n, inf_off);\n    vector<int>\
    \ pre(n, -1);\n    \n    dist[start] = 0;\n    priority_queue<PT, vector<PT>,\
    \ greater<PT>> q;\n    q.emplace(dist[start], start);\n\n    while(q.size())\n\
    \    {\n        auto [d, a] = q.top(); q.pop();\n        if(dist[a] < d) continue;\n\
    \        for(auto p : g[a])\n        {\n            if(d + p.cost < dist[p.to])\n\
    \            {\n                dist[p.to] = d + p.cost;\n                pre[p.to]\
    \ = a;\n                q.emplace(dist[p.to], p.to);\n            }\n        }\n\
    \    }\n    return { dist, pre };\n}\n\n// route(\u76EE\u7684\u5730, pre) \u3067\
    \u7D4C\u8DEF\u3092\u8FD4\u3059\nvector<int> route(int x, vector<int>& pre) //\
    \ route restoration\n{\n    vector<int> path;\n    for(int i = x; i != -1; i =\
    \ pre[i]) path.push_back(i);\n    reverse(path.begin(), path.end());\n    return\
    \ path;\n}\n"
  code: "#pragma once\n\n#include \"graph/graph_base.hpp\"\n\n\n/*\n\u30C0\u30A4\u30AF\
    \u30B9\u30C8\u30E9\u6CD5 (dist, pre) \u306E pair \u3092\u8FD4\u3059\ndijkstra<int>(g,\
    \ 0) \u306E\u3088\u3046\u306B\u547C\u3076\n*/\ntemplate <class T = long long,\
    \ class GT>\npair<vector<T>, vector<int>> dijkstra(GT& g, int start, T inf_off\
    \ = 0)\n{\n    if(inf_off == 0) inf_off = infty<T>;\n    const int n = g.n;\n\
    \    using PT = pair<T, int>;\n\n    vector<T> dist(n, inf_off);\n    vector<int>\
    \ pre(n, -1);\n    \n    dist[start] = 0;\n    priority_queue<PT, vector<PT>,\
    \ greater<PT>> q;\n    q.emplace(dist[start], start);\n\n    while(q.size())\n\
    \    {\n        auto [d, a] = q.top(); q.pop();\n        if(dist[a] < d) continue;\n\
    \        for(auto p : g[a])\n        {\n            if(d + p.cost < dist[p.to])\n\
    \            {\n                dist[p.to] = d + p.cost;\n                pre[p.to]\
    \ = a;\n                q.emplace(dist[p.to], p.to);\n            }\n        }\n\
    \    }\n    return { dist, pre };\n}\n\n// route(\u76EE\u7684\u5730, pre) \u3067\
    \u7D4C\u8DEF\u3092\u8FD4\u3059\nvector<int> route(int x, vector<int>& pre) //\
    \ route restoration\n{\n    vector<int> path;\n    for(int i = x; i != -1; i =\
    \ pre[i]) path.push_back(i);\n    reverse(path.begin(), path.end());\n    return\
    \ path;\n}"
  dependsOn:
  - graph/graph_base.hpp
  isVerificationFile: false
  path: graph/dist_dijkstra.hpp
  requiredBy: []
  timestamp: '2024-05-03 01:16:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dist_dijkstra.hpp
layout: document
redirect_from:
- /library/graph/dist_dijkstra.hpp
- /library/graph/dist_dijkstra.hpp.html
title: graph/dist_dijkstra.hpp
---
