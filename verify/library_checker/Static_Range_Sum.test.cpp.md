---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/FenwickTree.hpp
    title: data_structure/FenwickTree.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"verify/library_checker/Static_Range_Sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#line 2 \"my_template.hpp\"\
    \n#pragma GCC optimize(\"O3\")\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long; using ld = long double;\nusing P = pair<int, int>; using\
    \ Pll = pair<ll, ll>;\nusing vi = vector<int>; using vvi = vector<vector<int>>;\
    \ using vvvi = vector<vvi>;\nusing vl = vector<ll>; using vvl = vector<vector<ll>>;\
    \ using vvvl = vector<vvl>;\nusing vld = vector<ld>; using vvld = vector<vector<vld>>;\
    \ using vvvld = vector<vvld>;\nusing vp = vector<P>; using vpll = vector<Pll>;\
    \ using vvp = vector<vector<P>>;\nusing vs = vector<string>;\ntemplate <typename\
    \ T> using pq = priority_queue<T, vector<T>, greater<T>>;\n#define rep(i, s, n)\
    \ for (long long i = (s); i < (long long)(n); i++)\n#define drep(i, s, n) for\
    \ (long long i = (s); i >= (long long)(n); i--)\ntemplate <typename T> bool chmax(T&\
    \ a, const T& b) { if (a < b) { a = b; return true; } return false; }\ntemplate\
    \ <typename T> bool chmin(T& a, const T& b) { if (a > b) { a = b; return true;\
    \ } return false; }\ntemplate <typename T = long long> T floor(T x, T m) { return\
    \ (x - ((x % m + m) % m)) / m; }\ntemplate <typename T = long long> T ceil(T x,\
    \ T m) { return floor(x + m - 1, m); }\n\ntemplate <class T> constexpr T infty\
    \ = 0;\ntemplate<> constexpr int infty<int> = 1001001001;\ntemplate<> constexpr\
    \ long long infty<long long> = 9e18;\ntemplate<> constexpr double infty<double>\
    \ = infty<long long>;\ntemplate<> constexpr long double infty<long double> = infty<long\
    \ long>;\n\ntemplate<class T> istream& operator >> (istream& i, vector<T>& v)\
    \ { for(T& p : v) cin >> p; return i; }\ntemplate<class T> ostream& operator <<\
    \ (ostream& o, vector<T>& v) { for(T& p : v) cout << p << \" \"; return o; }\n\
    template<class T> istream& operator >> (istream& i, vector<vector<T>>& v) { for(vector<T>&\
    \ p : v) cin >> p; return i; }\ntemplate<class T> ostream& operator << (ostream&\
    \ o, vector<vector<T>>& v) { for(vector<T>& p : v) cout << p << '\\n'; return\
    \ o; }\ntemplate<class T> void operator -- (vector<T>& v, int) { for(T& p : v)\
    \ p--; }\ntemplate<class T> void operator ++ (vector<T>& v, int) { for(T& p :\
    \ v) p++; }\n#line 2 \"data_structure/FenwickTree.hpp\"\n\n/*\nFenwickTree (BIT)\n\
    FenwickTree<T = long long>(), FenwickTree<T = long long>(int _n) \u30B5\u30A4\u30BA\
    \ n \u3067\u751F\u6210\nadd(int p, T x) p \u306B x \u3092\u8DB3\u3059\nget(int\
    \ l, int r) [l, r) \u306E\u548C\u3092\u53D6\u5F97\n*/\ntemplate <class T = long\
    \ long>\nclass FenwickTree\n{\n  public:\n\tFenwickTree() : n(0) {}\n\tFenwickTree(int\
    \ _n) : n(_n), data(_n, 0) {}\n\tFenwickTree(vector<T>& v) : n(v.size()), data(n,\
    \ 0)\n\t{\n\t\tfor(int i = 0; i < n; i++) add(i, v[i]);\n\t}\n\n\tvoid add(int\
    \ p, T x) // add x at p\n\t{\n\t\tassert(0 <= p && p < n);\n\t\tfor (++p; p <=\
    \ n; p += (p & -p)) data[p - 1] += x;\n\t}\n\n\tT get(int l, int r) // sum [l,\
    \ r)\n\t{\n\t\tassert(0 <= l && l <= r && r <= n);\n\t\treturn sum(r) - sum(l);\n\
    \t}\n\n  private:\n\tint n;\n\tvector<T> data;\n\n\tT sum(int x)\n\t{\n\t\tT s\
    \ = 0;\n\t\tfor (; x > 0; x -= (x & -x)) s += data[x - 1];\n\t\treturn s;\n\t\
    }\n};\n#line 4 \"verify/library_checker/Static_Range_Sum.test.cpp\"\n\nvoid solve()\n\
    {\n    ll n, q; cin >> n >> q;\n    vl a(n); cin >> a;\n    FenwickTree b(a);\n\
    \    while(q--)\n    {\n        ll l, r; cin >> l >> r;\n        cout << b.get(l,\
    \ r) << '\\n';\n    }\n}\n\nint main()\n{\n    ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    int t = 1;\n    //cin >> t;\n    while (t--)\
    \ solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ \"my_template.hpp\"\n#include \"data_structure/FenwickTree.hpp\"\n\nvoid solve()\n\
    {\n    ll n, q; cin >> n >> q;\n    vl a(n); cin >> a;\n    FenwickTree b(a);\n\
    \    while(q--)\n    {\n        ll l, r; cin >> l >> r;\n        cout << b.get(l,\
    \ r) << '\\n';\n    }\n}\n\nint main()\n{\n    ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    int t = 1;\n    //cin >> t;\n    while (t--)\
    \ solve();\n}"
  dependsOn:
  - my_template.hpp
  - data_structure/FenwickTree.hpp
  isVerificationFile: true
  path: verify/library_checker/Static_Range_Sum.test.cpp
  requiredBy: []
  timestamp: '2024-05-03 18:59:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/Static_Range_Sum.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/Static_Range_Sum.test.cpp
- /verify/verify/library_checker/Static_Range_Sum.test.cpp.html
title: verify/library_checker/Static_Range_Sum.test.cpp
---
