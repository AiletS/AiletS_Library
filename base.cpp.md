---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: my_template.hpp
    title: my_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"my_template.hpp\"\n#pragma GCC optimize(\"O3\")\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\nusing ll = long long; using ld = long\
    \ double;\nusing P = pair<int, int>; using Pll = pair<ll, ll>;\nusing vi = vector<int>;\
    \ using vvi = vector<vector<int>>; using vvvi = vector<vvi>;\nusing vl = vector<ll>;\
    \ using vvl = vector<vector<ll>>; using vvvl = vector<vvl>;\nusing vld = vector<ld>;\
    \ using vvld = vector<vector<vld>>; using vvvld = vector<vvld>;\nusing vp = vector<P>;\
    \ using vpll = vector<Pll>; using vvp = vector<vector<P>>;\nusing vs = vector<string>;\n\
    template <typename T> using pq = priority_queue<T, vector<T>, greater<T>>;\n#define\
    \ rep(i, s, n) for (long long i = (s); i < (long long)(n); i++)\n#define drep(i,\
    \ s, n) for (long long i = (s); i >= (long long)(n); i--)\ntemplate <typename\
    \ T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } return\
    \ false; }\ntemplate <typename T> bool chmin(T& a, const T& b) { if (a > b) {\
    \ a = b; return true; } return false; }\ntemplate <typename T = long long> T floor(T\
    \ x, T m) { return (x - ((x % m + m) % m)) / m; }\ntemplate <typename T = long\
    \ long> T ceil(T x, T m) { return floor(x + m - 1, m); }\n\ntemplate <class T>\
    \ constexpr T infty = 0;\ntemplate<> constexpr int infty<int> = 1001001001;\n\
    template<> constexpr long long infty<long long> = 9e18;\ntemplate<> constexpr\
    \ double infty<double> = infty<long long>;\ntemplate<> constexpr long double infty<long\
    \ double> = infty<long long>;\n\ntemplate<class T> istream& operator >> (istream&\
    \ i, vector<T>& v) { for(T& p : v) cin >> p; return i; }\ntemplate<class T> ostream&\
    \ operator << (ostream& o, vector<T>& v) { for(T& p : v) cout << p << \" \"; return\
    \ o; }\ntemplate<class T> istream& operator >> (istream& i, vector<vector<T>>&\
    \ v) { for(vector<T>& p : v) cin >> p; return i; }\ntemplate<class T> ostream&\
    \ operator << (ostream& o, vector<vector<T>>& v) { for(vector<T>& p : v) cout\
    \ << p << '\\n'; return o; }\ntemplate<class T> void operator -- (vector<T>& v,\
    \ int) { for(T& p : v) p--; }\ntemplate<class T> void operator ++ (vector<T>&\
    \ v, int) { for(T& p : v) p++; }\n#line 2 \"base.cpp\"\n\nvoid solve()\n{\n  \
    \  \n}\n\nint main()\n{\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    int t = 1;\n    //cin >> t;\n    while (t--) solve();\n}\n"
  code: "#include \"my_template.hpp\"\n\nvoid solve()\n{\n    \n}\n\nint main()\n\
    {\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n    int t = 1;\n\
    \    //cin >> t;\n    while (t--) solve();\n}"
  dependsOn:
  - my_template.hpp
  isVerificationFile: false
  path: base.cpp
  requiredBy: []
  timestamp: '2024-05-03 01:16:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: base.cpp
layout: document
redirect_from:
- /library/base.cpp
- /library/base.cpp.html
title: base.cpp
---
