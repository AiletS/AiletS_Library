---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/Matrix.hpp\"\n\ntemplate <typename T = long\
    \ long>\nstruct Matrix\n{\n    int n, m;\n    vector<vector<T>> v;\n\n    Matrix()\
    \ : v(vector<vector<T>>()) {}\n    Matrix(int n) : v(vector<vector<T>>(n, vector<T>(n))),\
    \ n(n), m(n) {}\n    Matrix(int n, int m) : v(vector<vector<T>>(n, vector<T>(m))),\
    \ n(n), m(m) {}\n    Matrix(int n, int m, T d) : v(vector<vector<T>>(n, vector<T>(m,\
    \ d))), n(n), m(m) {}\n    Matrix(vector<vector<T>> _v) : v(_v), n(_v.size()),\
    \ m(_v[0].size()) {}\n\n    vector<T>& operator[](int i) { return v[i]; }\n  \
    \  vector<T> operator[](int i) const { return v[i]; }\n\n    void identity() \n\
    \    {\n        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) (i == j\
    \ ? v[i][j] = 1 : v[i][j] = 0);\n    }\n\n    Matrix& operator+=(const Matrix&\
    \ a) \n    {  \n        assert(n == a.n && m == a.m);\n        for(int i = 0;\
    \ i < n; i++) for(int j = 0; j < n; j++) v[i][j] += a[i][j];\n        return *this;\n\
    \    }\n    Matrix& operator-=(const Matrix& a) \n    {  \n        assert(n ==\
    \ a.n && m == a.m);\n        for(int i = 0; i < n; i++) for(int j = 0; j < n;\
    \ j++) v[i][j] -= a[i][j];\n        return *this;\n    }\n    Matrix& operator*=(const\
    \ T& a) \n    {  \n        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)\
    \ v[i][j] *= a;\n        return *this;\n    }\n    Matrix& operator*=(const Matrix&\
    \ a) \n    {  \n        assert(m == a.n);\n        vector<vector<T>> res(n, vector<T>(a.m));\
    \      \n        for(int i = 0; i < n; i++) for(int j = 0; j < a.m; j++)\n   \
    \         for(int k = 0; k < m; k++) res[i][j] += v[i][k] * a[k][j];\n       \
    \ m = a.m, v = res;\n        return *this;\n    }\n    Matrix operator+(const\
    \ Matrix& a) const { return Matrix(*this) += a; }\n    Matrix operator-(const\
    \ Matrix& a) const { return Matrix(*this) -= a; }\n    Matrix operator*(const\
    \ T& a) const { return Matrix(*this) *= a; }\n    Matrix operator*(const Matrix&\
    \ a) const { return Matrix(*this) *= a; }\n\n    Matrix pow(long long t) const\
    \ \n    {\n        assert(n == m);\n        Matrix res(n, n); res.identity();\n\
    \        for(Matrix p = *this; t; p *= p, t >>= 1) if(t & 1) res *= p;\n     \
    \   return res;\n    }\n\n    // deg = 1, 2, 3 : clockwise\n    Matrix& rot(int\
    \ deg)\n    {\n        if(deg == 1 || deg == 3)\n        {\n            vector<vector<T>>\
    \ res(m, vector<T>(n));\n            if(deg == 1) for(int i = 0; i < n; i++) for(int\
    \ j = 0; j < m; j++) res[j][n - i - 1] = v[i][j];\n            if(deg == 3) for(int\
    \ i = 0; i < n; i++) for(int j = 0; j < m; j++) res[m - j - 1][i] = v[i][j];\n\
    \            swap(n, m);\n            v = res;\n        }\n        if(deg == 2)\n\
    \        {\n            vector<vector<T>> res(m, vector<T>(n));\n            for(int\
    \ i = 0; i < n; i++) for(int j = 0; j < m; j++) res[n - i - 1][m - j - 1] = v[i][j];\n\
    \            v = res;\n        }     \n        return *this;\n    }\n\n    void\
    \ dump()\n    {\n        for(int i = 0; i < n; i++)\n        {\n            for(int\
    \ j = 0; j < m; j++) cout << v[i][j] << ' ';\n            cout << '\\n';\n   \
    \     }\n        return;\n    }\n};\n"
  code: "#pragma once\n\ntemplate <typename T = long long>\nstruct Matrix\n{\n   \
    \ int n, m;\n    vector<vector<T>> v;\n\n    Matrix() : v(vector<vector<T>>())\
    \ {}\n    Matrix(int n) : v(vector<vector<T>>(n, vector<T>(n))), n(n), m(n) {}\n\
    \    Matrix(int n, int m) : v(vector<vector<T>>(n, vector<T>(m))), n(n), m(m)\
    \ {}\n    Matrix(int n, int m, T d) : v(vector<vector<T>>(n, vector<T>(m, d))),\
    \ n(n), m(m) {}\n    Matrix(vector<vector<T>> _v) : v(_v), n(_v.size()), m(_v[0].size())\
    \ {}\n\n    vector<T>& operator[](int i) { return v[i]; }\n    vector<T> operator[](int\
    \ i) const { return v[i]; }\n\n    void identity() \n    {\n        for(int i\
    \ = 0; i < n; i++) for(int j = 0; j < m; j++) (i == j ? v[i][j] = 1 : v[i][j]\
    \ = 0);\n    }\n\n    Matrix& operator+=(const Matrix& a) \n    {  \n        assert(n\
    \ == a.n && m == a.m);\n        for(int i = 0; i < n; i++) for(int j = 0; j <\
    \ n; j++) v[i][j] += a[i][j];\n        return *this;\n    }\n    Matrix& operator-=(const\
    \ Matrix& a) \n    {  \n        assert(n == a.n && m == a.m);\n        for(int\
    \ i = 0; i < n; i++) for(int j = 0; j < n; j++) v[i][j] -= a[i][j];\n        return\
    \ *this;\n    }\n    Matrix& operator*=(const T& a) \n    {  \n        for(int\
    \ i = 0; i < n; i++) for(int j = 0; j < n; j++) v[i][j] *= a;\n        return\
    \ *this;\n    }\n    Matrix& operator*=(const Matrix& a) \n    {  \n        assert(m\
    \ == a.n);\n        vector<vector<T>> res(n, vector<T>(a.m));      \n        for(int\
    \ i = 0; i < n; i++) for(int j = 0; j < a.m; j++)\n            for(int k = 0;\
    \ k < m; k++) res[i][j] += v[i][k] * a[k][j];\n        m = a.m, v = res;\n   \
    \     return *this;\n    }\n    Matrix operator+(const Matrix& a) const { return\
    \ Matrix(*this) += a; }\n    Matrix operator-(const Matrix& a) const { return\
    \ Matrix(*this) -= a; }\n    Matrix operator*(const T& a) const { return Matrix(*this)\
    \ *= a; }\n    Matrix operator*(const Matrix& a) const { return Matrix(*this)\
    \ *= a; }\n\n    Matrix pow(long long t) const \n    {\n        assert(n == m);\n\
    \        Matrix res(n, n); res.identity();\n        for(Matrix p = *this; t; p\
    \ *= p, t >>= 1) if(t & 1) res *= p;\n        return res;\n    }\n\n    // deg\
    \ = 1, 2, 3 : clockwise\n    Matrix& rot(int deg)\n    {\n        if(deg == 1\
    \ || deg == 3)\n        {\n            vector<vector<T>> res(m, vector<T>(n));\n\
    \            if(deg == 1) for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)\
    \ res[j][n - i - 1] = v[i][j];\n            if(deg == 3) for(int i = 0; i < n;\
    \ i++) for(int j = 0; j < m; j++) res[m - j - 1][i] = v[i][j];\n            swap(n,\
    \ m);\n            v = res;\n        }\n        if(deg == 2)\n        {\n    \
    \        vector<vector<T>> res(m, vector<T>(n));\n            for(int i = 0; i\
    \ < n; i++) for(int j = 0; j < m; j++) res[n - i - 1][m - j - 1] = v[i][j];\n\
    \            v = res;\n        }     \n        return *this;\n    }\n\n    void\
    \ dump()\n    {\n        for(int i = 0; i < n; i++)\n        {\n            for(int\
    \ j = 0; j < m; j++) cout << v[i][j] << ' ';\n            cout << '\\n';\n   \
    \     }\n        return;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/Matrix.hpp
  requiredBy: []
  timestamp: '2024-06-10 11:18:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/Matrix.hpp
layout: document
redirect_from:
- /library/data_structure/Matrix.hpp
- /library/data_structure/Matrix.hpp.html
title: data_structure/Matrix.hpp
---
