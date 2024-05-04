---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: base.cpp
    title: base.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/Lowest_Common_Ancestor.test.cpp
    title: verify/library_checker/Lowest_Common_Ancestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/Static_RMQ.test.cpp
    title: verify/library_checker/Static_RMQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/Static_Range_Sum.test.cpp
    title: verify/library_checker/Static_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/Strongly_Connected_Components.test.cpp
    title: verify/library_checker/Strongly_Connected_Components.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/Unionfind.test.cpp
    title: verify/library_checker/Unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/test_atcoder/abc327_d.test.cpp
    title: verify/test_atcoder/abc327_d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 2 "my_template.hpp"

    #pragma GCC optimize("O3")

    #include <bits/stdc++.h>

    using namespace std;

    using ll = long long; using ld = long double;

    using P = pair<int, int>; using Pll = pair<ll, ll>;

    using vi = vector<int>; using vvi = vector<vector<int>>; using vvvi = vector<vvi>;

    using vl = vector<ll>; using vvl = vector<vector<ll>>; using vvvl = vector<vvl>;

    using vld = vector<ld>; using vvld = vector<vector<vld>>; using vvvld = vector<vvld>;

    using vp = vector<P>; using vpll = vector<Pll>; using vvp = vector<vector<P>>;

    using vs = vector<string>;

    template <typename T> using pq = priority_queue<T, vector<T>, greater<T>>;

    #define rep(i, s, n) for (long long i = (s); i < (long long)(n); i++)

    #define drep(i, s, n) for (long long i = (s); i >= (long long)(n); i--)

    template <typename T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return
    true; } return false; }

    template <typename T> bool chmin(T& a, const T& b) { if (a > b) { a = b; return
    true; } return false; }

    template <typename T = long long> T floor(T x, T m) { return (x - ((x % m + m)
    % m)) / m; }

    template <typename T = long long> T ceil(T x, T m) { return floor(x + m - 1, m);
    }


    template <class T> constexpr T infty = 0;

    template<> constexpr int infty<int> = 1001001001;

    template<> constexpr long long infty<long long> = 9e18;

    template<> constexpr double infty<double> = infty<long long>;

    template<> constexpr long double infty<long double> = infty<long long>;


    template<class T> istream& operator >> (istream& i, vector<T>& v) { for(T& p :
    v) cin >> p; return i; }

    template<class T> ostream& operator << (ostream& o, vector<T>& v) { for(T& p :
    v) cout << p << " "; return o; }

    template<class T> istream& operator >> (istream& i, vector<vector<T>>& v) { for(vector<T>&
    p : v) cin >> p; return i; }

    template<class T> ostream& operator << (ostream& o, vector<vector<T>>& v) { for(vector<T>&
    p : v) cout << p << ''\n''; return o; }

    template<class T> void operator -- (vector<T>& v, int) { for(T& p : v) p--; }

    template<class T> void operator ++ (vector<T>& v, int) { for(T& p : v) p++; }

    '
  code: '#pragma once

    #pragma GCC optimize("O3")

    #include <bits/stdc++.h>

    using namespace std;

    using ll = long long; using ld = long double;

    using P = pair<int, int>; using Pll = pair<ll, ll>;

    using vi = vector<int>; using vvi = vector<vector<int>>; using vvvi = vector<vvi>;

    using vl = vector<ll>; using vvl = vector<vector<ll>>; using vvvl = vector<vvl>;

    using vld = vector<ld>; using vvld = vector<vector<vld>>; using vvvld = vector<vvld>;

    using vp = vector<P>; using vpll = vector<Pll>; using vvp = vector<vector<P>>;

    using vs = vector<string>;

    template <typename T> using pq = priority_queue<T, vector<T>, greater<T>>;

    #define rep(i, s, n) for (long long i = (s); i < (long long)(n); i++)

    #define drep(i, s, n) for (long long i = (s); i >= (long long)(n); i--)

    template <typename T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return
    true; } return false; }

    template <typename T> bool chmin(T& a, const T& b) { if (a > b) { a = b; return
    true; } return false; }

    template <typename T = long long> T floor(T x, T m) { return (x - ((x % m + m)
    % m)) / m; }

    template <typename T = long long> T ceil(T x, T m) { return floor(x + m - 1, m);
    }


    template <class T> constexpr T infty = 0;

    template<> constexpr int infty<int> = 1001001001;

    template<> constexpr long long infty<long long> = 9e18;

    template<> constexpr double infty<double> = infty<long long>;

    template<> constexpr long double infty<long double> = infty<long long>;


    template<class T> istream& operator >> (istream& i, vector<T>& v) { for(T& p :
    v) cin >> p; return i; }

    template<class T> ostream& operator << (ostream& o, vector<T>& v) { for(T& p :
    v) cout << p << " "; return o; }

    template<class T> istream& operator >> (istream& i, vector<vector<T>>& v) { for(vector<T>&
    p : v) cin >> p; return i; }

    template<class T> ostream& operator << (ostream& o, vector<vector<T>>& v) { for(vector<T>&
    p : v) cout << p << ''\n''; return o; }

    template<class T> void operator -- (vector<T>& v, int) { for(T& p : v) p--; }

    template<class T> void operator ++ (vector<T>& v, int) { for(T& p : v) p++; }'
  dependsOn: []
  isVerificationFile: false
  path: my_template.hpp
  requiredBy:
  - base.cpp
  timestamp: '2024-05-03 01:16:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/test_atcoder/abc327_d.test.cpp
  - verify/library_checker/Unionfind.test.cpp
  - verify/library_checker/Static_Range_Sum.test.cpp
  - verify/library_checker/Lowest_Common_Ancestor.test.cpp
  - verify/library_checker/Static_RMQ.test.cpp
  - verify/library_checker/Strongly_Connected_Components.test.cpp
documentation_of: my_template.hpp
layout: document
redirect_from:
- /library/my_template.hpp
- /library/my_template.hpp.html
title: my_template.hpp
---
