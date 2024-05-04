---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structure/merge_sort_tree.hpp
    title: data_structure/merge_sort_tree.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc351/tasks/abc351_f
    links:
    - https://atcoder.jp/contests/abc351/tasks/abc351_f
  bundledCode: "#line 1 \"verify/test_atcoder/abc351_f.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc351/tasks/abc351_f\"\n#line 2 \"my_template.hpp\"\
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
    \ v) p++; }\n#line 2 \"data_structure/merge_sort_tree.hpp\"\n\n/*\nmerge sort\
    \ tree\nmerge_sorte_tree<T = long long>(vector<T> v)\npair<T,T> get(l, r, x) :\
    \ [l, r) \u306E\u533A\u9593\u3067 x \u4EE5\u4E0B\u306E\u3082\u306E\u306E\u500B\
    \u6570\u3068\u305D\u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B O(log^2 N)\n*/\n\
    template <typename T = long long>\nstruct merge_sort_tree\n{\n    int n;\n   \
    \ vector<vector<T>> v;\n    vector<vector<T>> sum;\n\n    merge_sort_tree() {}\n\
    \    merge_sort_tree(const vector<T>& _v)\n    {\n        int m = _v.size();\n\
    \        n = 1; while(n < m) n <<= 1;\n        v.resize(n << 1);\n        sum\
    \ = vector<vector<T>>(n << 1, vector<T>(1));\n        for(int i = 0; i < m; i++)\
    \ \n        {\n            v[i + n].push_back(_v[i]);\n            sum[i + n].push_back(_v[i]);\n\
    \        }\n        init();\n    }\n\n    void init()\n    {\n        for(int\
    \ i = n - 1; i >= 1; i--)\n        {\n            int l = i << 1, r = l | 1;\n\
    \            merge(v[l].begin(), v[l].end(),\n                  v[r].begin(),\
    \ v[r].end(),\n                  back_inserter(v[i]));\n            sum[i] = vector<T>(v[i].size()\
    \ + 1, 0);\n            rep(j, 0, v[i].size()) sum[i][j + 1] = sum[i][j] + v[i][j];\n\
    \        }\n    }\n\n    pair<T, T> get(int i, T x)\n    {\n        int j = upper_bound(v[i].begin(),\
    \ v[i].end(), x) - v[i].begin();\n        return {j, sum[i][j]};\n    }\n\n  \
    \  pair<T, T> get(int l, int r, T x)\n    {\n        l += n, r += n;\n       \
    \ pair<T, T> res = {0, 0};\n        while(l < r)\n        {\n            if(l\
    \ & 1) { auto tmp = get(l++, x); res.first += tmp.first, res.second += tmp.second;\
    \ }\n            if(r & 1) { auto tmp = get(--r, x); res.first += tmp.first, res.second\
    \ += tmp.second; }\n            l >>= 1, r >>= 1;\n        }\n        return res;\n\
    \    }\n};\n#line 4 \"verify/test_atcoder/abc351_f.test.cpp\"\n\nvoid solve()\n\
    {\n    ll n; cin >> n;\n    vl v(n); cin >> v;\n    merge_sort_tree st(v);\n \
    \   ll sum = accumulate(v.begin(), v.end(), 0LL);\n    ll ans = 0;\n    rep(i,\
    \ 0, n)\n    {\n        sum -= v[i];\n        auto [x, y] = st.get(i + 1, n, v[i]);\n\
    \        ans += (sum - y) - v[i] * (n - 1 - i - x);\n    }\n    cout << ans;\n\
    }\n\nint main()\n{\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    int t = 1;\n    //cin >> t;\n    while (t--) solve();\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc351/tasks/abc351_f\"\n#include\
    \ \"my_template.hpp\"\n#include \"data_structure/merge_sort_tree.hpp\"\n\nvoid\
    \ solve()\n{\n    ll n; cin >> n;\n    vl v(n); cin >> v;\n    merge_sort_tree\
    \ st(v);\n    ll sum = accumulate(v.begin(), v.end(), 0LL);\n    ll ans = 0;\n\
    \    rep(i, 0, n)\n    {\n        sum -= v[i];\n        auto [x, y] = st.get(i\
    \ + 1, n, v[i]);\n        ans += (sum - y) - v[i] * (n - 1 - i - x);\n    }\n\
    \    cout << ans;\n}\n\nint main()\n{\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    int t = 1;\n    //cin >> t;\n    while (t--) solve();\n}"
  dependsOn:
  - my_template.hpp
  - data_structure/merge_sort_tree.hpp
  isVerificationFile: true
  path: verify/test_atcoder/abc351_f.test.cpp
  requiredBy: []
  timestamp: '2024-05-05 03:37:43+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/test_atcoder/abc351_f.test.cpp
layout: document
redirect_from:
- /verify/verify/test_atcoder/abc351_f.test.cpp
- /verify/verify/test_atcoder/abc351_f.test.cpp.html
title: verify/test_atcoder/abc351_f.test.cpp
---
