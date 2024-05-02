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
  bundledCode: "#line 2 \"data_structure/Weighted_UnionFind.hpp\"\n\n/*\nWeighted_UnionFind<T\
    \ = long long>(int n, T off = 0) : \u91CD\u307F\u306F\u6700\u521D off \u306E\u30B5\
    \u30A4\u30BA n \u3067\u751F\u6210\nfind(int x) x \u306E\u4EE3\u8868\u3092\u53D6\
    \u5F97\nweight(int x) x \u304C\u542B\u307E\u308C\u3066\u3044\u308B\u30B0\u30EB\
    \u30FC\u30D7\u306E\u91CD\u307F\u3092\u53D6\u5F97\nunite(int x, int y, T weight)\
    \ x, y \u3092\u91CD\u307F\u304C y - x = weight \u306B\u306A\u308B\u3088\u3046\u306B\
    \u7D50\u5408\nsame(int x, int y) x, y \u304C\u540C\u3058\u30B0\u30EB\u30FC\u30D7\
    \u3067\u3042\u308B\u304B\u3092\u53D6\u5F97\ngroup() \u73FE\u5728\u306E\u30B0\u30EB\
    \u30FC\u30D7\u306E\u500B\u6570\u3092\u53D6\u5F97\nsize(int x) x \u304C\u542B\u307E\
    \u308C\u3066\u3044\u308B\u30B0\u30EB\u30FC\u30D7\u306E\u30B5\u30A4\u30BA\u3092\
    \u53D6\u5F97\ndiff(int x, int y) \u91CD\u307F\u306E\u5DEE weight(y) - weight(x)\
    \ \u3092\u53D6\u5F97\n*/\ntemplate <class T = long long>\nclass Weighted_UnionFind\n\
    {\n  private:\n    vector<int> par, rk, SIZE;\n    vector<T> w;\n    int gr;\n\
    \n  public:\n    Weighted_UnionFind(int n, T off = 0) : gr(n), par(n), rk(n, 0),\
    \ SIZE(n, 1), w(n, off) // initialize\n    {\n        iota(par.begin(), par.end(),\
    \ 0);\n    }\n\n    int find(int x) // find parent\n    {\n        if (par[x]\
    \ == x) return x;\n        else { int r = find(par[x]); w[x] += w[par[x]]; return\
    \ par[x] = r; }\n    }\n\n    T weight(int x) { find(x); return w[x]; }\n\n  \
    \  bool unite(int x, int y, T _weight) // unite two nodes, y - x = _weight\n \
    \   {\n        _weight += weight(x); _weight -= weight(y);\n        x = find(x),\
    \ y = find(y);\n        if (x == y) return diff(x, y) == _weight;\n\n        gr--;\n\
    \        if(rk[x] < rk[y]) swap(x, y) , _weight = -_weight;\n        if(rk[x]\
    \ == rk[y]) rk[x]++;\n        par[y] = x; SIZE[x] += SIZE[y];\n        w[y] =\
    \ _weight;\n        return true;\n    }\n\n    bool same(int x, int y) { return\
    \ find(x) == find(y); }\n    // judge two nodes' parents are the same\n\n    int\
    \ group() { return gr; }\n    // total number of connectivity components\n\n \
    \   int size(int x) { return SIZE[find(x)]; }\n    // number of nodes in the connection\
    \ component containing x\n\n    T diff(int x, int y) { return weight(y) - weight(x);\
    \ }\n    // return weight(y - x)\n};\n"
  code: "#pragma once\n\n/*\nWeighted_UnionFind<T = long long>(int n, T off = 0) :\
    \ \u91CD\u307F\u306F\u6700\u521D off \u306E\u30B5\u30A4\u30BA n \u3067\u751F\u6210\
    \nfind(int x) x \u306E\u4EE3\u8868\u3092\u53D6\u5F97\nweight(int x) x \u304C\u542B\
    \u307E\u308C\u3066\u3044\u308B\u30B0\u30EB\u30FC\u30D7\u306E\u91CD\u307F\u3092\
    \u53D6\u5F97\nunite(int x, int y, T weight) x, y \u3092\u91CD\u307F\u304C y -\
    \ x = weight \u306B\u306A\u308B\u3088\u3046\u306B\u7D50\u5408\nsame(int x, int\
    \ y) x, y \u304C\u540C\u3058\u30B0\u30EB\u30FC\u30D7\u3067\u3042\u308B\u304B\u3092\
    \u53D6\u5F97\ngroup() \u73FE\u5728\u306E\u30B0\u30EB\u30FC\u30D7\u306E\u500B\u6570\
    \u3092\u53D6\u5F97\nsize(int x) x \u304C\u542B\u307E\u308C\u3066\u3044\u308B\u30B0\
    \u30EB\u30FC\u30D7\u306E\u30B5\u30A4\u30BA\u3092\u53D6\u5F97\ndiff(int x, int\
    \ y) \u91CD\u307F\u306E\u5DEE weight(y) - weight(x) \u3092\u53D6\u5F97\n*/\ntemplate\
    \ <class T = long long>\nclass Weighted_UnionFind\n{\n  private:\n    vector<int>\
    \ par, rk, SIZE;\n    vector<T> w;\n    int gr;\n\n  public:\n    Weighted_UnionFind(int\
    \ n, T off = 0) : gr(n), par(n), rk(n, 0), SIZE(n, 1), w(n, off) // initialize\n\
    \    {\n        iota(par.begin(), par.end(), 0);\n    }\n\n    int find(int x)\
    \ // find parent\n    {\n        if (par[x] == x) return x;\n        else { int\
    \ r = find(par[x]); w[x] += w[par[x]]; return par[x] = r; }\n    }\n\n    T weight(int\
    \ x) { find(x); return w[x]; }\n\n    bool unite(int x, int y, T _weight) // unite\
    \ two nodes, y - x = _weight\n    {\n        _weight += weight(x); _weight -=\
    \ weight(y);\n        x = find(x), y = find(y);\n        if (x == y) return diff(x,\
    \ y) == _weight;\n\n        gr--;\n        if(rk[x] < rk[y]) swap(x, y) , _weight\
    \ = -_weight;\n        if(rk[x] == rk[y]) rk[x]++;\n        par[y] = x; SIZE[x]\
    \ += SIZE[y];\n        w[y] = _weight;\n        return true;\n    }\n\n    bool\
    \ same(int x, int y) { return find(x) == find(y); }\n    // judge two nodes' parents\
    \ are the same\n\n    int group() { return gr; }\n    // total number of connectivity\
    \ components\n\n    int size(int x) { return SIZE[find(x)]; }\n    // number of\
    \ nodes in the connection component containing x\n\n    T diff(int x, int y) {\
    \ return weight(y) - weight(x); }\n    // return weight(y - x)\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/Weighted_UnionFind.hpp
  requiredBy: []
  timestamp: '2024-05-03 01:19:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/Weighted_UnionFind.hpp
layout: document
redirect_from:
- /library/data_structure/Weighted_UnionFind.hpp
- /library/data_structure/Weighted_UnionFind.hpp.html
title: data_structure/Weighted_UnionFind.hpp
---
