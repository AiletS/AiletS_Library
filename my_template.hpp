#pragma once
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
template <typename T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } return false; }
template <typename T> bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } return false; }
template <typename T = long long> T floor(T x, T m) { return (x - ((x % m + m) % m)) / m; }
template <typename T = long long> T ceil(T x, T m) { return floor(x + m - 1, m); }

template <class T> constexpr T infty = 0;
template<> constexpr int infty<int> = 1001001001;
template<> constexpr long long infty<long long> = 9e18;
template<> constexpr double infty<double> = infty<long long>;
template<> constexpr long double infty<long double> = infty<long long>;

template<class T> istream& operator >> (istream& i, vector<T>& v) { for(T& p : v) cin >> p; return i; }
template<class T> ostream& operator << (ostream& o, vector<T>& v) { for(T& p : v) cout << p << " "; return o; }
template<class T> istream& operator >> (istream& i, vector<vector<T>>& v) { for(vector<T>& p : v) cin >> p; return i; }
template<class T> ostream& operator << (ostream& o, vector<vector<T>>& v) { for(vector<T>& p : v) cout << p << '\n'; return o; }
template<class T> void operator -- (vector<T>& v, int) { for(T& p : v) p--; }
template<class T> void operator ++ (vector<T>& v, int) { for(T& p : v) p++; }