---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: data_structure/mint.hpp
    title: data_structure/mint.hpp
  - icon: ':warning:'
    path: fps/fps.hpp
    title: fps/fps.hpp
  - icon: ':warning:'
    path: math/convolution.hpp
    title: math/convolution.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fps/convolution_all.hpp\"\n\n#line 2 \"fps/fps.hpp\"\n\n\
    #line 2 \"data_structure/mint.hpp\"\n\n// Mod int\nusing ull = unsigned long long;\
    \ using uint = unsigned;\n#define pb push_back\nuint mod = 998244353;\n//const\
    \ uint mod = 1000000007;\nstruct mint {\n    uint x;\n    mint() : x(0) {}\n \
    \   mint(ll x) :x((x% mod + mod) % mod) {}\n    mint operator-() const { return\
    \ mint(0) - *this; }\n    mint operator~() const { return mint(1) / *this; }\n\
    \    mint& operator+=(const mint& a) { if ((x += a.x) >= mod) x -= mod; return\
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
    \ (a < b || b < 0) return 0;\n    return  facs(a) * ifacs(a - b);\n}\n//\n#line\
    \ 2 \"math/convolution.hpp\"\n\n#line 4 \"math/convolution.hpp\"\n\nint ceil_pow(int\
    \ n)\n{\n    int x = 0;\n    while((1LL << x) < (long long)(n)) x++;\n    return\
    \ x;\n}\n\nvoid NTT(vector<mint>& a)\n{\n    int n = a.size();\n    int h = ceil_pow(n);\n\
    \n    static bool first = true;\n    static mint sum_e[30];\n    if(first)\n \
    \   {\n        first = false;\n        int g = 3; // primitive root of 998244353\n\
    \        mint es[30], ies[30];\n        int cnt2 = __countr_zero(mod - 1);\n \
    \       mint e = mint(g).pow((mod - 1) >> cnt2), ie = mint(1) / e;\n        for\
    \ (int i = cnt2; i >= 2; i--) {\n            es[i - 2] = e;\n            ies[i\
    \ - 2] = ie;\n            e *= e;\n            ie *= ie;\n        }\n        mint\
    \ now = 1;\n        for (int i = 0; i <= cnt2 - 2; i++) {\n            sum_e[i]\
    \ = es[i] * now;\n            now *= ies[i];\n        }\n    }\n\n    for (int\
    \ ph = 1; ph <= h; ph++) \n    {\n        int w = 1 << (ph - 1), p = 1 << (h -\
    \ ph);\n        mint now = 1;\n        for (int s = 0; s < w; s++) {\n       \
    \     int offset = s << (h - ph + 1);\n            for (int i = 0; i < p; i++)\
    \ {\n                auto l = a[i + offset];\n                auto r = a[i + offset\
    \ + p] * now;\n                a[i + offset] = l + r;\n                a[i + offset\
    \ + p] = l - r;\n            }\n            now *= sum_e[__countr_zero(~(unsigned\
    \ int)(s))];\n        }\n    }\n}\n\nvoid NTT_inv(vector<mint>& a)\n{\n    int\
    \ n = a.size();\n    int h = ceil_pow(n);\n\n    static bool first = true;\n \
    \   static mint sum_ie[30];  \n    if (first) \n    {\n        first = false;\n\
    \        int g = 3; // primitive root of 998244353\n        mint es[30], ies[30];\
    \  // es[i]^(2^(2+i)) == 1\n        int cnt2 = __countr_zero(mod - 1);\n     \
    \   mint e = mint(g).pow((mod - 1) >> cnt2), ie = mint(1) / e;\n        for (int\
    \ i = cnt2; i >= 2; i--) {\n            es[i - 2] = e;\n            ies[i - 2]\
    \ = ie;\n            e *= e;\n            ie *= ie;\n        }\n        mint now\
    \ = 1;\n        for (int i = 0; i <= cnt2 - 2; i++) {\n            sum_ie[i] =\
    \ ies[i] * now;\n            now *= es[i];\n        }\n    }\n\n    for (int ph\
    \ = h; ph >= 1; ph--) \n    {\n        int w = 1 << (ph - 1), p = 1 << (h - ph);\n\
    \        mint inow = 1;\n        for (int s = 0; s < w; s++) {\n            int\
    \ offset = s << (h - ph + 1);\n            for (int i = 0; i < p; i++) {\n   \
    \             auto l = a[i + offset];\n                auto r = a[i + offset +\
    \ p];\n                a[i + offset] = l + r;\n                a[i + offset +\
    \ p] =\n                    (unsigned long long)(mod + l.val() - r.val()) *\n\
    \                    inow.val();\n            }\n            inow *= sum_ie[__countr_zero(~(unsigned\
    \ int)(s))];\n        }\n    }\n}\n\nvector<mint> convolution(vector<mint> a,\
    \ vector<mint> b)\n{   // mod 998244353\n    int n = a.size(), m = b.size(), len\
    \ = 1;\n    if(n == 0 || m == 0) return {};\n    if(min(n, m) <= 60)\n    {\n\
    \        if(n < m) swap(n, m), swap(a, b);\n        vector<mint> res(n + m - 1);\n\
    \        for (int i = 0; i < n; i++) {\n            for (int j = 0; j < m; j++)\
    \ {\n                res[i + j] += a[i] * b[j];\n            }\n        }\n  \
    \      return res;\n    }\n    while(len <= n + m - 1) len <<= 1;\n    a.resize(len),\
    \ b.resize(len);\n    \n    NTT(a), NTT(b);\n    vector<mint> c(len);\n    for(int\
    \ i = 0; i < len; i++) c[i] = a[i] * b[i];\n    NTT_inv(c);\n    c.resize(n +\
    \ m - 1);\n    mint in = mint(1) / len;\n    for(mint &p : c) p *= in;\n    return\
    \ c;\n}\n\nvector<mint> convolution(vector<long long>& a, vector<long long>& b)\n\
    {  \n    vector<mint> ma, mb;\n    for(int i = 0; i < a.size(); i++) ma.push_back(a[i]);\n\
    \    for(int i = 0; i < b.size(); i++) mb.push_back(b[i]);\n    return convolution(ma,\
    \ mb);\n}\n#line 5 \"fps/fps.hpp\"\n\ntemplate<class T>\nstruct FormalPowerSeries\
    \ : vector<T>\n{\n    using fps = FormalPowerSeries;\n    using vector<T>::vector;\n\
    \    using vector<T>::operator=;\n\n    fps operator-() const { fps r(*this);\
    \ for(auto& p : r) p = -p; return r; }\n    fps& operator+=(const fps& r) \n \
    \   { \n        int n = min((*this).size(), r.size());   \n        for(int i =\
    \ 0; i < n; i++) (*this)[i] += r[i];\n        return *this;\n    }\n    fps operator+(const\
    \ fps& r) const { return fps(*this) += r; }\n    fps& operator-=(const fps& r)\
    \ \n    { \n        int n = min((*this).size(), r.size());   \n        for(int\
    \ i = 0; i < n; i++) (*this)[i] -= r[i];\n        return *this;\n    }\n    fps\
    \ operator-(const fps& r) const { return fps(*this) -= r; }\n    fps& operator*=(T&\
    \ c) { for(auto& p : *this) p *= c; return *this; }\n    fps operator*(T c) {\
    \ return fps(*this) *= c; }\n    fps& operator*=(const fps& r) { *this = convolution(*this,\
    \ r); return *this; }\n    fps operator*(const fps& r) const { return fps(*this)\
    \ *= r; }\n    fps& operator<<=(const T& c) \n    {\n        int n = (*this).size();\n\
    \        (*this).insert((*this).begin(), c, 0);\n        (*this).resize(n);\n\
    \        return *this;\n    }\n    fps operator<<(const T c) const { return fps(*this)\
    \ <<= c; }\n    fps& operator>>=(const T& c)\n    {\n        int n = (*this).size();\n\
    \        (*this).erase((*this).begin(), (*this).begin() + min(n, c));\n      \
    \  (*this).resize(n);\n        return *this;\n    }\n    fps operator>>(const\
    \ T c) const { return fps(*this) >>= c; }\n};\n\nusing fps = FormalPowerSeries<mint>;\n\
    #line 4 \"fps/convolution_all.hpp\"\n\n/*\nfps \u3059\u3079\u3066\u3092 convolution\
    \ \u3059\u308B\nO(n log^2 n) n \u306F\u9805\u306E\u9577\u3055\u306E\u7DCF\u548C\
    \n*/\nfps convolution_all(vector<fps>& v)\n{\n    queue<fps> q;\n    for(auto\
    \ p : v) q.push(p);\n    while(q.size() >= 2)\n    {\n        auto l = q.front();\
    \ q.pop();\n        auto r = q.front(); q.pop();\n        q.push(l * r);\n   \
    \ }\n    return q.front();\n}\n"
  code: "#pragma once\n\n#include \"fps/fps.hpp\"\n\n/*\nfps \u3059\u3079\u3066\u3092\
    \ convolution \u3059\u308B\nO(n log^2 n) n \u306F\u9805\u306E\u9577\u3055\u306E\
    \u7DCF\u548C\n*/\nfps convolution_all(vector<fps>& v)\n{\n    queue<fps> q;\n\
    \    for(auto p : v) q.push(p);\n    while(q.size() >= 2)\n    {\n        auto\
    \ l = q.front(); q.pop();\n        auto r = q.front(); q.pop();\n        q.push(l\
    \ * r);\n    }\n    return q.front();\n}"
  dependsOn:
  - fps/fps.hpp
  - data_structure/mint.hpp
  - math/convolution.hpp
  isVerificationFile: false
  path: fps/convolution_all.hpp
  requiredBy: []
  timestamp: '2024-06-10 11:18:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/convolution_all.hpp
layout: document
redirect_from:
- /library/fps/convolution_all.hpp
- /library/fps/convolution_all.hpp.html
title: fps/convolution_all.hpp
---
