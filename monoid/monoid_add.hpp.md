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
  bundledCode: "#line 2 \"monoid/monoid_add.hpp\"\n\ntemplate <typename _type>\nstruct\
    \ Monoid_Add\n{\n    using TYPE = _type;\n    static TYPE op(TYPE a, TYPE b) {\
    \ return a + b; }\n    static TYPE e() { return 0; }\n};\n"
  code: "#pragma once\n\ntemplate <typename _type>\nstruct Monoid_Add\n{\n    using\
    \ TYPE = _type;\n    static TYPE op(TYPE a, TYPE b) { return a + b; }\n    static\
    \ TYPE e() { return 0; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: monoid/monoid_add.hpp
  requiredBy: []
  timestamp: '2023-10-01 20:48:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: monoid/monoid_add.hpp
layout: document
redirect_from:
- /library/monoid/monoid_add.hpp
- /library/monoid/monoid_add.hpp.html
title: monoid/monoid_add.hpp
---
