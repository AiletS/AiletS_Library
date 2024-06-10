#pragma once

template <typename T = long long>
struct Matrix
{
    int n, m;
    vector<vector<T>> v;

    Matrix() : v(vector<vector<T>>()) {}
    Matrix(int n) : v(vector<vector<T>>(n, vector<T>(n))), n(n), m(n) {}
    Matrix(int n, int m) : v(vector<vector<T>>(n, vector<T>(m))), n(n), m(m) {}
    Matrix(int n, int m, T d) : v(vector<vector<T>>(n, vector<T>(m, d))), n(n), m(m) {}
    Matrix(vector<vector<T>> _v) : v(_v), n(_v.size()), m(_v[0].size()) {}

    vector<T>& operator[](int i) { return v[i]; }
    vector<T> operator[](int i) const { return v[i]; }

    void identity() 
    {
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) (i == j ? v[i][j] = 1 : v[i][j] = 0);
    }

    Matrix& operator+=(const Matrix& a) 
    {  
        assert(n == a.n && m == a.m);
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) v[i][j] += a[i][j];
        return *this;
    }
    Matrix& operator-=(const Matrix& a) 
    {  
        assert(n == a.n && m == a.m);
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) v[i][j] -= a[i][j];
        return *this;
    }
    Matrix& operator*=(const T& a) 
    {  
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) v[i][j] *= a;
        return *this;
    }
    Matrix& operator*=(const Matrix& a) 
    {  
        assert(m == a.n);
        vector<vector<T>> res(n, vector<T>(a.m));      
        for(int i = 0; i < n; i++) for(int j = 0; j < a.m; j++)
            for(int k = 0; k < m; k++) res[i][j] += v[i][k] * a[k][j];
        m = a.m, v = res;
        return *this;
    }
    Matrix operator+(const Matrix& a) const { return Matrix(*this) += a; }
    Matrix operator-(const Matrix& a) const { return Matrix(*this) -= a; }
    Matrix operator*(const T& a) const { return Matrix(*this) *= a; }
    Matrix operator*(const Matrix& a) const { return Matrix(*this) *= a; }

    Matrix pow(long long t) const 
    {
        assert(n == m);
        Matrix res(n, n); res.identity();
        for(Matrix p = *this; t; p *= p, t >>= 1) if(t & 1) res *= p;
        return res;
    }

    // deg = 1, 2, 3 : clockwise
    Matrix& rot(int deg)
    {
        if(deg == 1 || deg == 3)
        {
            vector<vector<T>> res(m, vector<T>(n));
            if(deg == 1) for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) res[j][n - i - 1] = v[i][j];
            if(deg == 3) for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) res[m - j - 1][i] = v[i][j];
            swap(n, m);
            v = res;
        }
        if(deg == 2)
        {
            vector<vector<T>> res(m, vector<T>(n));
            for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) res[n - i - 1][m - j - 1] = v[i][j];
            v = res;
        }     
        return *this;
    }

    void dump()
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++) cout << v[i][j] << ' ';
            cout << '\n';
        }
        return;
    }
};