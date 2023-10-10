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
  bundledCode: "#line 2 \"data_structure/rational.hpp\"\n\nstruct Ra {\n    long long\
    \ n, d;\n    Ra() : n(0), d(1) { re(*this); }\n    Ra(long long x) : n(x), d(1)\
    \ { re(*this); }\n    Ra(long long x, long long y) : n(x), d(y) { if (d < 0) n\
    \ = -n, d = -d; re(*this); }\n    void re(Ra& x) { long long y = gcd(x.d, x.n);\
    \ x.n /= y, x.d /= y; }\n    bool operator<(const Ra& x) { return n * x.d < x.n*\
    \ d; }\n    bool operator<(const long long& x) { return *this < Ra(x); }\n   \
    \ bool operator>(const Ra& x) { return n * x.d > x.n * d; }\n    bool operator>(const\
    \ long long& x) { return *this > Ra(x); }\n    bool operator<=(const Ra& x) {\
    \ return !(*this > x); }\n    bool operator<=(const long long& x) { return *this\
    \ <= Ra(x); }\n    bool operator>=(const Ra& x) { return !(*this < x); }\n   \
    \ bool operator>=(const long long& x) { return *this >= Ra(x); }\n    bool operator==(const\
    \ Ra& x) { return n * x.d == x.n * d; }\n    bool operator==(const long long&\
    \ x) { return *this == Ra(x); }\n    bool operator!=(const Ra& x) { return n *\
    \ x.d != x.n * d; }\n    bool operator!=(const long long& x) { return *this !=\
    \ Ra(x); }\n    Ra& operator+=(const Ra& x) { n = n * x.d + x.n * d, d = d * x.d;\
    \ re(*this); return *this; }\n    Ra operator+(const Ra& x) const { return Ra(*this)\
    \ += x; }\n    Ra& operator-=(const Ra& x) { n = n * x.d - x.n * d, d = d * x.d;\
    \ re(*this); return *this; }\n    Ra operator-(const Ra& x) const { return Ra(*this)\
    \ -= x; }\n    Ra& operator*=(const Ra& x) { n = n * x.n, d = d * x.d; re(*this);\
    \ return *this; }\n    Ra operator*(const Ra& x) const { return Ra(*this) *= x;\
    \ }\n    Ra& operator/=(const Ra& x) { n = n * x.d, d = d * x.n; re(*this); return\
    \ *this; }\n    Ra operator/(const Ra& x) const { return Ra(*this) /= x; }\n \
    \   Ra operator-() const { return Ra() - *this; }\n};\nostream& operator<<(ostream&\
    \ o, const Ra& a) { o << a.n << \" / \" << a.d; return o; }\n"
  code: "#pragma once\n\nstruct Ra {\n    long long n, d;\n    Ra() : n(0), d(1) {\
    \ re(*this); }\n    Ra(long long x) : n(x), d(1) { re(*this); }\n    Ra(long long\
    \ x, long long y) : n(x), d(y) { if (d < 0) n = -n, d = -d; re(*this); }\n   \
    \ void re(Ra& x) { long long y = gcd(x.d, x.n); x.n /= y, x.d /= y; }\n    bool\
    \ operator<(const Ra& x) { return n * x.d < x.n* d; }\n    bool operator<(const\
    \ long long& x) { return *this < Ra(x); }\n    bool operator>(const Ra& x) { return\
    \ n * x.d > x.n * d; }\n    bool operator>(const long long& x) { return *this\
    \ > Ra(x); }\n    bool operator<=(const Ra& x) { return !(*this > x); }\n    bool\
    \ operator<=(const long long& x) { return *this <= Ra(x); }\n    bool operator>=(const\
    \ Ra& x) { return !(*this < x); }\n    bool operator>=(const long long& x) { return\
    \ *this >= Ra(x); }\n    bool operator==(const Ra& x) { return n * x.d == x.n\
    \ * d; }\n    bool operator==(const long long& x) { return *this == Ra(x); }\n\
    \    bool operator!=(const Ra& x) { return n * x.d != x.n * d; }\n    bool operator!=(const\
    \ long long& x) { return *this != Ra(x); }\n    Ra& operator+=(const Ra& x) {\
    \ n = n * x.d + x.n * d, d = d * x.d; re(*this); return *this; }\n    Ra operator+(const\
    \ Ra& x) const { return Ra(*this) += x; }\n    Ra& operator-=(const Ra& x) { n\
    \ = n * x.d - x.n * d, d = d * x.d; re(*this); return *this; }\n    Ra operator-(const\
    \ Ra& x) const { return Ra(*this) -= x; }\n    Ra& operator*=(const Ra& x) { n\
    \ = n * x.n, d = d * x.d; re(*this); return *this; }\n    Ra operator*(const Ra&\
    \ x) const { return Ra(*this) *= x; }\n    Ra& operator/=(const Ra& x) { n = n\
    \ * x.d, d = d * x.n; re(*this); return *this; }\n    Ra operator/(const Ra& x)\
    \ const { return Ra(*this) /= x; }\n    Ra operator-() const { return Ra() - *this;\
    \ }\n};\nostream& operator<<(ostream& o, const Ra& a) { o << a.n << \" / \" <<\
    \ a.d; return o; }"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/rational.hpp
  requiredBy: []
  timestamp: '2023-09-26 16:04:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/rational.hpp
layout: document
redirect_from:
- /library/data_structure/rational.hpp
- /library/data_structure/rational.hpp.html
title: data_structure/rational.hpp
---
