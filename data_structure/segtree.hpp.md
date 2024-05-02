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
  bundledCode: "#line 2 \"data_structure/segtree.hpp\"\n\n/*\nMonoid\u304C\u5FC5\u8981\
    \nsegtree(), segtree(int k), segtree(vector<Monoid::TYPE> v)\n1,2\u756A\u76EE\u306F\
    \ operator[i]\u3067\u8FFD\u52A0\u3057\u3066 init()\u304C\u5FC5\u8981\nvoid set(int\
    \ i, T x) [i] \u3092 x \u306B\u8A2D\u5B9A\nvoid add(int i, T x) [i] \u306B x \u3092\
    \u8DB3\u3059(Monoid \u306E op \u3092\u9069\u7528\u3059\u308B)\nT get(int l, int\
    \ r) [l, r) \u306E\u6F14\u7B97\u7D50\u679C\u3092\u5F97\u308B\n*/\ntemplate <class\
    \ Monoid>\nstruct segtree\n{\n  private:\n\tusing T = typename Monoid::TYPE;\n\
    \tint n;\n\tvector<T> v;\n\t\n\tvoid upd(int i) { v[i] = Monoid::op(v[i << 1],\
    \ v[i << 1 | 1]); }\n\n  public:\n\tsegtree() : segtree(vector<T>(0)){}\n\tsegtree(int\
    \ k) : segtree(vector<T>(k, Monoid::e())) {}\n\tsegtree(const vector<T>& _v)\n\
    \t{\n\t\tint k = _v.size();\n\t\tn = 1; while(n < k) n <<= 1;\n\t\tv = vector<T>(n\
    \ << 1, Monoid::e());\n\t\tfor(int i = 0; i < k; i++) v[i + n] = _v[i];\n\t\t\
    init();\n\t}\n\n\tT& operator[](int i) { return v[i + n]; }\n\n\tvoid init() {\
    \ for (int i = n - 1; i; i--) upd(i); }\n\n\tvoid set(int i, T x) { for (i +=\
    \ n, v[i] = x, i >>= 1; i; i >>= 1) upd(i); }\n\n\tvoid add(int i, T x) { for\
    \ (i += n, v[i] += x, i >>= 1; i; i >>= 1) upd(i); }\n\n\tT get(int l, int r)\
    \ // [l, r)\n\t{\n\t\tT ls = Monoid::e(), rs = Monoid::e();\n\t\tl += n; r +=\
    \ n;\n\n\t\twhile (l < r) {\n\t\t\tif (l & 1) ls = Monoid::op(ls, v[l++]);\n\t\
    \t\tif (r & 1) rs = Monoid::op(v[--r], rs);\n\t\t\tl >>= 1; r >>= 1;\n\t\t}\n\t\
    \treturn Monoid::op(ls, rs);\n\t}\n};\n"
  code: "#pragma once\n\n/*\nMonoid\u304C\u5FC5\u8981\nsegtree(), segtree(int k),\
    \ segtree(vector<Monoid::TYPE> v)\n1,2\u756A\u76EE\u306F operator[i]\u3067\u8FFD\
    \u52A0\u3057\u3066 init()\u304C\u5FC5\u8981\nvoid set(int i, T x) [i] \u3092 x\
    \ \u306B\u8A2D\u5B9A\nvoid add(int i, T x) [i] \u306B x \u3092\u8DB3\u3059(Monoid\
    \ \u306E op \u3092\u9069\u7528\u3059\u308B)\nT get(int l, int r) [l, r) \u306E\
    \u6F14\u7B97\u7D50\u679C\u3092\u5F97\u308B\n*/\ntemplate <class Monoid>\nstruct\
    \ segtree\n{\n  private:\n\tusing T = typename Monoid::TYPE;\n\tint n;\n\tvector<T>\
    \ v;\n\t\n\tvoid upd(int i) { v[i] = Monoid::op(v[i << 1], v[i << 1 | 1]); }\n\
    \n  public:\n\tsegtree() : segtree(vector<T>(0)){}\n\tsegtree(int k) : segtree(vector<T>(k,\
    \ Monoid::e())) {}\n\tsegtree(const vector<T>& _v)\n\t{\n\t\tint k = _v.size();\n\
    \t\tn = 1; while(n < k) n <<= 1;\n\t\tv = vector<T>(n << 1, Monoid::e());\n\t\t\
    for(int i = 0; i < k; i++) v[i + n] = _v[i];\n\t\tinit();\n\t}\n\n\tT& operator[](int\
    \ i) { return v[i + n]; }\n\n\tvoid init() { for (int i = n - 1; i; i--) upd(i);\
    \ }\n\n\tvoid set(int i, T x) { for (i += n, v[i] = x, i >>= 1; i; i >>= 1) upd(i);\
    \ }\n\n\tvoid add(int i, T x) { for (i += n, v[i] += x, i >>= 1; i; i >>= 1) upd(i);\
    \ }\n\n\tT get(int l, int r) // [l, r)\n\t{\n\t\tT ls = Monoid::e(), rs = Monoid::e();\n\
    \t\tl += n; r += n;\n\n\t\twhile (l < r) {\n\t\t\tif (l & 1) ls = Monoid::op(ls,\
    \ v[l++]);\n\t\t\tif (r & 1) rs = Monoid::op(v[--r], rs);\n\t\t\tl >>= 1; r >>=\
    \ 1;\n\t\t}\n\t\treturn Monoid::op(ls, rs);\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/segtree.hpp
  requiredBy: []
  timestamp: '2024-05-03 01:19:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/segtree.hpp
layout: document
redirect_from:
- /library/data_structure/segtree.hpp
- /library/data_structure/segtree.hpp.html
title: data_structure/segtree.hpp
---
