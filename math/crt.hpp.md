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
  bundledCode: "#line 2 \"math/crt.hpp\"\n\nlong long extgcd(long long a, long long\
    \ b, long long& x, long long& y)\n{\n\tlong long d = a;\n\tif (b != 0)\n\t{\n\t\
    \td = extgcd(b, a % b, y, x);\n\t\ty -= (a / b) * x;\n\t}\n\telse { x = 1; y =\
    \ 0; return a; }\n\n\treturn d;\n}\n// ax + by = gcd(a, b), return gcd(a, b),\
    \ get x and y\n\npair<long long, long long> crt(const vector<long long> b, const\
    \ vector<long long> m)\n{\n\tlong long r = 0, M = 1;\n\tfor (int i = 0; i < b.size();\
    \ i++)\n\t{\n\t\tlong long p, q;\n\t\tlong long d = extgcd(M, m[i], p, q);\n\t\
    \tif ((b[i] - r) % d != 0) return { 0, -1 };\n\t\tlong long tmp = (b[i] - r) /\
    \ d * p % (m[i] / d);\n\t\tr += M * tmp;\n\t\tM *= m[i] / d;\n\t}\n\n\tr = (r\
    \ % M + M) % M; // if r < 0\n\treturn { r, M };\n}\n// x = b[i] mod m[i], get\
    \ x = r mod M {r, M}\n// if there is no solution return {0, -1}\n"
  code: "#pragma once\n\nlong long extgcd(long long a, long long b, long long& x,\
    \ long long& y)\n{\n\tlong long d = a;\n\tif (b != 0)\n\t{\n\t\td = extgcd(b,\
    \ a % b, y, x);\n\t\ty -= (a / b) * x;\n\t}\n\telse { x = 1; y = 0; return a;\
    \ }\n\n\treturn d;\n}\n// ax + by = gcd(a, b), return gcd(a, b), get x and y\n\
    \npair<long long, long long> crt(const vector<long long> b, const vector<long\
    \ long> m)\n{\n\tlong long r = 0, M = 1;\n\tfor (int i = 0; i < b.size(); i++)\n\
    \t{\n\t\tlong long p, q;\n\t\tlong long d = extgcd(M, m[i], p, q);\n\t\tif ((b[i]\
    \ - r) % d != 0) return { 0, -1 };\n\t\tlong long tmp = (b[i] - r) / d * p % (m[i]\
    \ / d);\n\t\tr += M * tmp;\n\t\tM *= m[i] / d;\n\t}\n\n\tr = (r % M + M) % M;\
    \ // if r < 0\n\treturn { r, M };\n}\n// x = b[i] mod m[i], get x = r mod M {r,\
    \ M}\n// if there is no solution return {0, -1}"
  dependsOn: []
  isVerificationFile: false
  path: math/crt.hpp
  requiredBy: []
  timestamp: '2024-05-03 01:19:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/crt.hpp
layout: document
redirect_from:
- /library/math/crt.hpp
- /library/math/crt.hpp.html
title: math/crt.hpp
---
