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
  bundledCode: "#line 2 \"math/mex.hpp\"\n\ntemplate<typename T>\nint mex(vector<T>\
    \ &v)\n{\n    int n = v.size();\n    vector<int> check(n + 1, 0);\n    for(auto\
    \ p : v) if(p < check.size()) check[p] |= 1;\n    for(int i = 0; i < n + 1; i++)\
    \ if(check[i] == 0) return i;\n}\n"
  code: "#pragma once\n\ntemplate<typename T>\nint mex(vector<T> &v)\n{\n    int n\
    \ = v.size();\n    vector<int> check(n + 1, 0);\n    for(auto p : v) if(p < check.size())\
    \ check[p] |= 1;\n    for(int i = 0; i < n + 1; i++) if(check[i] == 0) return\
    \ i;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/mex.hpp
  requiredBy: []
  timestamp: '2024-05-03 01:19:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/mex.hpp
layout: document
redirect_from:
- /library/math/mex.hpp
- /library/math/mex.hpp.html
title: math/mex.hpp
---
