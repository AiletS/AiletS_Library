#pragma once

#include "data_structure/mint.hpp"

int ceil_pow(int n)
{
    int x = 0;
    while((1LL << x) < (long long)(n)) x++;
    return x;
}

void NTT(vector<mint>& a)
{
    int n = a.size();
    int h = ceil_pow(n);

    static bool first = true;
    static mint sum_e[30];
    if(first)
    {
        first = false;
        int g = 3; // primitive root of 998244353
        mint es[30], ies[30];
        int cnt2 = __countr_zero(mod - 1);
        mint e = mint(g).pow((mod - 1) >> cnt2), ie = mint(1) / e;
        for (int i = cnt2; i >= 2; i--) {
            es[i - 2] = e;
            ies[i - 2] = ie;
            e *= e;
            ie *= ie;
        }
        mint now = 1;
        for (int i = 0; i <= cnt2 - 2; i++) {
            sum_e[i] = es[i] * now;
            now *= ies[i];
        }
    }

    for (int ph = 1; ph <= h; ph++) 
    {
        int w = 1 << (ph - 1), p = 1 << (h - ph);
        mint now = 1;
        for (int s = 0; s < w; s++) {
            int offset = s << (h - ph + 1);
            for (int i = 0; i < p; i++) {
                auto l = a[i + offset];
                auto r = a[i + offset + p] * now;
                a[i + offset] = l + r;
                a[i + offset + p] = l - r;
            }
            now *= sum_e[__countr_zero(~(unsigned int)(s))];
        }
    }
}

void NTT_inv(vector<mint>& a)
{
    int n = a.size();
    int h = ceil_pow(n);

    static bool first = true;
    static mint sum_ie[30];  
    if (first) 
    {
        first = false;
        int g = 3; // primitive root of 998244353
        mint es[30], ies[30];  // es[i]^(2^(2+i)) == 1
        int cnt2 = __countr_zero(mod - 1);
        mint e = mint(g).pow((mod - 1) >> cnt2), ie = mint(1) / e;
        for (int i = cnt2; i >= 2; i--) {
            es[i - 2] = e;
            ies[i - 2] = ie;
            e *= e;
            ie *= ie;
        }
        mint now = 1;
        for (int i = 0; i <= cnt2 - 2; i++) {
            sum_ie[i] = ies[i] * now;
            now *= es[i];
        }
    }

    for (int ph = h; ph >= 1; ph--) 
    {
        int w = 1 << (ph - 1), p = 1 << (h - ph);
        mint inow = 1;
        for (int s = 0; s < w; s++) {
            int offset = s << (h - ph + 1);
            for (int i = 0; i < p; i++) {
                auto l = a[i + offset];
                auto r = a[i + offset + p];
                a[i + offset] = l + r;
                a[i + offset + p] =
                    (unsigned long long)(mod + l.val() - r.val()) *
                    inow.val();
            }
            inow *= sum_ie[__countr_zero(~(unsigned int)(s))];
        }
    }
}

vector<mint> convolution(vector<mint> &a, vector<mint> &b)
{   // mod 998244353
    long long len = a.size() + b.size() - 1, n = 1;
    while(n <= len) n <<= 1;
    a.resize(n), b.resize(n);
    
    NTT(a), NTT(b);
    vector<mint> c(n);
    for(int i = 0; i < n; i++) c[i] = a[i] * b[i];
    NTT_inv(c);
    c.resize(a.size() + b.size() - 1);
    mint in = mint(1) / n;
    for(mint &p : c) p *= in;
    return c;
}

vector<mint> convolution(vector<long long>& a, vector<long long>& b)
{  
    vector<mint> ma, mb;
    for(int i = 0; i < a.size(); i++) ma.push_back(a[i]);
    for(int i = 0; i < b.size(); i++) mb.push_back(b[i]);
    return convolution(ma, mb);
}