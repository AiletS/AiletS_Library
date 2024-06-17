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
  bundledCode: "#line 2 \"data_structure/lazy_segtree.hpp\"\n\n/*\noperatormonoid\
    \ \u304C\u5FC5\u8981\nlazy_segtree(), lazy_segtree(int k), lazy_segtree(vector<T>\
    \ v)\n1,2\u756A\u76EE\u306F init() \u304C\u5FC5\u8981\nT get(int l, int r) [l,\
    \ r) \u306E\u6F14\u7B97\u7D50\u679C\u3092\u5F97\u308B\nvoid apply(int l, int r,\
    \ F f) [l, r) \u306B f \u3092\u9069\u7528\n*/\ntemplate<class OperatorMonoid>\n\
    struct lazy_segtree\n{\n  private:\n    using T = typename OperatorMonoid::TYPE_S;\n\
    \    using F = typename OperatorMonoid::TYPE_F;\n    int n, log;\n    vector<T>\
    \ d;\n    vector<F> lz;\n\n\tvoid update(int k) { d[k] = OperatorMonoid::op(d[k\
    \ << 1], d[k << 1 | 1]); }\n\n\tvoid all_apply(int k, F f)\n\t{\n        d[k]\
    \ = OperatorMonoid::mapping(f, d[k]);\n\t\tif (k < n) lz[k] = OperatorMonoid::composition(lz[k],\
    \ f);\n\t}\n\n\tvoid push(int k)\n\t{\n\t\tall_apply(2 * k, lz[k]);\n\t\tall_apply(2\
    \ * k + 1, lz[k]);\n\t\tlz[k] = OperatorMonoid::id();\n\t}\n\n  public:\n\tlazy_segtree()\
    \ : lazy_segtree(vector<T>(0)) {}\n\tlazy_segtree(int k) : lazy_segtree(vector<T>(k,\
    \ OperatorMonoid::e())) {}\n    lazy_segtree(const vector<T>& _v)\n    {\n   \
    \     int k = _v.size();\n\t\tlog = 0; while ((1 << log) < k) log++;\n\t\tn =\
    \ 1 << log;\n\t\td = vector<T>(n << 1);\n\t\tlz = vector<F>(n);\n        for(int\
    \ i = 0; i < k; i++) d[i + n] = _v[i];\n        init();\n    }\n\n\tT& operator[](int\
    \ i) { return d[i + n]; }\n\tvoid init() { for (int i = n - 1; i; i--) update(i);\
    \ }\n\n\tT get(int p) // get d[p]\n\t{\n\t\tp += n;\n\t\tfor (int i = log; i >=\
    \ 1; i--) push(p >> i);\n\t\treturn d[p];\n\t}\n\n\tT get(int l, int r) // get\
    \ [l, r)\n\t{\n\t\tif (l == r) return OperatorMonoid::e();\n\n\t\tl += n;\n\t\t\
    r += n;\n\n\t\tfor (int i = log; i >= 1; i--) {\n\t\t\tif (((l >> i) << i) !=\
    \ l) push(l >> i);\n\t\t\tif (((r >> i) << i) != r) push(r >> i);\n\t\t}\n\n\t\
    \tT sml = OperatorMonoid::e(), smr = OperatorMonoid::e();\n\t\twhile (l < r) {\n\
    \t\t\tif (l & 1) sml = OperatorMonoid::op(sml, d[l++]);\n\t\t\tif (r & 1) smr\
    \ = OperatorMonoid::op(d[--r], smr);\n\t\t\tl >>= 1; r >>= 1;\n\t\t}\n\n\t\treturn\
    \ OperatorMonoid::op(sml, smr);\n\t}\n\n\tT all_get() { return d[1]; }\n\n\tvoid\
    \ set(int p, T x) // d[p] = x\n\t{\n\t\tp += n;\n\t\tfor (int i = log; i >= 1;\
    \ i--) push(p >> i);\n\t\td[p] = x;\n\t\tfor (int i = 1; i <= log; i++) update(p\
    \ >> i);\n\t}\n\n\tvoid apply(int p, F f)  // d[p] = f(d[p])\n\t{\n\t\tp += n;\n\
    \t\tfor (int i = log; i >= 1; i--) push(p >> i);\n\t\td[p] = OperatorMonoid::mapping(f,\
    \ d[p]);\n\t\tfor (int i = 1; i <= log; i++) update(p >> i);\n\t}\n\n\tvoid apply(int\
    \ l, int r, F f) // [l, r) d[i] = f(d[i])\n\t{\n\t\tif (l == r) return;\n\n\t\t\
    l += n; r += n;\n\n\t\tfor (int i = log; i >= 1; i--) {\n\t\t\tif (((l >> i) <<\
    \ i) != l) push(l >> i);\n\t\t\tif (((r >> i) << i) != r) push((r - 1) >> i);\n\
    \t\t}\n\n\t\t{\n\t\t\tint l2 = l, r2 = r;\n\t\t\twhile (l < r) {\n\t\t\t\tif (l\
    \ & 1) all_apply(l++, f);\n\t\t\t\tif (r & 1) all_apply(--r, f);\n\t\t\t\tl >>=\
    \ 1;\n\t\t\t\tr >>= 1;\n\t\t\t}\n\t\t\tl = l2;\n\t\t\tr = r2;\n\t\t}\n\n\t\tfor\
    \ (int i = 1; i <= log; i++) {\n\t\t\tif (((l >> i) << i) != l) update(l >> i);\n\
    \t\t\tif (((r >> i) << i) != r) update((r - 1) >> i);\n\t\t}\n\t}\n};\n"
  code: "#pragma once\n\n/*\noperatormonoid \u304C\u5FC5\u8981\nlazy_segtree(), lazy_segtree(int\
    \ k), lazy_segtree(vector<T> v)\n1,2\u756A\u76EE\u306F init() \u304C\u5FC5\u8981\
    \nT get(int l, int r) [l, r) \u306E\u6F14\u7B97\u7D50\u679C\u3092\u5F97\u308B\n\
    void apply(int l, int r, F f) [l, r) \u306B f \u3092\u9069\u7528\n*/\ntemplate<class\
    \ OperatorMonoid>\nstruct lazy_segtree\n{\n  private:\n    using T = typename\
    \ OperatorMonoid::TYPE_S;\n    using F = typename OperatorMonoid::TYPE_F;\n  \
    \  int n, log;\n    vector<T> d;\n    vector<F> lz;\n\n\tvoid update(int k) {\
    \ d[k] = OperatorMonoid::op(d[k << 1], d[k << 1 | 1]); }\n\n\tvoid all_apply(int\
    \ k, F f)\n\t{\n        d[k] = OperatorMonoid::mapping(f, d[k]);\n\t\tif (k <\
    \ n) lz[k] = OperatorMonoid::composition(lz[k], f);\n\t}\n\n\tvoid push(int k)\n\
    \t{\n\t\tall_apply(2 * k, lz[k]);\n\t\tall_apply(2 * k + 1, lz[k]);\n\t\tlz[k]\
    \ = OperatorMonoid::id();\n\t}\n\n  public:\n\tlazy_segtree() : lazy_segtree(vector<T>(0))\
    \ {}\n\tlazy_segtree(int k) : lazy_segtree(vector<T>(k, OperatorMonoid::e()))\
    \ {}\n    lazy_segtree(const vector<T>& _v)\n    {\n        int k = _v.size();\n\
    \t\tlog = 0; while ((1 << log) < k) log++;\n\t\tn = 1 << log;\n\t\td = vector<T>(n\
    \ << 1);\n\t\tlz = vector<F>(n);\n        for(int i = 0; i < k; i++) d[i + n]\
    \ = _v[i];\n        init();\n    }\n\n\tT& operator[](int i) { return d[i + n];\
    \ }\n\tvoid init() { for (int i = n - 1; i; i--) update(i); }\n\n\tT get(int p)\
    \ // get d[p]\n\t{\n\t\tp += n;\n\t\tfor (int i = log; i >= 1; i--) push(p >>\
    \ i);\n\t\treturn d[p];\n\t}\n\n\tT get(int l, int r) // get [l, r)\n\t{\n\t\t\
    if (l == r) return OperatorMonoid::e();\n\n\t\tl += n;\n\t\tr += n;\n\n\t\tfor\
    \ (int i = log; i >= 1; i--) {\n\t\t\tif (((l >> i) << i) != l) push(l >> i);\n\
    \t\t\tif (((r >> i) << i) != r) push(r >> i);\n\t\t}\n\n\t\tT sml = OperatorMonoid::e(),\
    \ smr = OperatorMonoid::e();\n\t\twhile (l < r) {\n\t\t\tif (l & 1) sml = OperatorMonoid::op(sml,\
    \ d[l++]);\n\t\t\tif (r & 1) smr = OperatorMonoid::op(d[--r], smr);\n\t\t\tl >>=\
    \ 1; r >>= 1;\n\t\t}\n\n\t\treturn OperatorMonoid::op(sml, smr);\n\t}\n\n\tT all_get()\
    \ { return d[1]; }\n\n\tvoid set(int p, T x) // d[p] = x\n\t{\n\t\tp += n;\n\t\
    \tfor (int i = log; i >= 1; i--) push(p >> i);\n\t\td[p] = x;\n\t\tfor (int i\
    \ = 1; i <= log; i++) update(p >> i);\n\t}\n\n\tvoid apply(int p, F f)  // d[p]\
    \ = f(d[p])\n\t{\n\t\tp += n;\n\t\tfor (int i = log; i >= 1; i--) push(p >> i);\n\
    \t\td[p] = OperatorMonoid::mapping(f, d[p]);\n\t\tfor (int i = 1; i <= log; i++)\
    \ update(p >> i);\n\t}\n\n\tvoid apply(int l, int r, F f) // [l, r) d[i] = f(d[i])\n\
    \t{\n\t\tif (l == r) return;\n\n\t\tl += n; r += n;\n\n\t\tfor (int i = log; i\
    \ >= 1; i--) {\n\t\t\tif (((l >> i) << i) != l) push(l >> i);\n\t\t\tif (((r >>\
    \ i) << i) != r) push((r - 1) >> i);\n\t\t}\n\n\t\t{\n\t\t\tint l2 = l, r2 = r;\n\
    \t\t\twhile (l < r) {\n\t\t\t\tif (l & 1) all_apply(l++, f);\n\t\t\t\tif (r &\
    \ 1) all_apply(--r, f);\n\t\t\t\tl >>= 1;\n\t\t\t\tr >>= 1;\n\t\t\t}\n\t\t\tl\
    \ = l2;\n\t\t\tr = r2;\n\t\t}\n\n\t\tfor (int i = 1; i <= log; i++) {\n\t\t\t\
    if (((l >> i) << i) != l) update(l >> i);\n\t\t\tif (((r >> i) << i) != r) update((r\
    \ - 1) >> i);\n\t\t}\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/lazy_segtree.hpp
  requiredBy: []
  timestamp: '2024-06-17 21:21:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/lazy_segtree.hpp
layout: document
redirect_from:
- /library/data_structure/lazy_segtree.hpp
- /library/data_structure/lazy_segtree.hpp.html
title: data_structure/lazy_segtree.hpp
---
