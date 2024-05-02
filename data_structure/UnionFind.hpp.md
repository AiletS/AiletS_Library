---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/UnionFind.test.cpp
    title: verify/UnionFind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/UnionFind.hpp\"\n\n/* \nUnionFind\nUnionfind(int\
    \ n) \u30B5\u30A4\u30BA n \u3067\u751F\u6210\nfind(int x) x \u306E\u4EE3\u8868\
    \u3092\u53D6\u5F97\nunite(int x, int y) x, y \u3092\u7D50\u5408\nsame(int x, int\
    \ y) x, y \u304C\u540C\u3058\u30B0\u30EB\u30FC\u30D7\u3067\u3042\u308B\u304B\u3092\
    \u53D6\u5F97\ngroup() \u73FE\u5728\u306E\u30B0\u30EB\u30FC\u30D7\u306E\u500B\u6570\
    \u3092\u53D6\u5F97\nsize(int x) x \u304C\u542B\u307E\u308C\u3066\u3044\u308B\u30B0\
    \u30EB\u30FC\u30D7\u306E\u30B5\u30A4\u30BA\u3092\u53D6\u5F97\n*/\nstruct UnionFind\n\
    {\n\tUnionFind(int n) : gr(n), par(n), rk(n, 0), SIZE(n, 1) // initialize\n\t\
    {\n\t\tiota(par.begin(), par.end(), 0);\n\t}\n\n\tint find(int x) // find parent\n\
    \t{\n\t\tif (par[x] == x) return x;\n\t\telse return par[x] = find(par[x]);\n\t\
    }\n\n\tbool unite(int x, int y) // unite two nodes\n\t{\n\t\tx = find(x), y =\
    \ find(y);\n\t\tif (x == y) return false;\n\n\t\tgr--;\n\t\tif (rk[x] < rk[y])\
    \ { par[x] = y, SIZE[y] += SIZE[x]; }\n\t\telse\n\t\t{\n\t\t\tpar[y] = x; SIZE[x]\
    \ += SIZE[y];\n\t\t\tif (rk[x] == rk[y]) rk[x]++;\n\t\t}\n\t\treturn true;\n\t\
    }\n\n\tbool same(int x, int y) { return find(x) == find(y); }\n\t// judge two\
    \ nodes' parents are the same\n\n\tint group() { return gr; }\n\t// total number\
    \ of connectivity components\n\n\tint size(int x) { return SIZE[find(x)]; }\n\t\
    // number of nodes in the connection component containing x  \n\nprivate:\n\t\
    vector<int> par, rk, SIZE;\n\tint gr;\n};\n"
  code: "#pragma once\n\n/* \nUnionFind\nUnionfind(int n) \u30B5\u30A4\u30BA n \u3067\
    \u751F\u6210\nfind(int x) x \u306E\u4EE3\u8868\u3092\u53D6\u5F97\nunite(int x,\
    \ int y) x, y \u3092\u7D50\u5408\nsame(int x, int y) x, y \u304C\u540C\u3058\u30B0\
    \u30EB\u30FC\u30D7\u3067\u3042\u308B\u304B\u3092\u53D6\u5F97\ngroup() \u73FE\u5728\
    \u306E\u30B0\u30EB\u30FC\u30D7\u306E\u500B\u6570\u3092\u53D6\u5F97\nsize(int x)\
    \ x \u304C\u542B\u307E\u308C\u3066\u3044\u308B\u30B0\u30EB\u30FC\u30D7\u306E\u30B5\
    \u30A4\u30BA\u3092\u53D6\u5F97\n*/\nstruct UnionFind\n{\n\tUnionFind(int n) :\
    \ gr(n), par(n), rk(n, 0), SIZE(n, 1) // initialize\n\t{\n\t\tiota(par.begin(),\
    \ par.end(), 0);\n\t}\n\n\tint find(int x) // find parent\n\t{\n\t\tif (par[x]\
    \ == x) return x;\n\t\telse return par[x] = find(par[x]);\n\t}\n\n\tbool unite(int\
    \ x, int y) // unite two nodes\n\t{\n\t\tx = find(x), y = find(y);\n\t\tif (x\
    \ == y) return false;\n\n\t\tgr--;\n\t\tif (rk[x] < rk[y]) { par[x] = y, SIZE[y]\
    \ += SIZE[x]; }\n\t\telse\n\t\t{\n\t\t\tpar[y] = x; SIZE[x] += SIZE[y];\n\t\t\t\
    if (rk[x] == rk[y]) rk[x]++;\n\t\t}\n\t\treturn true;\n\t}\n\n\tbool same(int\
    \ x, int y) { return find(x) == find(y); }\n\t// judge two nodes' parents are\
    \ the same\n\n\tint group() { return gr; }\n\t// total number of connectivity\
    \ components\n\n\tint size(int x) { return SIZE[find(x)]; }\n\t// number of nodes\
    \ in the connection component containing x  \n\nprivate:\n\tvector<int> par, rk,\
    \ SIZE;\n\tint gr;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/UnionFind.hpp
  requiredBy: []
  timestamp: '2024-05-03 01:16:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/UnionFind.test.cpp
documentation_of: data_structure/UnionFind.hpp
layout: document
redirect_from:
- /library/data_structure/UnionFind.hpp
- /library/data_structure/UnionFind.hpp.html
title: data_structure/UnionFind.hpp
---
