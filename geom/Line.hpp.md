---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: geom/Vector.hpp
    title: geom/Vector.hpp
  _extendedRequiredBy: []
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
    )\"; return os;\n}\n#line 3 \"geom/Line.hpp\"\n\nstruct Line\n{\n    V s, t;\n\
    \    Line() {}\n    Line(V s = V(0,0), V t = V(0,0)): s(s), t(t) {}\n    V dir()\
    \ const { return t - s;}\n    V normalize() const { return dir().normalize();\
    \ }\n    double norm() const { return dir().norm(); }\n    /* +1: s-t,s-p : ccw\n\
    \    * -1: s-t,s-p : cw\n    * +2: t-s-p\n    * -2: s-t-p\n    *  0: s-p-t */\n\
    \    const long double eps = 1e-9;\n    int ccw(const V& p) const {\n        if\
    \ (dir().cross(p-s) > eps) return +1;\n        if (dir().cross(p-s) < -eps) return\
    \ -1;\n        if (dir().dot(p-s) < -eps) return +2;\n        if (dir().dot(t-p)\
    \ < -eps) return -2;\n        return 0;\n    }\n    bool touch(const Line& l)\
    \ const {\n        int a = ccw(l.s)*ccw(l.t), b = l.ccw(s)*l.ccw(t);\n       \
    \ return !a || !b || (a == -1 && b == -1);\n    }\n};\n"
  code: "#pragma once\n#include \"geom/Vector.hpp\"\n\nstruct Line\n{\n    V s, t;\n\
    \    Line() {}\n    Line(V s = V(0,0), V t = V(0,0)): s(s), t(t) {}\n    V dir()\
    \ const { return t - s;}\n    V normalize() const { return dir().normalize();\
    \ }\n    double norm() const { return dir().norm(); }\n    /* +1: s-t,s-p : ccw\n\
    \    * -1: s-t,s-p : cw\n    * +2: t-s-p\n    * -2: s-t-p\n    *  0: s-p-t */\n\
    \    const long double eps = 1e-9;\n    int ccw(const V& p) const {\n        if\
    \ (dir().cross(p-s) > eps) return +1;\n        if (dir().cross(p-s) < -eps) return\
    \ -1;\n        if (dir().dot(p-s) < -eps) return +2;\n        if (dir().dot(t-p)\
    \ < -eps) return -2;\n        return 0;\n    }\n    bool touch(const Line& l)\
    \ const {\n        int a = ccw(l.s)*ccw(l.t), b = l.ccw(s)*l.ccw(t);\n       \
    \ return !a || !b || (a == -1 && b == -1);\n    }\n};"
  dependsOn:
  - geom/Vector.hpp
  isVerificationFile: false
  path: geom/Line.hpp
  requiredBy: []
  timestamp: '2024-07-16 01:07:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geom/Line.hpp
layout: document
redirect_from:
- /library/geom/Line.hpp
- /library/geom/Line.hpp.html
title: geom/Line.hpp
---
