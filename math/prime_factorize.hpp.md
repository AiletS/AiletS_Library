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
  bundledCode: "#line 2 \"math/prime_factorize.hpp\"\n\nmap<long long, long long>\
    \ prime_factorize(long long n)\n{\n    map<long long, long long> mp;\n    for(long\
    \ long i = 2; i * i <= n; i++) while(n % i == 0) mp[i]++, n /= i;\n    if(n !=\
    \ 1) mp[n]++;\n    return mp;\n}\n"
  code: "#pragma once\n\nmap<long long, long long> prime_factorize(long long n)\n\
    {\n    map<long long, long long> mp;\n    for(long long i = 2; i * i <= n; i++)\
    \ while(n % i == 0) mp[i]++, n /= i;\n    if(n != 1) mp[n]++;\n    return mp;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: math/prime_factorize.hpp
  requiredBy: []
  timestamp: '2024-05-03 01:19:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/prime_factorize.hpp
layout: document
redirect_from:
- /library/math/prime_factorize.hpp
- /library/math/prime_factorize.hpp.html
title: math/prime_factorize.hpp
---
