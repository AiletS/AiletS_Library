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
  bundledCode: "#line 2 \"monoid/monoid_max.hpp\"\n\ntemplate <typename _type>\nstruct\
    \ Monoid_Max\n{\n    using TYPE = _type;\n    static TYPE op(TYPE a, TYPE b) {\
    \ return max(a, b); }\n    static TYPE e() { return -numeric_limits<TYPE>::max();\
    \ }\n};\n"
  code: "#pragma once\n\ntemplate <typename _type>\nstruct Monoid_Max\n{\n    using\
    \ TYPE = _type;\n    static TYPE op(TYPE a, TYPE b) { return max(a, b); }\n  \
    \  static TYPE e() { return -numeric_limits<TYPE>::max(); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: monoid/monoid_max.hpp
  requiredBy: []
  timestamp: '2023-10-01 20:48:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: monoid/monoid_max.hpp
layout: document
redirect_from:
- /library/monoid/monoid_max.hpp
- /library/monoid/monoid_max.hpp.html
title: monoid/monoid_max.hpp
---
