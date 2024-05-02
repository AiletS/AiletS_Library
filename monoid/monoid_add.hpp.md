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
  bundledCode: "#line 2 \"monoid/monoid_add.hpp\"\n\ntemplate <class _S>\nstruct Monoid_Add\n\
    {\n    using TYPE = _S;\n    static TYPE op(TYPE a, TYPE b)\n    {\n        return\
    \ a + b;\n    };\n    static TYPE e() \n    {\n        return 0;\n    };\n};\n"
  code: "#pragma once\n\ntemplate <class _S>\nstruct Monoid_Add\n{\n    using TYPE\
    \ = _S;\n    static TYPE op(TYPE a, TYPE b)\n    {\n        return a + b;\n  \
    \  };\n    static TYPE e() \n    {\n        return 0;\n    };\n};"
  dependsOn: []
  isVerificationFile: false
  path: monoid/monoid_add.hpp
  requiredBy: []
  timestamp: '2024-05-03 01:16:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: monoid/monoid_add.hpp
layout: document
redirect_from:
- /library/monoid/monoid_add.hpp
- /library/monoid/monoid_add.hpp.html
title: monoid/monoid_add.hpp
---
