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
  bundledCode: "#line 2 \"math/Eratos.hpp\"\n\n/*\nEratos(long long n) // O(n log\
    \ log n)\nget_nth_prime(long long id) : 1-index, O(1)\nfactorize : not sorted\
    \ O(log n)\ndivisor : not sorted O(log n)\nfast zeta, fast mobius\n*/\nstruct\
    \ Eratos\n{\n    vector<long long> prime;\n    vector<long long> nth_prime;\n\
    \    vector<long long> minfactor;\n    vector<long long> mobius;\n\n    Eratos(long\
    \ long n)\n    {   // O(n log log n)\n        prime = vector<long long>(n + 1,\
    \ 1); prime[1] = 0;\n        minfactor = vector<long long>(n + 1, -1); minfactor[1]\
    \ = 1;\n        mobius = vector<long long>(n + 1, 1);\n\n        for (long long\
    \ i = 2; i <= n; i++)\n        {\n            if (!prime[i]) continue;\n     \
    \       nth_prime.push_back(i);\n            minfactor[i] = i;\n            for\
    \ (long long j = i * 2; j <= n; j += i)\n            {\n                prime[j]\
    \ = 0;\n                if (minfactor[j] == -1) minfactor[j] = i;\n          \
    \      (j / i) % i == 0 ? mobius[j] = 0 : mobius[j] = -mobius[j];\n          \
    \  }\n        }\n    }\n\n    long long get_nth_prime(long long id) \n    { \n\
    \        assert(id >= 0 && id < nth_prime.size());\n        return nth_prime[id\
    \ - 1]; \n    }\n\n    vector<pair<long long, long long>> factorize(long long\
    \ n)\n    {   // not sorted, O(log n)\n        vector<pair<long long, long long>>\
    \ res;\n        while (n > 1)\n        {\n            long long p = minfactor[n];\n\
    \            long long q = 0;\n            while (minfactor[n] == p) n /= p, q++;\n\
    \            res.emplace_back(p, q);\n        }\n        return res;\n    }\n\n\
    \    vector<long long> divisor(long long n)\n    {   // not sorted\n        vector<long\
    \ long> res = { 1 };\n        vector<pair<long long, long long>> pf = factorize(n);\n\
    \        for (auto [p, q] : pf)\n        {\n            int x = (int)res.size();\n\
    \            for (int i = 0; i < x; i++)\n            {\n                long\
    \ long y = 1;\n                for (int j = 0; j < q; j++) y *= p, res.push_back(res[i]\
    \ * y);\n            }\n        }\n        return res;\n    }\n\n    template<class\
    \ T>\n    void fast_zeta(vector<T>& v)\n    {   // F(n) = sigma_(n|i) f(i)\n \
    \       int n = v.size() - 1;\n        for (int i = 2; i <= n; i++)\n        {\n\
    \            if (!prime[i]) continue;\n            for (int j = n / i; j >= 1;\
    \ j--) v[j] += v[j * i];\n        }\n    }\n\n    template<class T>\n    void\
    \ fast_mobius(vector<T>& v)\n    {   // f(n) = sigma_(n|i) \u03BC(i/n)F(i)\n \
    \       int n = v.size() - 1;\n        for (int i = 2; i <= n; i++)\n        {\n\
    \            if (!prime[i]) continue;\n            for (int j = 1; j * i <= n;\
    \ j++) v[j] -= v[j * i];\n        }\n    }\n};\n"
  code: "#pragma once\n\n/*\nEratos(long long n) // O(n log log n)\nget_nth_prime(long\
    \ long id) : 1-index, O(1)\nfactorize : not sorted O(log n)\ndivisor : not sorted\
    \ O(log n)\nfast zeta, fast mobius\n*/\nstruct Eratos\n{\n    vector<long long>\
    \ prime;\n    vector<long long> nth_prime;\n    vector<long long> minfactor;\n\
    \    vector<long long> mobius;\n\n    Eratos(long long n)\n    {   // O(n log\
    \ log n)\n        prime = vector<long long>(n + 1, 1); prime[1] = 0;\n       \
    \ minfactor = vector<long long>(n + 1, -1); minfactor[1] = 1;\n        mobius\
    \ = vector<long long>(n + 1, 1);\n\n        for (long long i = 2; i <= n; i++)\n\
    \        {\n            if (!prime[i]) continue;\n            nth_prime.push_back(i);\n\
    \            minfactor[i] = i;\n            for (long long j = i * 2; j <= n;\
    \ j += i)\n            {\n                prime[j] = 0;\n                if (minfactor[j]\
    \ == -1) minfactor[j] = i;\n                (j / i) % i == 0 ? mobius[j] = 0 :\
    \ mobius[j] = -mobius[j];\n            }\n        }\n    }\n\n    long long get_nth_prime(long\
    \ long id) \n    { \n        assert(id >= 0 && id < nth_prime.size());\n     \
    \   return nth_prime[id - 1]; \n    }\n\n    vector<pair<long long, long long>>\
    \ factorize(long long n)\n    {   // not sorted, O(log n)\n        vector<pair<long\
    \ long, long long>> res;\n        while (n > 1)\n        {\n            long long\
    \ p = minfactor[n];\n            long long q = 0;\n            while (minfactor[n]\
    \ == p) n /= p, q++;\n            res.emplace_back(p, q);\n        }\n       \
    \ return res;\n    }\n\n    vector<long long> divisor(long long n)\n    {   //\
    \ not sorted\n        vector<long long> res = { 1 };\n        vector<pair<long\
    \ long, long long>> pf = factorize(n);\n        for (auto [p, q] : pf)\n     \
    \   {\n            int x = (int)res.size();\n            for (int i = 0; i < x;\
    \ i++)\n            {\n                long long y = 1;\n                for (int\
    \ j = 0; j < q; j++) y *= p, res.push_back(res[i] * y);\n            }\n     \
    \   }\n        return res;\n    }\n\n    template<class T>\n    void fast_zeta(vector<T>&\
    \ v)\n    {   // F(n) = sigma_(n|i) f(i)\n        int n = v.size() - 1;\n    \
    \    for (int i = 2; i <= n; i++)\n        {\n            if (!prime[i]) continue;\n\
    \            for (int j = n / i; j >= 1; j--) v[j] += v[j * i];\n        }\n \
    \   }\n\n    template<class T>\n    void fast_mobius(vector<T>& v)\n    {   //\
    \ f(n) = sigma_(n|i) \u03BC(i/n)F(i)\n        int n = v.size() - 1;\n        for\
    \ (int i = 2; i <= n; i++)\n        {\n            if (!prime[i]) continue;\n\
    \            for (int j = 1; j * i <= n; j++) v[j] -= v[j * i];\n        }\n \
    \   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/Eratos.hpp
  requiredBy: []
  timestamp: '2024-05-09 13:07:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/Eratos.hpp
layout: document
redirect_from:
- /library/math/Eratos.hpp
- /library/math/Eratos.hpp.html
title: math/Eratos.hpp
---
