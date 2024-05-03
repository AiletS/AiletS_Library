---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/Static_RMQ.test.cpp
    title: verify/library_checker/Static_RMQ.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"monoid/monoid_min.hpp\"\n\ntemplate <class _S>\nstruct Monoid_min\n\
    {\n    using TYPE = _S;\n    static TYPE op(TYPE a, TYPE b)\n    {\n        return\
    \ min(a, b);\n    };\n    static TYPE e() \n    {\n        return infty<TYPE>;\n\
    \    };\n};\n"
  code: "#pragma once\n\ntemplate <class _S>\nstruct Monoid_min\n{\n    using TYPE\
    \ = _S;\n    static TYPE op(TYPE a, TYPE b)\n    {\n        return min(a, b);\n\
    \    };\n    static TYPE e() \n    {\n        return infty<TYPE>;\n    };\n};"
  dependsOn: []
  isVerificationFile: false
  path: monoid/monoid_min.hpp
  requiredBy: []
  timestamp: '2024-05-03 16:42:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/Static_RMQ.test.cpp
documentation_of: monoid/monoid_min.hpp
layout: document
redirect_from:
- /library/monoid/monoid_min.hpp
- /library/monoid/monoid_min.hpp.html
title: monoid/monoid_min.hpp
---
