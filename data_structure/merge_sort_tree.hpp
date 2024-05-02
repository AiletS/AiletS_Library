#pragma once

/*
merge sort tree
merge_sorte_tree<T = long long>(vector<T> v)
pair<T,T> get(l, r, x) : [l, r) の区間で x 以下のものの個数とその総和を求める O(log^2 N)
*/
template <typename T = long long>
struct merge_sort_tree
{
    int n;
    vector<vector<T>> v;
    vector<vector<T>> sum;

    merge_sort_tree() {}
    merge_sort_tree(const vector<T>& _v)
    {
        int m = _v.size();
        n = 1; while(n < m) n <<= 1;
        v.resize(n << 1);
        sum = vector<vector<T>>(n << 1, vector<T>(1));
        for(int i = 0; i < m; i++) 
        {
            v[i + n].push_back(_v[i]);
            sum[i + n].push_back(_v[i]);
        }
        init();
    }

    void init()
    {
        for(int i = n - 1; i >= 1; i--)
        {
            int l = i << 1, r = l | 1;
            merge(v[l].begin(), v[l].end(),
                  v[r].begin(), v[r].end(),
                  back_inserter(v[i]));
            sum[i] = vector<T>(v[i].size() + 1, 0);
            rep(j, 0, v[i].size()) sum[i][j + 1] = sum[i][j] + v[i][j];
        }
    }

    pair<T, T> get(int i, T x)
    {
        int j = upper_bound(v[i].begin(), v[i].end(), x) - v[i].begin();
        return {j, sum[i][j]};
    }

    pair<T, T> get(int l, int r, T x)
    {
        l += n, r += n;
        pair<T, T> res = {0, 0};
        while(l < r)
        {
            if(l & 1) { auto tmp = get(l++, x); res.first += tmp.first, res.second += tmp.second; }
            if(r & 1) { auto tmp = get(--r, x); res.first += tmp.first, res.second += tmp.second; }
            l >>= 1, r >>= 1;
        }
        return res;
    }
};