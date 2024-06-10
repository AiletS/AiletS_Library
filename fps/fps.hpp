#pragma once

#include "data_structure/mint.hpp"
#include "math/convolution.hpp"

template<class T>
struct FormalPowerSeries : vector<T>
{
    using fps = FormalPowerSeries;
    using vector<T>::vector;
    using vector<T>::operator=;

    fps operator-() const { fps r(*this); for(auto& p : r) p = -p; return r; }
    fps& operator+=(const fps& r) 
    { 
        int n = min((*this).size(), r.size());   
        for(int i = 0; i < n; i++) (*this)[i] += r[i];
        return *this;
    }
    fps operator+(const fps& r) const { return fps(*this) += r; }
    fps& operator-=(const fps& r) 
    { 
        int n = min((*this).size(), r.size());   
        for(int i = 0; i < n; i++) (*this)[i] -= r[i];
        return *this;
    }
    fps operator-(const fps& r) const { return fps(*this) -= r; }
    fps& operator*=(T& c) { for(auto& p : *this) p *= c; return *this; }
    fps operator*(T c) { return fps(*this) *= c; }
    fps& operator*=(const fps& r) { *this = convolution(*this, r); return *this; }
    fps operator*(const fps& r) const { return fps(*this) *= r; }
    fps& operator<<=(const T& c) 
    {
        int n = (*this).size();
        (*this).insert((*this).begin(), c, 0);
        (*this).resize(n);
        return *this;
    }
    fps operator<<(const T c) const { return fps(*this) <<= c; }
    fps& operator>>=(const T& c)
    {
        int n = (*this).size();
        (*this).erase((*this).begin(), (*this).begin() + min(n, c));
        (*this).resize(n);
        return *this;
    }
    fps operator>>(const T c) const { return fps(*this) >>= c; }
};

using fps = FormalPowerSeries<mint>;