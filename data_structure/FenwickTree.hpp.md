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
  bundledCode: "#line 2 \"data_structure/FenwickTree.hpp\"\n\ntemplate <class T =\
    \ long long>\nstruct FenwickTree\n{\n\tint n;\n\tvector<T> data;\n\n\tFenwickTree(int\
    \ k) : n(k), data(k, 0) {}\n\n\tvoid add(int p, T x) // add x at p\n\t{\n\t\t\
    assert(0 <= p && p < n);\n\t\tfor (++p; p <= n; p += (p & -p)) data[p - 1] +=\
    \ x;\n\t}\n\n\tT get(int l, int r) // sum [l, r)\n\t{\n\t\tassert(0 <= l && l\
    \ <= r && r <= n);\n\t\treturn sum(r) - sum(l);\n\t}\n\n\tT sum(int x)\n\t{\n\t\
    \tT s = 0;\n\t\tfor (; x > 0; x -= (x & -x)) s += data[x - 1];\n\t\treturn s;\n\
    \t}\n};\n"
  code: "#pragma once\n\ntemplate <class T = long long>\nstruct FenwickTree\n{\n\t\
    int n;\n\tvector<T> data;\n\n\tFenwickTree(int k) : n(k), data(k, 0) {}\n\n\t\
    void add(int p, T x) // add x at p\n\t{\n\t\tassert(0 <= p && p < n);\n\t\tfor\
    \ (++p; p <= n; p += (p & -p)) data[p - 1] += x;\n\t}\n\n\tT get(int l, int r)\
    \ // sum [l, r)\n\t{\n\t\tassert(0 <= l && l <= r && r <= n);\n\t\treturn sum(r)\
    \ - sum(l);\n\t}\n\n\tT sum(int x)\n\t{\n\t\tT s = 0;\n\t\tfor (; x > 0; x -=\
    \ (x & -x)) s += data[x - 1];\n\t\treturn s;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/FenwickTree.hpp
  requiredBy: []
  timestamp: '2023-09-05 17:22:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/FenwickTree.hpp
layout: document
redirect_from:
- /library/data_structure/FenwickTree.hpp
- /library/data_structure/FenwickTree.hpp.html
title: data_structure/FenwickTree.hpp
---
