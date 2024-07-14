---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geom/Line.hpp
    title: geom/Line.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geom/Vector.hpp\"\n\nstruct V\n{\n    long double x, y,\
    \ eps = 1e-9;\n    V() {}\n    V(long double x = 0, long double y = 0) : x(x),\
    \ y(y) {}\n    V& operator+=(const V& v) { x += v.x; y += v.y; return *this;}\n\
    \    V operator+(const V& v) const { return V(*this) += v;}\n    V& operator-=(const\
    \ V& v) { x -= v.x; y -= v.y; return *this;}\n    V operator-(const V& v) const\
    \ { return V(*this) -= v;}\n    V& operator*=(long double s) { x *= s; y *= s;\
    \ return *this;}\n    V operator*(long double s) const { return V(*this) *= s;}\n\
    \    V& operator/=(long double s) { x /= s; y /= s; return *this;}\n    V operator/(long\
    \ double s) const { return V(*this) /= s;}\n    long double dot(const V& v) const\
    \ { return x * v.x + y * v.y;}\n    long double cross(const V& v) const { return\
    \ x * v.y - v.x * y;}\n    long double norm2() const { return x * x + y * y;}\n\
    \    long double norm() const { return sqrt(norm2());}\n    V normalize() const\
    \ { return *this / norm();}\n    V rotate90() const { return V(y, -x);}\n    int\
    \ ort() const { // orthant\n        if (abs(x) < eps && abs(y) < eps) return 0;\n\
    \        if (y > 0) return x > 0 ? 1 : 2;\n        else return x > 0 ? 4 : 3;\n\
    \    }\n    bool operator<(const V& v) const {\n        int o = ort(), vo = v.ort();\n\
    \        if (o != vo) return o < vo;\n        return cross(v) > 0;\n    }\n};\n\
    istream& operator>>(istream& is, V& v) {\n  is >> v.x >> v.y; return is;\n}\n\
    ostream& operator<<(ostream& os, const V& v) {\n  os<<\"(\"<<v.x<<\",\"<<v.y<<\"\
    )\"; return os;\n}\n"
  code: "#pragma once\n\nstruct V\n{\n    long double x, y, eps = 1e-9;\n    V() {}\n\
    \    V(long double x = 0, long double y = 0) : x(x), y(y) {}\n    V& operator+=(const\
    \ V& v) { x += v.x; y += v.y; return *this;}\n    V operator+(const V& v) const\
    \ { return V(*this) += v;}\n    V& operator-=(const V& v) { x -= v.x; y -= v.y;\
    \ return *this;}\n    V operator-(const V& v) const { return V(*this) -= v;}\n\
    \    V& operator*=(long double s) { x *= s; y *= s; return *this;}\n    V operator*(long\
    \ double s) const { return V(*this) *= s;}\n    V& operator/=(long double s) {\
    \ x /= s; y /= s; return *this;}\n    V operator/(long double s) const { return\
    \ V(*this) /= s;}\n    long double dot(const V& v) const { return x * v.x + y\
    \ * v.y;}\n    long double cross(const V& v) const { return x * v.y - v.x * y;}\n\
    \    long double norm2() const { return x * x + y * y;}\n    long double norm()\
    \ const { return sqrt(norm2());}\n    V normalize() const { return *this / norm();}\n\
    \    V rotate90() const { return V(y, -x);}\n    int ort() const { // orthant\n\
    \        if (abs(x) < eps && abs(y) < eps) return 0;\n        if (y > 0) return\
    \ x > 0 ? 1 : 2;\n        else return x > 0 ? 4 : 3;\n    }\n    bool operator<(const\
    \ V& v) const {\n        int o = ort(), vo = v.ort();\n        if (o != vo) return\
    \ o < vo;\n        return cross(v) > 0;\n    }\n};\nistream& operator>>(istream&\
    \ is, V& v) {\n  is >> v.x >> v.y; return is;\n}\nostream& operator<<(ostream&\
    \ os, const V& v) {\n  os<<\"(\"<<v.x<<\",\"<<v.y<<\")\"; return os;\n}"
  dependsOn: []
  isVerificationFile: false
  path: geom/Vector.hpp
  requiredBy:
  - geom/Line.hpp
  timestamp: '2024-07-16 01:07:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geom/Vector.hpp
layout: document
redirect_from:
- /library/geom/Vector.hpp
- /library/geom/Vector.hpp.html
title: geom/Vector.hpp
---
