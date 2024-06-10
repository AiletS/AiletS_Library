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
  bundledCode: "#line 2 \"monoid/monoid_max.hpp\"\n\ntemplate <class _S>\nstruct monoid_max\n\
    {\n    using TYPE = _S;\n    static TYPE op(TYPE a, TYPE b)\n    {\n        return\
    \ max(a, b);\n    };\n    static TYPE e() \n    {\n        return -infty<TYPE>;\n\
    \    };\n};\n"
  code: "#pragma once\n\ntemplate <class _S>\nstruct monoid_max\n{\n    using TYPE\
    \ = _S;\n    static TYPE op(TYPE a, TYPE b)\n    {\n        return max(a, b);\n\
    \    };\n    static TYPE e() \n    {\n        return -infty<TYPE>;\n    };\n};"
  dependsOn: []
  isVerificationFile: false
  path: monoid/monoid_max.hpp
  requiredBy: []
  timestamp: '2024-06-10 11:18:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: monoid/monoid_max.hpp
layout: document
redirect_from:
- /library/monoid/monoid_max.hpp
- /library/monoid/monoid_max.hpp.html
title: monoid/monoid_max.hpp
---
