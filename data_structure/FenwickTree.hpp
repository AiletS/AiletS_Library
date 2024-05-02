#pragma once

/*
FenwickTree (BIT)
FenwickTree<T = long long>(), FenwickTree<T = long long>(int _n) サイズ n で生成
add(int p, T x) p に x を足す
get(int l, int r) [l, r) の和を取得
*/
template <class T = long long>
class FenwickTree
{
  public:
	FenwickTree() : n(0) {}
	FenwickTree(int _n) : n(_n), data(_n, 0) {}

	void add(int p, T x) // add x at p
	{
		assert(0 <= p && p < n);
		for (++p; p <= n; p += (p & -p)) data[p - 1] += x;
	}

	T get(int l, int r) // sum [l, r)
	{
		assert(0 <= l && l <= r && r <= n);
		return sum(r) - sum(l);
	}

  private:
	int n;
	vector<T> data;

	T sum(int x)
	{
		T s = 0;
		for (; x > 0; x -= (x & -x)) s += data[x - 1];
		return s;
	}
};
