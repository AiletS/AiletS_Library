#pragma once

/*
有理数ライブラリ
Ra(long long x) : x / 1
Ra(long long x, long long y) : x / y
n が分子 d が分母
*/
struct Ra {
    long long n, d;
    Ra() : n(0), d(1) { re(*this); }
    Ra(long long x) : n(x), d(1) { re(*this); }
    Ra(long long x, long long y) : n(x), d(y) { if (d < 0) n = -n, d = -d; re(*this); }
    void re(Ra& x) { long long y = gcd(x.d, x.n); x.n /= y, x.d /= y; }
    bool operator<(const Ra& x) { return n * x.d < x.n* d; }
    bool operator<(const long long& x) { return *this < Ra(x); }
    bool operator>(const Ra& x) { return n * x.d > x.n * d; }
    bool operator>(const long long& x) { return *this > Ra(x); }
    bool operator<=(const Ra& x) { return !(*this > x); }
    bool operator<=(const long long& x) { return *this <= Ra(x); }
    bool operator>=(const Ra& x) { return !(*this < x); }
    bool operator>=(const long long& x) { return *this >= Ra(x); }
    bool operator==(const Ra& x) { return n * x.d == x.n * d; }
    bool operator==(const long long& x) { return *this == Ra(x); }
    bool operator!=(const Ra& x) { return n * x.d != x.n * d; }
    bool operator!=(const long long& x) { return *this != Ra(x); }
    Ra& operator+=(const Ra& x) { n = n * x.d + x.n * d, d = d * x.d; re(*this); return *this; }
    Ra operator+(const Ra& x) const { return Ra(*this) += x; }
    Ra& operator-=(const Ra& x) { n = n * x.d - x.n * d, d = d * x.d; re(*this); return *this; }
    Ra operator-(const Ra& x) const { return Ra(*this) -= x; }
    Ra& operator*=(const Ra& x) { n = n * x.n, d = d * x.d; re(*this); return *this; }
    Ra operator*(const Ra& x) const { return Ra(*this) *= x; }
    Ra& operator/=(const Ra& x) { n = n * x.d, d = d * x.n; re(*this); return *this; }
    Ra operator/(const Ra& x) const { return Ra(*this) /= x; }
    Ra operator-() const { return Ra() - *this; }
};
ostream& operator<<(ostream& o, const Ra& a) { o << a.n << " / " << a.d; return o; }