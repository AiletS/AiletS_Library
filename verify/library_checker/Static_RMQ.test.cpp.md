---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/segtree.hpp
    title: data_structure/segtree.hpp
  - icon: ':heavy_check_mark:'
    path: monoid/monoid_min.hpp
    title: monoid/monoid_min.hpp
  - icon: ':heavy_check_mark:'
    path: my_template.hpp
    title: my_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"verify/library_checker/Static_RMQ.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/staticrmq\"\n#line 2 \"my_template.hpp\"\n\
    #pragma GCC optimize(\"O3\")\n#include <bits/stdc++.h>\nusing namespace std;\n\
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
    \ v) p++; }\n#line 2 \"data_structure/segtree.hpp\"\n\n/*\nMonoid\u304C\u5FC5\u8981\
    \nsegtree(), segtree(int k), segtree(vector<Monoid::TYPE> v)\n1,2\u756A\u76EE\u306F\
    \ operator[i]\u3067\u8FFD\u52A0\u3057\u3066 init()\u304C\u5FC5\u8981\nvoid set(int\
    \ i, T x) [i] \u3092 x \u306B\u8A2D\u5B9A\nvoid add(int i, T x) [i] \u306B x \u3092\
    \u8DB3\u3059(Monoid \u306E op \u3092\u9069\u7528\u3059\u308B)\nT get(int l, int\
    \ r) [l, r) \u306E\u6F14\u7B97\u7D50\u679C\u3092\u5F97\u308B\n*/\ntemplate <class\
    \ Monoid>\nstruct segtree\n{\n  private:\n\tusing T = typename Monoid::TYPE;\n\
    \tint n;\n\tvector<T> v;\n\t\n\tvoid upd(int i) { v[i] = Monoid::op(v[i << 1],\
    \ v[i << 1 | 1]); }\n\n  public:\n\tsegtree() : segtree(vector<T>(0)){}\n\tsegtree(int\
    \ k) : segtree(vector<T>(k, Monoid::e())) {}\n\tsegtree(const vector<T>& _v)\n\
    \t{\n\t\tint k = _v.size();\n\t\tn = 1; while(n < k) n <<= 1;\n\t\tv = vector<T>(n\
    \ << 1, Monoid::e());\n\t\tfor(int i = 0; i < k; i++) v[i + n] = _v[i];\n\t\t\
    init();\n\t}\n\n\tT& operator[](int i) { return v[i + n]; }\n\n\tvoid init() {\
    \ for (int i = n - 1; i; i--) upd(i); }\n\n\tvoid set(int i, T x) { for (i +=\
    \ n, v[i] = x, i >>= 1; i; i >>= 1) upd(i); }\n\n\tvoid add(int i, T x) { for\
    \ (i += n, v[i] += x, i >>= 1; i; i >>= 1) upd(i); }\n\n\tT get(int l, int r)\
    \ // [l, r)\n\t{\n\t\tT ls = Monoid::e(), rs = Monoid::e();\n\t\tl += n; r +=\
    \ n;\n\n\t\twhile (l < r) {\n\t\t\tif (l & 1) ls = Monoid::op(ls, v[l++]);\n\t\
    \t\tif (r & 1) rs = Monoid::op(v[--r], rs);\n\t\t\tl >>= 1; r >>= 1;\n\t\t}\n\t\
    \treturn Monoid::op(ls, rs);\n\t}\n};\n#line 2 \"monoid/monoid_min.hpp\"\n\ntemplate\
    \ <class _S>\nstruct Monoid_min\n{\n    using TYPE = _S;\n    static TYPE op(TYPE\
    \ a, TYPE b)\n    {\n        return min(a, b);\n    };\n    static TYPE e() \n\
    \    {\n        return infty<TYPE>;\n    };\n};\n#line 5 \"verify/library_checker/Static_RMQ.test.cpp\"\
    \n\nvoid solve()\n{\n    int n, q; cin >> n >> q;\n    vi a(n); cin >> a;\n  \
    \  segtree<Monoid_min<int>> seg(a);\n    while(q--)\n    {\n        int l, r;\
    \ cin >> l >> r;\n        cout << seg.get(l, r) << '\\n';\n    }\n}\n\nint main()\n\
    {\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n    int t = 1;\n\
    \    //cin >> t;\n    while (t--) solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include \"\
    my_template.hpp\"\n#include \"data_structure/segtree.hpp\"\n#include \"monoid/monoid_min.hpp\"\
    \n\nvoid solve()\n{\n    int n, q; cin >> n >> q;\n    vi a(n); cin >> a;\n  \
    \  segtree<Monoid_min<int>> seg(a);\n    while(q--)\n    {\n        int l, r;\
    \ cin >> l >> r;\n        cout << seg.get(l, r) << '\\n';\n    }\n}\n\nint main()\n\
    {\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n    int t = 1;\n\
    \    //cin >> t;\n    while (t--) solve();\n}"
  dependsOn:
  - my_template.hpp
  - data_structure/segtree.hpp
  - monoid/monoid_min.hpp
  isVerificationFile: true
  path: verify/library_checker/Static_RMQ.test.cpp
  requiredBy: []
  timestamp: '2024-05-03 18:59:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/Static_RMQ.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/Static_RMQ.test.cpp
- /verify/verify/library_checker/Static_RMQ.test.cpp.html
title: verify/library_checker/Static_RMQ.test.cpp
---
