#pragma once

/*
Monoidが必要
segtree(), segtree(int k), segtree(vector<Monoid::TYPE> v)
1,2番目は operator[i]で追加して init()が必要
void set(int i, T x) [i] を x に設定
void add(int i, T x) [i] に x を足す(Monoid の op を適用する)
T get(int l, int r) [l, r) の演算結果を得る
*/
template <class Monoid>
struct segtree
{
  private:
	using T = typename Monoid::TYPE;
	int n;
	vector<T> v;
	
	void upd(int i) { v[i] = Monoid::op(v[i << 1], v[i << 1 | 1]); }

  public:
	segtree() : segtree(vector<T>(0)){}
	segtree(int k) : segtree(vector<T>(k, Monoid::e())) {}
	segtree(const vector<T>& _v)
	{
		int k = _v.size();
		n = 1; while(n < k) n <<= 1;
		v = vector<T>(n << 1, Monoid::e());
		for(int i = 0; i < k; i++) v[i + n] = _v[i];
		init();
	}

	T& operator[](int i) { return v[i + n]; }

	void init() { for (int i = n - 1; i; i--) upd(i); }

	void set(int i, T x) { for (i += n, v[i] = x, i >>= 1; i; i >>= 1) upd(i); }

	void add(int i, T x) { for (i += n, v[i] += x, i >>= 1; i; i >>= 1) upd(i); }

	T get(int l, int r) // [l, r)
	{
		T ls = Monoid::e(), rs = Monoid::e();
		l += n; r += n;

		while (l < r) {
			if (l & 1) ls = Monoid::op(ls, v[l++]);
			if (r & 1) rs = Monoid::op(v[--r], rs);
			l >>= 1; r >>= 1;
		}
		return Monoid::op(ls, rs);
	}
};