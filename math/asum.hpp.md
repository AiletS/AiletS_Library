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
  bundledCode: "#line 2 \"math/asum.hpp\"\n\n// arithmetic progression sum\n// first\
    \ : a, difference : d, length : n\ntemplate <typename T>\nT asum(T first, T diff,\
    \ T len)\n{\n    return first * len + (len - 1) * len / 2 * diff;\n}\n"
  code: "#pragma once\n\n// arithmetic progression sum\n// first : a, difference :\
    \ d, length : n\ntemplate <typename T>\nT asum(T first, T diff, T len)\n{\n  \
    \  return first * len + (len - 1) * len / 2 * diff;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/asum.hpp
  requiredBy: []
  timestamp: '2024-05-03 01:19:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/asum.hpp
layout: document
redirect_from:
- /library/math/asum.hpp
- /library/math/asum.hpp.html
title: math/asum.hpp
---
