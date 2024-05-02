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
  bundledCode: "#line 2 \"data_structure/merge_sort_tree.hpp\"\n\n/*\nmerge sort tree\n\
    merge_sorte_tree<T = long long>(vector<T> v)\npair<T,T> get(l, r, x) : [l, r)\
    \ \u306E\u533A\u9593\u3067 x \u4EE5\u4E0B\u306E\u3082\u306E\u306E\u500B\u6570\u3068\
    \u305D\u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B O(log^2 N)\n*/\ntemplate <typename\
    \ T = long long>\nstruct merge_sort_tree\n{\n    int n;\n    vector<vector<T>>\
    \ v;\n    vector<vector<T>> sum;\n\n    merge_sort_tree() {}\n    merge_sort_tree(const\
    \ vector<T>& _v)\n    {\n        int m = _v.size();\n        n = 1; while(n <\
    \ m) n <<= 1;\n        v.resize(n << 1);\n        sum = vector<vector<T>>(n <<\
    \ 1, vector<T>(1));\n        for(int i = 0; i < m; i++) \n        {\n        \
    \    v[i + n].push_back(_v[i]);\n            sum[i + n].push_back(_v[i]);\n  \
    \      }\n        init();\n    }\n\n    void init()\n    {\n        for(int i\
    \ = n - 1; i >= 1; i--)\n        {\n            int l = i << 1, r = l | 1;\n \
    \           merge(v[l].begin(), v[l].end(),\n                  v[r].begin(), v[r].end(),\n\
    \                  back_inserter(v[i]));\n            sum[i] = vector<T>(v[i].size()\
    \ + 1, 0);\n            rep(j, 0, v[i].size()) sum[i][j + 1] = sum[i][j] + v[i][j];\n\
    \        }\n    }\n\n    pair<T, T> get(int i, T x)\n    {\n        int j = upper_bound(v[i].begin(),\
    \ v[i].end(), x) - v[i].begin();\n        return {j, sum[i][j]};\n    }\n\n  \
    \  pair<T, T> get(int l, int r, T x)\n    {\n        l += n, r += n;\n       \
    \ pair<T, T> res = {0, 0};\n        while(l < r)\n        {\n            if(l\
    \ & 1) { auto tmp = get(l++, x); res.first += tmp.first, res.second += tmp.second;\
    \ }\n            if(r & 1) { auto tmp = get(--r, x); res.first += tmp.first, res.second\
    \ += tmp.second; }\n            l >>= 1, r >>= 1;\n        }\n        return res;\n\
    \    }\n};\n"
  code: "#pragma once\n\n/*\nmerge sort tree\nmerge_sorte_tree<T = long long>(vector<T>\
    \ v)\npair<T,T> get(l, r, x) : [l, r) \u306E\u533A\u9593\u3067 x \u4EE5\u4E0B\u306E\
    \u3082\u306E\u306E\u500B\u6570\u3068\u305D\u306E\u7DCF\u548C\u3092\u6C42\u3081\
    \u308B O(log^2 N)\n*/\ntemplate <typename T = long long>\nstruct merge_sort_tree\n\
    {\n    int n;\n    vector<vector<T>> v;\n    vector<vector<T>> sum;\n\n    merge_sort_tree()\
    \ {}\n    merge_sort_tree(const vector<T>& _v)\n    {\n        int m = _v.size();\n\
    \        n = 1; while(n < m) n <<= 1;\n        v.resize(n << 1);\n        sum\
    \ = vector<vector<T>>(n << 1, vector<T>(1));\n        for(int i = 0; i < m; i++)\
    \ \n        {\n            v[i + n].push_back(_v[i]);\n            sum[i + n].push_back(_v[i]);\n\
    \        }\n        init();\n    }\n\n    void init()\n    {\n        for(int\
    \ i = n - 1; i >= 1; i--)\n        {\n            int l = i << 1, r = l | 1;\n\
    \            merge(v[l].begin(), v[l].end(),\n                  v[r].begin(),\
    \ v[r].end(),\n                  back_inserter(v[i]));\n            sum[i] = vector<T>(v[i].size()\
    \ + 1, 0);\n            rep(j, 0, v[i].size()) sum[i][j + 1] = sum[i][j] + v[i][j];\n\
    \        }\n    }\n\n    pair<T, T> get(int i, T x)\n    {\n        int j = upper_bound(v[i].begin(),\
    \ v[i].end(), x) - v[i].begin();\n        return {j, sum[i][j]};\n    }\n\n  \
    \  pair<T, T> get(int l, int r, T x)\n    {\n        l += n, r += n;\n       \
    \ pair<T, T> res = {0, 0};\n        while(l < r)\n        {\n            if(l\
    \ & 1) { auto tmp = get(l++, x); res.first += tmp.first, res.second += tmp.second;\
    \ }\n            if(r & 1) { auto tmp = get(--r, x); res.first += tmp.first, res.second\
    \ += tmp.second; }\n            l >>= 1, r >>= 1;\n        }\n        return res;\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/merge_sort_tree.hpp
  requiredBy: []
  timestamp: '2024-05-03 01:16:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/merge_sort_tree.hpp
layout: document
redirect_from:
- /library/data_structure/merge_sort_tree.hpp
- /library/data_structure/merge_sort_tree.hpp.html
title: data_structure/merge_sort_tree.hpp
---
