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
  bundledCode: "#line 2 \"data_structure/FenwickTree.hpp\"\n\n/*\nFenwickTree (BIT)\n\
    FenwickTree<T = long long>(), FenwickTree<T = long long>(int _n) \u30B5\u30A4\u30BA\
    \ n \u3067\u751F\u6210\nadd(int p, T x) p \u306B x \u3092\u8DB3\u3059\nget(int\
    \ l, int r) [l, r) \u306E\u548C\u3092\u53D6\u5F97\n*/\ntemplate <class T = long\
    \ long>\nclass FenwickTree\n{\n  public:\n\tFenwickTree() : n(0) {}\n\tFenwickTree(int\
    \ _n) : n(_n), data(_n, 0) {}\n\n\tvoid add(int p, T x) // add x at p\n\t{\n\t\
    \tassert(0 <= p && p < n);\n\t\tfor (++p; p <= n; p += (p & -p)) data[p - 1] +=\
    \ x;\n\t}\n\n\tT get(int l, int r) // sum [l, r)\n\t{\n\t\tassert(0 <= l && l\
    \ <= r && r <= n);\n\t\treturn sum(r) - sum(l);\n\t}\n\n  private:\n\tint n;\n\
    \tvector<T> data;\n\n\tT sum(int x)\n\t{\n\t\tT s = 0;\n\t\tfor (; x > 0; x -=\
    \ (x & -x)) s += data[x - 1];\n\t\treturn s;\n\t}\n};\n"
  code: "#pragma once\n\n/*\nFenwickTree (BIT)\nFenwickTree<T = long long>(), FenwickTree<T\
    \ = long long>(int _n) \u30B5\u30A4\u30BA n \u3067\u751F\u6210\nadd(int p, T x)\
    \ p \u306B x \u3092\u8DB3\u3059\nget(int l, int r) [l, r) \u306E\u548C\u3092\u53D6\
    \u5F97\n*/\ntemplate <class T = long long>\nclass FenwickTree\n{\n  public:\n\t\
    FenwickTree() : n(0) {}\n\tFenwickTree(int _n) : n(_n), data(_n, 0) {}\n\n\tvoid\
    \ add(int p, T x) // add x at p\n\t{\n\t\tassert(0 <= p && p < n);\n\t\tfor (++p;\
    \ p <= n; p += (p & -p)) data[p - 1] += x;\n\t}\n\n\tT get(int l, int r) // sum\
    \ [l, r)\n\t{\n\t\tassert(0 <= l && l <= r && r <= n);\n\t\treturn sum(r) - sum(l);\n\
    \t}\n\n  private:\n\tint n;\n\tvector<T> data;\n\n\tT sum(int x)\n\t{\n\t\tT s\
    \ = 0;\n\t\tfor (; x > 0; x -= (x & -x)) s += data[x - 1];\n\t\treturn s;\n\t\
    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/FenwickTree.hpp
  requiredBy: []
  timestamp: '2024-05-03 01:16:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/FenwickTree.hpp
layout: document
redirect_from:
- /library/data_structure/FenwickTree.hpp
- /library/data_structure/FenwickTree.hpp.html
title: data_structure/FenwickTree.hpp
---
