---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  attributes:
    links: []
  bundledCode: "#line 2 \"convolution.hpp\"\ntemplate<long long MOD>\nlong long mod_pow(long\
    \ long a, long long b)\n{\n\tlong long res = 1;\n\tfor (long long p = a; b; p\
    \ *= p, p %= MOD, b >>= 1) if (b & 1) res *= p, res %= MOD; \n\treturn res;\n\
    }\n\ntemplate<long long MOD>\nlong long mod_inv(long long x)\n{\n\treturn mod_pow<MOD>(x,\
    \ MOD - 2);\n}\n\ntemplate<long long MOD>\nvector<long long> NTT(vector<long long>\
    \ &a, long long depth, vector<long long> &root)\n{\n    long long n = a.size();\n\
    \    vector<long long> res(0);\n\n    if(n == 1) return a;\n\n    vector<long\
    \ long> even(0);\n    vector<long long> odd(0);\n    for (long long i = 0; i <\
    \ n; i++)\n    {\n        if (i % 2 == 0) even.push_back(a[i]);\n        else\
    \ odd.push_back(a[i]);\n    }\n    vector<long long> d_even = NTT<MOD>(even, depth\
    \ - 1, root);\n    vector<long long> d_odd = NTT<MOD>(odd, depth - 1, root);\n\
    \n    long long r = root[depth];\n        \n    long long now = 1;\n    for (long\
    \ long i = 0; i < n; i++)\n    {\n        res.push_back((d_even[i % (n / 2)] +\
    \ (now * d_odd[i % (n / 2)]) % MOD) % MOD);\n        now = (now * r) % MOD;\n\
    \    }\n    return res;\n}\n\ntemplate<long long MOD>\nvector<long long> convolution(vector<long\
    \ long> &a, vector<long long> &b)\n{\n\tint len = a.size() + b.size() - 1;\n \
    \   int n = 1;\n    while(n <= len) n <<= 1;\n    a.resize(n), b.resize(n);\n\n\
    \    long long log_2n = 1;\n    while ((1LL << log_2n) < n) log_2n++;\n\n    vector<long\
    \ long> root(0);\n    vector<long long> invroot;\n    long long r = mod_pow<MOD>(3,\
    \ 119);\n    for(long long i = 0; i < 23; i++){\n    \troot.push_back(r); r =\
    \ (r * r) % MOD;\n    }\n    reverse(root.begin(), root.end());\n    for(long\
    \ long i = 0; i < root.size(); i++){\n    \tinvroot.push_back(mod_inv<MOD>(root[i]));\n\
    \    }\n\n\n    a = NTT<MOD>(a, log_2n - 1, root);\n    b = NTT<MOD>(b, log_2n\
    \ - 1, root);\n\n    vector<long long> c(n);\n    for (int i = 0; i < n; i++)\
    \ c[i] = (a[i] * b[i]) % MOD;\n\n    c = NTT<MOD>(c, log_2n - 1, invroot);\n\n\
    \    vector<long long> res(0);\n    for (int i = 0; i < n; i++){\n        res.push_back((c[i]\
    \ * mod_inv<MOD>((long long)n)) % MOD);\n    }\n    return res;\n}\n"
  code: "#pragma once\ntemplate<long long MOD>\nlong long mod_pow(long long a, long\
    \ long b)\n{\n\tlong long res = 1;\n\tfor (long long p = a; b; p *= p, p %= MOD,\
    \ b >>= 1) if (b & 1) res *= p, res %= MOD; \n\treturn res;\n}\n\ntemplate<long\
    \ long MOD>\nlong long mod_inv(long long x)\n{\n\treturn mod_pow<MOD>(x, MOD -\
    \ 2);\n}\n\ntemplate<long long MOD>\nvector<long long> NTT(vector<long long> &a,\
    \ long long depth, vector<long long> &root)\n{\n    long long n = a.size();\n\
    \    vector<long long> res(0);\n\n    if(n == 1) return a;\n\n    vector<long\
    \ long> even(0);\n    vector<long long> odd(0);\n    for (long long i = 0; i <\
    \ n; i++)\n    {\n        if (i % 2 == 0) even.push_back(a[i]);\n        else\
    \ odd.push_back(a[i]);\n    }\n    vector<long long> d_even = NTT<MOD>(even, depth\
    \ - 1, root);\n    vector<long long> d_odd = NTT<MOD>(odd, depth - 1, root);\n\
    \n    long long r = root[depth];\n        \n    long long now = 1;\n    for (long\
    \ long i = 0; i < n; i++)\n    {\n        res.push_back((d_even[i % (n / 2)] +\
    \ (now * d_odd[i % (n / 2)]) % MOD) % MOD);\n        now = (now * r) % MOD;\n\
    \    }\n    return res;\n}\n\ntemplate<long long MOD>\nvector<long long> convolution(vector<long\
    \ long> &a, vector<long long> &b)\n{\n\tint len = a.size() + b.size() - 1;\n \
    \   int n = 1;\n    while(n <= len) n <<= 1;\n    a.resize(n), b.resize(n);\n\n\
    \    long long log_2n = 1;\n    while ((1LL << log_2n) < n) log_2n++;\n\n    vector<long\
    \ long> root(0);\n    vector<long long> invroot;\n    long long r = mod_pow<MOD>(3,\
    \ 119);\n    for(long long i = 0; i < 23; i++){\n    \troot.push_back(r); r =\
    \ (r * r) % MOD;\n    }\n    reverse(root.begin(), root.end());\n    for(long\
    \ long i = 0; i < root.size(); i++){\n    \tinvroot.push_back(mod_inv<MOD>(root[i]));\n\
    \    }\n\n\n    a = NTT<MOD>(a, log_2n - 1, root);\n    b = NTT<MOD>(b, log_2n\
    \ - 1, root);\n\n    vector<long long> c(n);\n    for (int i = 0; i < n; i++)\
    \ c[i] = (a[i] * b[i]) % MOD;\n\n    c = NTT<MOD>(c, log_2n - 1, invroot);\n\n\
    \    vector<long long> res(0);\n    for (int i = 0; i < n; i++){\n        res.push_back((c[i]\
    \ * mod_inv<MOD>((long long)n)) % MOD);\n    }\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: convolution.hpp
  requiredBy: []
  timestamp: '2023-09-02 07:34:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convolution.hpp
layout: document
title: convolution.hpp
---
abc

$12$