#pragma once

// Mod int
using ull = unsigned long long; using uint = unsigned;
#define pb push_back
uint mod = 998244353;
//const uint mod = 1000000007;
struct mint {
    uint x;
    mint() : x(0) {}
    mint(ll x) :x((x% mod + mod) % mod) {}
    mint operator-() const { return mint(0) - *this; }
    mint operator~() const { return mint(1) / *this; }
    mint& operator+=(const mint& a) { if ((x += a.x) >= mod) x -= mod; return *this; }
    mint& operator-=(const mint& a) { if ((x += mod - a.x) >= mod) x -= mod; return *this; }
    mint& operator*=(const mint& a) { x = (ull)x * a.x % mod; return *this; }
    mint& operator/=(const mint& a) { x = (ull)x * a.pow(mod - 2).x % mod; return *this; }
    mint operator+(const mint& a) const { return mint(*this) += a; }
    mint operator-(const mint& a) const { return mint(*this) -= a; }
    mint operator*(const mint& a) const { return mint(*this) *= a; }
    mint operator/(const mint& a) const { return mint(*this) /= a; }
    mint operator++() const { return *this + 1; }
    mint operator--() const { return *this - 1; }
    mint pow(ll t) const {
        mint res = 1; for (mint p = x; t; p *= p, t >>= 1) if (t & 1) res *= p; return res;
    }
    mint ppow(ll t) const { int p = mod - 1; return pow((t % p + p) % p); }
    uint val() const { return x; }
    bool operator<(const mint& a) const { return x < a.x; }
    bool operator==(const mint& a) const { return x == a.x; }
    bool operator!=(const mint& a) const { return x != a.x; }
};
mint ex(mint x, ll t) { return x.pow(t); }
istream& operator>>(istream& i, mint& a) { i >> a.x; return i; }
//*
ostream& operator<<(ostream& o, const mint& a) { o << a.x; return o; }
using vm = vector<mint>;
using vvm = vector<vm>;
using vvvm = vector<vvm>;
struct modinv {
    int n; vm d;
    modinv() : n(2), d({ 0,1 }) {}
    mint operator()(int i) { while (n <= i) d.pb(-d[mod % n] * (mod / n)), ++n; return d[i]; }
    mint operator[](int i) const { return d[i]; }
} invs;
struct modfact {
    int n; vm d;
    modfact() : n(2), d({ 1,1 }) {}
    mint operator()(int i) { while (n <= i) d.pb(d.back() * n), ++n; return d[i]; }
    mint operator[](int i) const { return d[i]; }
} facs;
struct modfactinv {
    int n; vm d;
    modfactinv() : n(2), d({ 1,1 }) {}
    mint operator()(int i) { while (n <= i) d.pb(d.back() * invs(n)), ++n; return d[i]; }
    mint operator[](int i) const { return d[i]; }
} ifacs;
mint comb(int a, int b) {
    if (a < b || b < 0) return 0;
    return facs(a) * ifacs(b) * ifacs(a - b);
}
mint comb2(int a, int b) { // if a is big and k is small : O(b)
    if (a < b || b < 0) return 0;
    mint res = ifacs(b);
    for (int i = 0; i < b; i++) res *= (a - i);
    return res;
}
mint hcomb(int a, int b) {
    return comb(a + b - 1, a - 1);
}
mint hcomb2(int a, int b) {
    return comb2(a + b - 1, a - 1);
}
mint perm(int a, int b) {
    if (a < b || b < 0) return 0;
    return  facs(a) * ifacs(a - b);
}
//
