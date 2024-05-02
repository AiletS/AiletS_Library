---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"flow/maxflow.hpp\"\n\nstruct maxflow // max flow, dinic,\
    \ O(EV^2)\n{\n    struct edge\n    {\n        int to;\n        long long cap;\n\
    \        int rev;\n    };\n    int n;\n\n    vector<vector<edge>> g;\n    vector<int>\
    \ level;\n    vector<int> iter;\n\n    maxflow() : n(0) {}\n    maxflow(int n)\
    \ : n(n), g(n), level(n), iter(n) {}\n\n    void add_edge(int from, int to, long\
    \ long cap)\n    {\n        g[from].push_back(edge{ to, cap, (int)g[to].size()\
    \ });\n        g[to].push_back(edge{ from, 0, (int)g[from].size() - 1 });\n  \
    \  }\n\n    void bfs(int s)\n    {\n        level = vector<int>(n, -1);\n    \
    \    queue<int> q;\n        level[s] = 0;\n        q.push(s);\n        while (q.size())\n\
    \        {\n            int v = q.front(); q.pop();\n            for (int i =\
    \ 0; i < g[v].size(); i++)\n            {\n                edge& e = g[v][i];\n\
    \                if (e.cap > 0 && level[e.to] < 0)\n                {\n      \
    \              level[e.to] = level[v] + 1;\n                    q.push(e.to);\n\
    \                }\n            }\n        }\n    }\n\n    int dfs(int v, int\
    \ t, long long f)\n    {\n        if (v == t) return f;\n        for (int& i =\
    \ iter[v]; i < g[v].size(); i++)\n        {\n            edge& e = g[v][i];\n\
    \            if (e.cap > 0 && level[v] < level[e.to])\n            {\n       \
    \         int d = dfs(e.to, t, min(f, e.cap));\n                if (d > 0)\n \
    \               {\n                    e.cap -= d;\n                    g[e.to][e.rev].cap\
    \ += d;\n                    return d;\n                }\n            }\n   \
    \     }\n        return 0;\n    }\n\n    int flow(int s, int t, int limit = 1001001001)\n\
    \    {\n        long long res = 0;\n        while(res < limit)\n        {\n  \
    \          bfs(s);\n            if (level[t] < 0) break;;\n            iter =\
    \ vector<int>(n, 0);\n            int f;\n            while(res < limit){\n  \
    \              f = dfs(s, t, limit - res);\n                if(!f) break;\n  \
    \              res += f;\n            }\n        }\n        return res;\n    }\n\
    };\n"
  code: "#pragma once\n\nstruct maxflow // max flow, dinic, O(EV^2)\n{\n    struct\
    \ edge\n    {\n        int to;\n        long long cap;\n        int rev;\n   \
    \ };\n    int n;\n\n    vector<vector<edge>> g;\n    vector<int> level;\n    vector<int>\
    \ iter;\n\n    maxflow() : n(0) {}\n    maxflow(int n) : n(n), g(n), level(n),\
    \ iter(n) {}\n\n    void add_edge(int from, int to, long long cap)\n    {\n  \
    \      g[from].push_back(edge{ to, cap, (int)g[to].size() });\n        g[to].push_back(edge{\
    \ from, 0, (int)g[from].size() - 1 });\n    }\n\n    void bfs(int s)\n    {\n\
    \        level = vector<int>(n, -1);\n        queue<int> q;\n        level[s]\
    \ = 0;\n        q.push(s);\n        while (q.size())\n        {\n            int\
    \ v = q.front(); q.pop();\n            for (int i = 0; i < g[v].size(); i++)\n\
    \            {\n                edge& e = g[v][i];\n                if (e.cap\
    \ > 0 && level[e.to] < 0)\n                {\n                    level[e.to]\
    \ = level[v] + 1;\n                    q.push(e.to);\n                }\n    \
    \        }\n        }\n    }\n\n    int dfs(int v, int t, long long f)\n    {\n\
    \        if (v == t) return f;\n        for (int& i = iter[v]; i < g[v].size();\
    \ i++)\n        {\n            edge& e = g[v][i];\n            if (e.cap > 0 &&\
    \ level[v] < level[e.to])\n            {\n                int d = dfs(e.to, t,\
    \ min(f, e.cap));\n                if (d > 0)\n                {\n           \
    \         e.cap -= d;\n                    g[e.to][e.rev].cap += d;\n        \
    \            return d;\n                }\n            }\n        }\n        return\
    \ 0;\n    }\n\n    int flow(int s, int t, int limit = 1001001001)\n    {\n   \
    \     long long res = 0;\n        while(res < limit)\n        {\n            bfs(s);\n\
    \            if (level[t] < 0) break;;\n            iter = vector<int>(n, 0);\n\
    \            int f;\n            while(res < limit){\n                f = dfs(s,\
    \ t, limit - res);\n                if(!f) break;\n                res += f;\n\
    \            }\n        }\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: flow/maxflow.hpp
  requiredBy: []
  timestamp: '2024-05-03 01:16:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: flow/maxflow.hpp
layout: document
redirect_from:
- /library/flow/maxflow.hpp
- /library/flow/maxflow.hpp.html
title: flow/maxflow.hpp
---
