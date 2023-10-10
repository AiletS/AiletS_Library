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
  bundledCode: "#line 2 \"data_structure/segtree.hpp\"\n\ntemplate <class Monoid>\n\
    struct segtree\n{\n\tusing T = typename Monoid::TYPE;\n\tint n;\n\tvector<T> v;\n\
    \n\tsegtree() : segtree(vector<T>(0)){}\n\tsegtree(int k) : segtree(vector<T>(k,\
    \ Monoid::e())) {}\n\tsegtree(const vector<T>& _v)\n\t{\n\t\tint k = _v.size();\n\
    \t\tn = 1; while(n < k) n <<= 1;\n\t\tv = vector<T>(n << 1, Monoid::e());\n\t\t\
    for(int i = 0; i < k; i++) v[i + n] = _v[i];\n\t\tinit();\n\t}\n\n\n\tT& operator[](int\
    \ i) { return v[i + n]; }\n\n\tvoid upd(int i) { v[i] = Monoid::op(v[i << 1],\
    \ v[i << 1 | 1]); }\n\n\tvoid init() { for (int i = n - 1; i; i--) upd(i); }\n\
    \n\tvoid set(int i, T x) { for (i += n, v[i] = x, i >>= 1; i; i >>= 1) upd(i);\
    \ }\n\n\tvoid add(int i, T x) { for (i += n, v[i] += x, i >>= 1; i; i >>= 1) upd(i);\
    \ }\n\n\tT get(int l, int r) // [l, r)\n\t{\n\t\tT ls = Monoid::e(), rs = Monoid::e();\n\
    \t\tl += n; r += n;\n\n\t\twhile (l < r) {\n\t\t\tif (l & 1) ls = Monoid::op(ls,\
    \ v[l++]);\n\t\t\tif (r & 1) rs = Monoid::op(v[--r], rs);\n\t\t\tl >>= 1; r >>=\
    \ 1;\n\t\t}\n\t\treturn Monoid::op(ls, rs);\n\t}\n};\n"
  code: "#pragma once\n\ntemplate <class Monoid>\nstruct segtree\n{\n\tusing T = typename\
    \ Monoid::TYPE;\n\tint n;\n\tvector<T> v;\n\n\tsegtree() : segtree(vector<T>(0)){}\n\
    \tsegtree(int k) : segtree(vector<T>(k, Monoid::e())) {}\n\tsegtree(const vector<T>&\
    \ _v)\n\t{\n\t\tint k = _v.size();\n\t\tn = 1; while(n < k) n <<= 1;\n\t\tv =\
    \ vector<T>(n << 1, Monoid::e());\n\t\tfor(int i = 0; i < k; i++) v[i + n] = _v[i];\n\
    \t\tinit();\n\t}\n\n\n\tT& operator[](int i) { return v[i + n]; }\n\n\tvoid upd(int\
    \ i) { v[i] = Monoid::op(v[i << 1], v[i << 1 | 1]); }\n\n\tvoid init() { for (int\
    \ i = n - 1; i; i--) upd(i); }\n\n\tvoid set(int i, T x) { for (i += n, v[i] =\
    \ x, i >>= 1; i; i >>= 1) upd(i); }\n\n\tvoid add(int i, T x) { for (i += n, v[i]\
    \ += x, i >>= 1; i; i >>= 1) upd(i); }\n\n\tT get(int l, int r) // [l, r)\n\t\
    {\n\t\tT ls = Monoid::e(), rs = Monoid::e();\n\t\tl += n; r += n;\n\n\t\twhile\
    \ (l < r) {\n\t\t\tif (l & 1) ls = Monoid::op(ls, v[l++]);\n\t\t\tif (r & 1) rs\
    \ = Monoid::op(v[--r], rs);\n\t\t\tl >>= 1; r >>= 1;\n\t\t}\n\t\treturn Monoid::op(ls,\
    \ rs);\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/segtree.hpp
  requiredBy: []
  timestamp: '2023-10-01 18:02:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/segtree.hpp
layout: document
redirect_from:
- /library/data_structure/segtree.hpp
- /library/data_structure/segtree.hpp.html
title: data_structure/segtree.hpp
---
