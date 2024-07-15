#pragma once

struct V
{
    long double x, y, eps = 1e-9;
    V() {}
    V(long double x = 0, long double y = 0) : x(x), y(y) {}
    V& operator+=(const V& v) { x += v.x; y += v.y; return *this;}
    V operator+(const V& v) const { return V(*this) += v;}
    V& operator-=(const V& v) { x -= v.x; y -= v.y; return *this;}
    V operator-(const V& v) const { return V(*this) -= v;}
    V& operator*=(long double s) { x *= s; y *= s; return *this;}
    V operator*(long double s) const { return V(*this) *= s;}
    V& operator/=(long double s) { x /= s; y /= s; return *this;}
    V operator/(long double s) const { return V(*this) /= s;}
    long double dot(const V& v) const { return x * v.x + y * v.y;}
    long double cross(const V& v) const { return x * v.y - v.x * y;}
    long double norm2() const { return x * x + y * y;}
    long double norm() const { return sqrt(norm2());}
    V normalize() const { return *this / norm();}
    V rotate90() const { return V(y, -x);}
    int ort() const { // orthant
        if (abs(x) < eps && abs(y) < eps) return 0;
        if (y > 0) return x > 0 ? 1 : 2;
        else return x > 0 ? 4 : 3;
    }
    bool operator<(const V& v) const {
        int o = ort(), vo = v.ort();
        if (o != vo) return o < vo;
        return cross(v) > 0;
    }
};
istream& operator>>(istream& is, V& v) {
  is >> v.x >> v.y; return is;
}
ostream& operator<<(ostream& os, const V& v) {
  os<<"("<<v.x<<","<<v.y<<")"; return os;
}