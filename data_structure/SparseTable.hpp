#pragma once

/*
冪等な Monoid である必要がある (f(f(x)) = f(x))
冪等性と結合測が満たされれば良い

SparseTable
SparseTable<monoid>(vector<monoid::TYPE> v)
get(int l, int r) [l, r) の結果を取得
*/
template <class Monoid>
struct SparseTable
{
    using T = typename Monoid::TYPE;
    SparseTable() {}
    SparseTable(const vector<T>& _v) : n(_v.size()), w(n + 1)
    {
        for (int i = 2; i < n + 1; i++) w[i] = w[i >> 1] + 1;
		v = vector<vector<T>>(w[n] + 1, vector<T>(n, Monoid::e()));
		for (int i = 0; i < n; i++) v[0][i] = _v[i];
		for (int i = 1; (1 << i) <= n; i++)
			for (int j = 0; j + (1 << i) <= n; j++)
			{
				v[i][j] = Monoid::op(v[i - 1][j], v[i - 1][j + (1 << (i - 1))]);
			}
    }

    T get(int l, int r)
    {
        assert(l <= r && l >= 0 && l < n && r >= 0 && r <= n);
        int k = w[r - l];
		return Monoid::op(v[k][l], v[k][r - (1 << k)]);
    }

private:
    int n;
    vector<int> w;
    vector<vector<T>> v;
};