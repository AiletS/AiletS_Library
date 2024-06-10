---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: fps/convolution_all.hpp
    title: fps/convolution_all.hpp
  - icon: ':warning:'
    path: fps/fps.hpp
    title: fps/fps.hpp
  - icon: ':warning:'
    path: math/convolution.hpp
    title: math/convolution.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/mint.hpp\"\n\n// Mod int\nusing ull = unsigned\
    \ long long; using uint = unsigned;\n#define pb push_back\nuint mod = 998244353;\n\
    //const uint mod = 1000000007;\nstruct mint {\n    uint x;\n    mint() : x(0)\
    \ {}\n    mint(ll x) :x((x% mod + mod) % mod) {}\n    mint operator-() const {\
    \ return mint(0) - *this; }\n    mint operator~() const { return mint(1) / *this;\
    \ }\n    mint& operator+=(const mint& a) { if ((x += a.x) >= mod) x -= mod; return\
    \ *this; }\n    mint& operator-=(const mint& a) { if ((x += mod - a.x) >= mod)\
    \ x -= mod; return *this; }\n    mint& operator*=(const mint& a) { x = (ull)x\
    \ * a.x % mod; return *this; }\n    mint& operator/=(const mint& a) { x = (ull)x\
    \ * a.pow(mod - 2).x % mod; return *this; }\n    mint operator+(const mint& a)\
    \ const { return mint(*this) += a; }\n    mint operator-(const mint& a) const\
    \ { return mint(*this) -= a; }\n    mint operator*(const mint& a) const { return\
    \ mint(*this) *= a; }\n    mint operator/(const mint& a) const { return mint(*this)\
    \ /= a; }\n    mint operator++() const { return *this + 1; }\n    mint operator--()\
    \ const { return *this - 1; }\n    mint pow(ll t) const {\n        mint res =\
    \ 1; for (mint p = x; t; p *= p, t >>= 1) if (t & 1) res *= p; return res;\n \
    \   }\n    mint ppow(ll t) const { int p = mod - 1; return pow((t % p + p) % p);\
    \ }\n    uint val() const { return x; }\n    bool operator<(const mint& a) const\
    \ { return x < a.x; }\n    bool operator==(const mint& a) const { return x ==\
    \ a.x; }\n    bool operator!=(const mint& a) const { return x != a.x; }\n};\n\
    mint ex(mint x, ll t) { return x.pow(t); }\nistream& operator>>(istream& i, mint&\
    \ a) { i >> a.x; return i; }\n//*\nostream& operator<<(ostream& o, const mint&\
    \ a) { o << a.x; return o; }\nusing vm = vector<mint>;\nusing vvm = vector<vm>;\n\
    using vvvm = vector<vvm>;\nstruct modinv {\n    int n; vm d;\n    modinv() : n(2),\
    \ d({ 0,1 }) {}\n    mint operator()(int i) { while (n <= i) d.pb(-d[mod % n]\
    \ * (mod / n)), ++n; return d[i]; }\n    mint operator[](int i) const { return\
    \ d[i]; }\n} invs;\nstruct modfact {\n    int n; vm d;\n    modfact() : n(2),\
    \ d({ 1,1 }) {}\n    mint operator()(int i) { while (n <= i) d.pb(d.back() * n),\
    \ ++n; return d[i]; }\n    mint operator[](int i) const { return d[i]; }\n} facs;\n\
    struct modfactinv {\n    int n; vm d;\n    modfactinv() : n(2), d({ 1,1 }) {}\n\
    \    mint operator()(int i) { while (n <= i) d.pb(d.back() * invs(n)), ++n; return\
    \ d[i]; }\n    mint operator[](int i) const { return d[i]; }\n} ifacs;\nmint comb(int\
    \ a, int b) {\n    if (a < b || b < 0) return 0;\n    return facs(a) * ifacs(b)\
    \ * ifacs(a - b);\n}\nmint comb2(int a, int b) { // if a is big and k is small\
    \ : O(b)\n    if (a < b || b < 0) return 0;\n    mint res = ifacs(b);\n    for\
    \ (int i = 0; i < b; i++) res *= (a - i);\n    return res;\n}\nmint hcomb(int\
    \ a, int b) {\n    return comb(a + b - 1, a - 1);\n}\nmint hcomb2(int a, int b)\
    \ {\n    return comb2(a + b - 1, a - 1);\n}\nmint perm(int a, int b) {\n    if\
    \ (a < b || b < 0) return 0;\n    return  facs(a) * ifacs(a - b);\n}\n//\n"
  code: "#pragma once\n\n// Mod int\nusing ull = unsigned long long; using uint =\
    \ unsigned;\n#define pb push_back\nuint mod = 998244353;\n//const uint mod = 1000000007;\n\
    struct mint {\n    uint x;\n    mint() : x(0) {}\n    mint(ll x) :x((x% mod +\
    \ mod) % mod) {}\n    mint operator-() const { return mint(0) - *this; }\n   \
    \ mint operator~() const { return mint(1) / *this; }\n    mint& operator+=(const\
    \ mint& a) { if ((x += a.x) >= mod) x -= mod; return *this; }\n    mint& operator-=(const\
    \ mint& a) { if ((x += mod - a.x) >= mod) x -= mod; return *this; }\n    mint&\
    \ operator*=(const mint& a) { x = (ull)x * a.x % mod; return *this; }\n    mint&\
    \ operator/=(const mint& a) { x = (ull)x * a.pow(mod - 2).x % mod; return *this;\
    \ }\n    mint operator+(const mint& a) const { return mint(*this) += a; }\n  \
    \  mint operator-(const mint& a) const { return mint(*this) -= a; }\n    mint\
    \ operator*(const mint& a) const { return mint(*this) *= a; }\n    mint operator/(const\
    \ mint& a) const { return mint(*this) /= a; }\n    mint operator++() const { return\
    \ *this + 1; }\n    mint operator--() const { return *this - 1; }\n    mint pow(ll\
    \ t) const {\n        mint res = 1; for (mint p = x; t; p *= p, t >>= 1) if (t\
    \ & 1) res *= p; return res;\n    }\n    mint ppow(ll t) const { int p = mod -\
    \ 1; return pow((t % p + p) % p); }\n    uint val() const { return x; }\n    bool\
    \ operator<(const mint& a) const { return x < a.x; }\n    bool operator==(const\
    \ mint& a) const { return x == a.x; }\n    bool operator!=(const mint& a) const\
    \ { return x != a.x; }\n};\nmint ex(mint x, ll t) { return x.pow(t); }\nistream&\
    \ operator>>(istream& i, mint& a) { i >> a.x; return i; }\n//*\nostream& operator<<(ostream&\
    \ o, const mint& a) { o << a.x; return o; }\nusing vm = vector<mint>;\nusing vvm\
    \ = vector<vm>;\nusing vvvm = vector<vvm>;\nstruct modinv {\n    int n; vm d;\n\
    \    modinv() : n(2), d({ 0,1 }) {}\n    mint operator()(int i) { while (n <=\
    \ i) d.pb(-d[mod % n] * (mod / n)), ++n; return d[i]; }\n    mint operator[](int\
    \ i) const { return d[i]; }\n} invs;\nstruct modfact {\n    int n; vm d;\n   \
    \ modfact() : n(2), d({ 1,1 }) {}\n    mint operator()(int i) { while (n <= i)\
    \ d.pb(d.back() * n), ++n; return d[i]; }\n    mint operator[](int i) const {\
    \ return d[i]; }\n} facs;\nstruct modfactinv {\n    int n; vm d;\n    modfactinv()\
    \ : n(2), d({ 1,1 }) {}\n    mint operator()(int i) { while (n <= i) d.pb(d.back()\
    \ * invs(n)), ++n; return d[i]; }\n    mint operator[](int i) const { return d[i];\
    \ }\n} ifacs;\nmint comb(int a, int b) {\n    if (a < b || b < 0) return 0;\n\
    \    return facs(a) * ifacs(b) * ifacs(a - b);\n}\nmint comb2(int a, int b) {\
    \ // if a is big and k is small : O(b)\n    if (a < b || b < 0) return 0;\n  \
    \  mint res = ifacs(b);\n    for (int i = 0; i < b; i++) res *= (a - i);\n   \
    \ return res;\n}\nmint hcomb(int a, int b) {\n    return comb(a + b - 1, a - 1);\n\
    }\nmint hcomb2(int a, int b) {\n    return comb2(a + b - 1, a - 1);\n}\nmint perm(int\
    \ a, int b) {\n    if (a < b || b < 0) return 0;\n    return  facs(a) * ifacs(a\
    \ - b);\n}\n//\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/mint.hpp
  requiredBy:
  - fps/convolution_all.hpp
  - fps/fps.hpp
  - math/convolution.hpp
  timestamp: '2024-05-03 01:16:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/mint.hpp
layout: document
redirect_from:
- /library/data_structure/mint.hpp
- /library/data_structure/mint.hpp.html
title: data_structure/mint.hpp
---
