---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/tree/CompressTree.hpp
    title: graph/tree/CompressTree.hpp
  - icon: ':x:'
    path: graph/tree/lca.hpp
    title: graph/tree/lca.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/library_checker/Lowest_Common_Ancestor.test.cpp
    title: verify/library_checker/Lowest_Common_Ancestor.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/SparseTable.hpp\"\n\n/*\n\u51AA\u7B49\u306A\
    \ Monoid \u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B (f(f(x)) = f(x))\n\u51AA\
    \u7B49\u6027\u3068\u7D50\u5408\u6E2C\u304C\u6E80\u305F\u3055\u308C\u308C\u3070\
    \u826F\u3044\n\nSparseTable\nSparseTable<monoid>(vector<monoid::TYPE> v)\nget(int\
    \ l, int r) [l, r) \u306E\u7D50\u679C\u3092\u53D6\u5F97\n*/\ntemplate <class Monoid>\n\
    struct SparseTable\n{\n    using T = typename Monoid::TYPE;\n    SparseTable()\
    \ {}\n    SparseTable(const vector<T>& _v) : n(_v.size()), w(n + 1)\n    {\n \
    \       for (int i = 2; i < n + 1; i++) w[i] = w[i >> 1] + 1;\n\t\tv = vector<vector<T>>(w[n]\
    \ + 1, vector<T>(n, Monoid::e()));\n\t\tfor (int i = 0; i < n; i++) v[0][i] =\
    \ _v[i];\n\t\tfor (int i = 1; (1 << i) <= n; i++)\n\t\t\tfor (int j = 0; j + (1\
    \ << i) <= n; j++)\n\t\t\t{\n\t\t\t\tv[i][j] = Monoid::op(v[i - 1][j], v[i - 1][j\
    \ + (1 << (i - 1))]);\n\t\t\t}\n    }\n\n    T get(int l, int r)\n    {\n    \
    \    assert(l <= r && l >= 0 && l < n && r >= 0 && r <= n);\n        int k = w[r\
    \ - l];\n\t\treturn Monoid::op(v[k][l], v[k][r - (1 << k)]);\n    }\n\nprivate:\n\
    \    int n;\n    vector<int> w;\n    vector<vector<T>> v;\n};\n"
  code: "#pragma once\n\n/*\n\u51AA\u7B49\u306A Monoid \u3067\u3042\u308B\u5FC5\u8981\
    \u304C\u3042\u308B (f(f(x)) = f(x))\n\u51AA\u7B49\u6027\u3068\u7D50\u5408\u6E2C\
    \u304C\u6E80\u305F\u3055\u308C\u308C\u3070\u826F\u3044\n\nSparseTable\nSparseTable<monoid>(vector<monoid::TYPE>\
    \ v)\nget(int l, int r) [l, r) \u306E\u7D50\u679C\u3092\u53D6\u5F97\n*/\ntemplate\
    \ <class Monoid>\nstruct SparseTable\n{\n    using T = typename Monoid::TYPE;\n\
    \    SparseTable() {}\n    SparseTable(const vector<T>& _v) : n(_v.size()), w(n\
    \ + 1)\n    {\n        for (int i = 2; i < n + 1; i++) w[i] = w[i >> 1] + 1;\n\
    \t\tv = vector<vector<T>>(w[n] + 1, vector<T>(n, Monoid::e()));\n\t\tfor (int\
    \ i = 0; i < n; i++) v[0][i] = _v[i];\n\t\tfor (int i = 1; (1 << i) <= n; i++)\n\
    \t\t\tfor (int j = 0; j + (1 << i) <= n; j++)\n\t\t\t{\n\t\t\t\tv[i][j] = Monoid::op(v[i\
    \ - 1][j], v[i - 1][j + (1 << (i - 1))]);\n\t\t\t}\n    }\n\n    T get(int l,\
    \ int r)\n    {\n        assert(l <= r && l >= 0 && l < n && r >= 0 && r <= n);\n\
    \        int k = w[r - l];\n\t\treturn Monoid::op(v[k][l], v[k][r - (1 << k)]);\n\
    \    }\n\nprivate:\n    int n;\n    vector<int> w;\n    vector<vector<T>> v;\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/SparseTable.hpp
  requiredBy:
  - graph/tree/lca.hpp
  - graph/tree/CompressTree.hpp
  timestamp: '2024-05-03 01:16:09+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/library_checker/Lowest_Common_Ancestor.test.cpp
documentation_of: data_structure/SparseTable.hpp
layout: document
redirect_from:
- /library/data_structure/SparseTable.hpp
- /library/data_structure/SparseTable.hpp.html
title: data_structure/SparseTable.hpp
---
