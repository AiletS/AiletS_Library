#pragma once

/*
Eratos(long long n) // O(n log log n)
get_nth_prime(long long id) : 1-index, O(1)
factorize : not sorted O(log n)
divisor : not sorted O(log n)
fast zeta, fast mobius
*/
struct Eratos
{
    vector<long long> prime;
    vector<long long> nth_prime;
    vector<long long> minfactor;
    vector<long long> mobius;

    Eratos(long long n)
    {   // O(n log log n)
        prime = vector<long long>(n + 1, 1); prime[1] = 0;
        minfactor = vector<long long>(n + 1, -1); minfactor[1] = 1;
        mobius = vector<long long>(n + 1, 1);

        for (long long i = 2; i <= n; i++)
        {
            if (!prime[i]) continue;
            nth_prime.push_back(i);
            minfactor[i] = i;
            for (long long j = i * 2; j <= n; j += i)
            {
                prime[j] = 0;
                if (minfactor[j] == -1) minfactor[j] = i;
                (j / i) % i == 0 ? mobius[j] = 0 : mobius[j] = -mobius[j];
            }
        }
    }

    long long get_nth_prime(long long id) 
    { 
        assert(id >= 0 && id < nth_prime.size());
        return nth_prime[id - 1]; 
    }

    vector<pair<long long, long long>> factorize(long long n)
    {   // not sorted, O(log n)
        vector<pair<long long, long long>> res;
        while (n > 1)
        {
            long long p = minfactor[n];
            long long q = 0;
            while (minfactor[n] == p) n /= p, q++;
            res.emplace_back(p, q);
        }
        return res;
    }

    vector<long long> divisor(long long n)
    {   // not sorted
        vector<long long> res = { 1 };
        vector<pair<long long, long long>> pf = factorize(n);
        for (auto [p, q] : pf)
        {
            int x = (int)res.size();
            for (int i = 0; i < x; i++)
            {
                long long y = 1;
                for (int j = 0; j < q; j++) y *= p, res.push_back(res[i] * y);
            }
        }
        return res;
    }

    template<class T>
    void fast_zeta(vector<T>& v)
    {   // F(n) = sigma_(n|i) f(i)
        int n = v.size() - 1;
        for (int i = 2; i <= n; i++)
        {
            if (!prime[i]) continue;
            for (int j = n / i; j >= 1; j--) v[j] += v[j * i];
        }
    }

    template<class T>
    void fast_mobius(vector<T>& v)
    {   // f(n) = sigma_(n|i) μ(i/n)F(i)
        int n = v.size() - 1;
        for (int i = 2; i <= n; i++)
        {
            if (!prime[i]) continue;
            for (int j = 1; j * i <= n; j++) v[j] -= v[j * i];
        }
    }
};