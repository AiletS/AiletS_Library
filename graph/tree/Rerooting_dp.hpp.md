---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph_base.hpp
    title: graph/graph_base.hpp
  - icon: ':x:'
    path: graph/tree/tree_base.hpp
    title: graph/tree/tree_base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/tree/Rerooting_dp.hpp\"\n\n#line 2 \"graph/tree/tree_base.hpp\"\
    \n\n#line 2 \"graph/graph_base.hpp\"\n\ntemplate <typename T>\nstruct Edge\n{\n\
    \    int from, to;\n    T cost;\n    int id;\n    Edge(int from, int to, T cost,\
    \ int id) : from(from), to(to), cost(cost), id(id) {}\n};\n\n/*\nGraph \u30E9\u30A4\
    \u30D6\u30E9\u30EA\nGraph<T = long long, directed = false> (int n) : n \u500B\u306E\
    \u9802\u70B9\u3092\u6301\u3064\u30B0\u30E9\u30D5\nT \u306F\u91CD\u307F\u306E\u578B\
    \u3001directed\u306F\u6709\u5411\u304C\u7121\u5411\u304B false \u306A\u3089\u7121\
    \u5411\noperator[] \u304C\u5B9A\u7FA9\u3055\u308C\u3066\u3044\u308B G[x] : x \u306E\
    \u96A3\u63A5\u30EA\u30B9\u30C8\nadd(int from, int to, T cost = 1, int id = -1)\
    \ \u8FBA\u3092\u8FFD\u52A0\u3059\u308B\nmkg(int m, bool weighted = false, int\
    \ off = 1) \u5165\u529B\u304B\u3089\u30B0\u30E9\u30D5\u3092\u4F5C\u308B m \u306F\
    \u5909\u6570 off-index\nmkg_ancestor(bool weighted = false, int off = 1) n-1\u8FBA\
    \u306E\u30B0\u30E9\u30D5\u3092\u5165\u529B\u304B\u3089\u4F5C\u308B\n*/\ntemplate\
    \ <typename T = long long, bool directed = false>\nstruct Graph\n{\n    using\
    \ cost_type = T;\n    int n, m;\n    vector<vector<Edge<T>>> G;\n    vector<Edge<T>>\
    \ edges;\n    vector<int> deg, in_deg, out_deg;\n\n    Graph() {}\n    Graph(int\
    \ N) \n    {\n        n = N; m = 0;\n        G = vector<vector<Edge<T>>>(N);\n\
    \        deg = vector<int>(N, 0);\n        in_deg = vector<int>(N, 0);\n     \
    \   out_deg = vector<int>(N, 0);\n    }\n\n    const vector<Edge<T>>& operator[](int\
    \ x) const { return G[x]; }\n\n    // \u8FBA\u3092\u8FFD\u52A0\n    void add(int\
    \ from, int to, T cost = 1, int id = -1)\\\n    {\n        if(id == -1) id = m++;\n\
    \        G[from].emplace_back(from, to, cost, id);\n        edges.emplace_back(from,\
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
    \   }\n    }\n};\n#line 4 \"graph/tree/tree_base.hpp\"\n\ntemplate <class GT>\n\
    struct Tree\n{\n    using Graph_type = GT;\n    using cost_type = typename GT::cost_type;\n\
    \    GT& G;\n    int n, root;\n    vector<int> depth, parent;\n\n    Tree() {}\n\
    \    Tree(GT& G, int root = 0) : G(G), root(root) { build(); }\n    const vector<Edge<cost_type>>&\
    \ operator[](int x) const { return G[x]; }\n\n    void build()\n    {\n      \
    \  n = G.n;\n        depth.assign(n, -1), parent.assign(n, -1);\n        dfs(root,\
    \ -1);\n    }\n\n    void dfs(int U, int V)\n    {\n        parent[U] = V;\n \
    \       depth[U] = (V == -1 ? 0 : depth[V] + 1);\n        for(auto [from, to,\
    \ _, __] : G[U])\n        {\n            if(to == V) continue;\n            dfs(to,\
    \ from);\n        }\n    }\n};\n#line 4 \"graph/tree/Rerooting_dp.hpp\"\n\n/*\n\
    Rerooting_dp<decltype(g), S, e, fee, fev> dp(g);\nstruct S : \u578B\nS e() : S\u306E\
    \u5358\u4F4D\u9650\nS fee(S, S) : \u90E8\u5206\u6728\u306E\u7D50\u5408\nS fev(S,\
    \ int) : \u8FBA e \u304B\u3089\u9802\u70B9 v \u306B\n*/\ntemplate <class TREE,\
    \ class S, S (*e)(), S (*fee)(S, S), S (*fev)(S, int)>\nstruct Rerooting_dp\n\
    {\n    TREE& g;\n    int n;\n    vector<S> subtree;\n    vector<S> rev_subtree;\n\
    \    vector<S> ans;\n\n    Rerooting_dp() {}\n    Rerooting_dp(TREE& _g) : g(_g),\
    \ n(_g.n) { build(); }\n\n    S& operator[](int i) { return ans[i]; }\n\n    void\
    \ build()\n    {\n        subtree.assign(n, e());\n        rev_subtree.assign(n,\
    \ e());\n        int root = g.root;\n        dfs(root);\n        dfs2(root);\n\
    \    }\n\n    S dfs(int U)\n    {\n        S res = e();\n        int m = g[U].size();\n\
    \        for(int i = 0; i < m; i++)\n        {\n            auto [from, to, _,\
    \ __] = g[U][i];\n            if(to == g.parent[U]) continue;\n            res\
    \ = fee(res, dfs(to));\n        }\n        return subtree[U] = fev(res, U);  \
    \      \n    }\n\n    void dfs2(int U)\n    {\n        int m = g[U].size();\n\
    \        vector<S> l(m + 1, e()), r(m + 1, e());\n        for(int i = 0; i < m;\
    \ i++)\n        {\n            auto [from, to, _, __] = g[U][i];\n           \
    \ if(to == g.parent[from]) l[i + 1] = fee(l[i], rev_subtree[from]);\n        \
    \    else l[i + 1] = fee(l[i], subtree[to]);\n        }\n        for(int i = m\
    \ - 1; i >= 0; i--)\n        {\n            auto [from, to, _, __] = g[U][i];\n\
    \            if(to == g.parent[U]) r[i] = fee(r[i + 1], rev_subtree[from]);\n\
    \            else r[i] = fee(r[i + 1], subtree[to]);\n        }\n        for(int\
    \ i = 0; i < m; i++)\n        {\n            auto [from, to, _, __] = g[U][i];\n\
    \            if(to == g.parent[U]) continue;\n            rev_subtree[to] = fev(fee(l[i],\
    \ r[i + 1]), U);\n            dfs2(to);\n        }\n    }\n\n    vector<S> get()\n\
    \    {\n        ans.assign(n, e());\n        for(int i = 0; i < n; i++)\n    \
    \    {\n            int m = g[i].size();\n            for(int j = 0; j < m; j++)\n\
    \            {\n                if(g[i][j].to == g.parent[i]) ans[i] = fee(ans[i],\
    \ rev_subtree[i]);\n                else ans[i] = fee(ans[i], subtree[g[i][j].to]);\n\
    \            }\n            ans[i] = fev(ans[i], i);\n        }\n        return\
    \ ans;\n    }\n};\n"
  code: "#pragma once\n\n#include \"graph/tree/tree_base.hpp\"\n\n/*\nRerooting_dp<decltype(g),\
    \ S, e, fee, fev> dp(g);\nstruct S : \u578B\nS e() : S\u306E\u5358\u4F4D\u9650\
    \nS fee(S, S) : \u90E8\u5206\u6728\u306E\u7D50\u5408\nS fev(S, int) : \u8FBA e\
    \ \u304B\u3089\u9802\u70B9 v \u306B\n*/\ntemplate <class TREE, class S, S (*e)(),\
    \ S (*fee)(S, S), S (*fev)(S, int)>\nstruct Rerooting_dp\n{\n    TREE& g;\n  \
    \  int n;\n    vector<S> subtree;\n    vector<S> rev_subtree;\n    vector<S> ans;\n\
    \n    Rerooting_dp() {}\n    Rerooting_dp(TREE& _g) : g(_g), n(_g.n) { build();\
    \ }\n\n    S& operator[](int i) { return ans[i]; }\n\n    void build()\n    {\n\
    \        subtree.assign(n, e());\n        rev_subtree.assign(n, e());\n      \
    \  int root = g.root;\n        dfs(root);\n        dfs2(root);\n    }\n\n    S\
    \ dfs(int U)\n    {\n        S res = e();\n        int m = g[U].size();\n    \
    \    for(int i = 0; i < m; i++)\n        {\n            auto [from, to, _, __]\
    \ = g[U][i];\n            if(to == g.parent[U]) continue;\n            res = fee(res,\
    \ dfs(to));\n        }\n        return subtree[U] = fev(res, U);        \n   \
    \ }\n\n    void dfs2(int U)\n    {\n        int m = g[U].size();\n        vector<S>\
    \ l(m + 1, e()), r(m + 1, e());\n        for(int i = 0; i < m; i++)\n        {\n\
    \            auto [from, to, _, __] = g[U][i];\n            if(to == g.parent[from])\
    \ l[i + 1] = fee(l[i], rev_subtree[from]);\n            else l[i + 1] = fee(l[i],\
    \ subtree[to]);\n        }\n        for(int i = m - 1; i >= 0; i--)\n        {\n\
    \            auto [from, to, _, __] = g[U][i];\n            if(to == g.parent[U])\
    \ r[i] = fee(r[i + 1], rev_subtree[from]);\n            else r[i] = fee(r[i +\
    \ 1], subtree[to]);\n        }\n        for(int i = 0; i < m; i++)\n        {\n\
    \            auto [from, to, _, __] = g[U][i];\n            if(to == g.parent[U])\
    \ continue;\n            rev_subtree[to] = fev(fee(l[i], r[i + 1]), U);\n    \
    \        dfs2(to);\n        }\n    }\n\n    vector<S> get()\n    {\n        ans.assign(n,\
    \ e());\n        for(int i = 0; i < n; i++)\n        {\n            int m = g[i].size();\n\
    \            for(int j = 0; j < m; j++)\n            {\n                if(g[i][j].to\
    \ == g.parent[i]) ans[i] = fee(ans[i], rev_subtree[i]);\n                else\
    \ ans[i] = fee(ans[i], subtree[g[i][j].to]);\n            }\n            ans[i]\
    \ = fev(ans[i], i);\n        }\n        return ans;\n    }\n};"
  dependsOn:
  - graph/tree/tree_base.hpp
  - graph/graph_base.hpp
  isVerificationFile: false
  path: graph/tree/Rerooting_dp.hpp
  requiredBy: []
  timestamp: '2024-06-17 21:21:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree/Rerooting_dp.hpp
layout: document
redirect_from:
- /library/graph/tree/Rerooting_dp.hpp
- /library/graph/tree/Rerooting_dp.hpp.html
title: graph/tree/Rerooting_dp.hpp
---
