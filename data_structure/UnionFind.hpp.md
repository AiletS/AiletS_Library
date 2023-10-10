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
  bundledCode: "#line 2 \"data_structure/UnionFind.hpp\"\n\nstruct UnionFind\n{\n\t\
    vector<int> par, rk, SIZE;\n\tint gr;\n\n\tUnionFind(int n) : gr(n), par(n), rk(n,\
    \ 0), SIZE(n, 1) // initialize\n\t{\n\t\tiota(par.begin(), par.end(), 0);\n\t\
    }\n\n\tint find(int x) // find parent\n\t{\n\t\tif (par[x] == x) return x;\n\t\
    \telse return par[x] = find(par[x]);\n\t}\n\n\tbool unite(int x, int y) // unite\
    \ two nodes\n\t{\n\t\tx = find(x), y = find(y);\n\t\tif (x == y) return false;\n\
    \n\t\tgr--;\n\t\tif (rk[x] < rk[y]) { par[x] = y, SIZE[y] += SIZE[x]; }\n\t\t\
    else\n\t\t{\n\t\t\tpar[y] = x; SIZE[x] += SIZE[y];\n\t\t\tif (rk[x] == rk[y])\
    \ rk[x]++;\n\t\t}\n\t\treturn true;\n\t}\n\n\tbool same(int x, int y) { return\
    \ find(x) == find(y); }\n\t// judge two nodes' parents are the same\n\n\tint group()\
    \ { return gr; }\n\t// total number of connectivity components\n\n\tint size(int\
    \ x) { return SIZE[find(x)]; }\n\t// number of nodes in the connection component\
    \ containing x\n};\n"
  code: "#pragma once\n\nstruct UnionFind\n{\n\tvector<int> par, rk, SIZE;\n\tint\
    \ gr;\n\n\tUnionFind(int n) : gr(n), par(n), rk(n, 0), SIZE(n, 1) // initialize\n\
    \t{\n\t\tiota(par.begin(), par.end(), 0);\n\t}\n\n\tint find(int x) // find parent\n\
    \t{\n\t\tif (par[x] == x) return x;\n\t\telse return par[x] = find(par[x]);\n\t\
    }\n\n\tbool unite(int x, int y) // unite two nodes\n\t{\n\t\tx = find(x), y =\
    \ find(y);\n\t\tif (x == y) return false;\n\n\t\tgr--;\n\t\tif (rk[x] < rk[y])\
    \ { par[x] = y, SIZE[y] += SIZE[x]; }\n\t\telse\n\t\t{\n\t\t\tpar[y] = x; SIZE[x]\
    \ += SIZE[y];\n\t\t\tif (rk[x] == rk[y]) rk[x]++;\n\t\t}\n\t\treturn true;\n\t\
    }\n\n\tbool same(int x, int y) { return find(x) == find(y); }\n\t// judge two\
    \ nodes' parents are the same\n\n\tint group() { return gr; }\n\t// total number\
    \ of connectivity components\n\n\tint size(int x) { return SIZE[find(x)]; }\n\t\
    // number of nodes in the connection component containing x\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/UnionFind.hpp
  requiredBy: []
  timestamp: '2023-09-05 17:24:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/UnionFind.hpp
layout: document
redirect_from:
- /library/data_structure/UnionFind.hpp
- /library/data_structure/UnionFind.hpp.html
title: data_structure/UnionFind.hpp
---
