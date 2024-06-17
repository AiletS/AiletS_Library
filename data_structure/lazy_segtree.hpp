#pragma once

/*
operatormonoid が必要
lazy_segtree(), lazy_segtree(int k), lazy_segtree(vector<T> v)
1,2番目は init() が必要
T get(int l, int r) [l, r) の演算結果を得る
void apply(int l, int r, F f) [l, r) に f を適用
*/
template<class OperatorMonoid>
struct lazy_segtree
{
  private:
    using T = typename OperatorMonoid::TYPE_S;
    using F = typename OperatorMonoid::TYPE_F;
    int n, log;
    vector<T> d;
    vector<F> lz;

	void update(int k) { d[k] = OperatorMonoid::op(d[k << 1], d[k << 1 | 1]); }

	void all_apply(int k, F f)
	{
        d[k] = OperatorMonoid::mapping(f, d[k]);
		if (k < n) lz[k] = OperatorMonoid::composition(lz[k], f);
	}

	void push(int k)
	{
		all_apply(2 * k, lz[k]);
		all_apply(2 * k + 1, lz[k]);
		lz[k] = OperatorMonoid::id();
	}

  public:
	lazy_segtree() : lazy_segtree(vector<T>(0)) {}
	lazy_segtree(int k) : lazy_segtree(vector<T>(k, OperatorMonoid::e())) {}
    lazy_segtree(const vector<T>& _v)
    {
        int k = _v.size();
		log = 0; while ((1 << log) < k) log++;
		n = 1 << log;
		d = vector<T>(n << 1);
		lz = vector<F>(n);
        for(int i = 0; i < k; i++) d[i + n] = _v[i];
        init();
    }

	T& operator[](int i) { return d[i + n]; }
	void init() { for (int i = n - 1; i; i--) update(i); }

	T get(int p) // get d[p]
	{
		p += n;
		for (int i = log; i >= 1; i--) push(p >> i);
		return d[p];
	}

	T get(int l, int r) // get [l, r)
	{
		if (l == r) return OperatorMonoid::e();

		l += n;
		r += n;

		for (int i = log; i >= 1; i--) {
			if (((l >> i) << i) != l) push(l >> i);
			if (((r >> i) << i) != r) push(r >> i);
		}

		T sml = OperatorMonoid::e(), smr = OperatorMonoid::e();
		while (l < r) {
			if (l & 1) sml = OperatorMonoid::op(sml, d[l++]);
			if (r & 1) smr = OperatorMonoid::op(d[--r], smr);
			l >>= 1; r >>= 1;
		}

		return OperatorMonoid::op(sml, smr);
	}

	T all_get() { return d[1]; }

	void set(int p, T x) // d[p] = x
	{
		p += n;
		for (int i = log; i >= 1; i--) push(p >> i);
		d[p] = x;
		for (int i = 1; i <= log; i++) update(p >> i);
	}

	void apply(int p, F f)  // d[p] = f(d[p])
	{
		p += n;
		for (int i = log; i >= 1; i--) push(p >> i);
		d[p] = OperatorMonoid::mapping(f, d[p]);
		for (int i = 1; i <= log; i++) update(p >> i);
	}

	void apply(int l, int r, F f) // [l, r) d[i] = f(d[i])
	{
		if (l == r) return;

		l += n; r += n;

		for (int i = log; i >= 1; i--) {
			if (((l >> i) << i) != l) push(l >> i);
			if (((r >> i) << i) != r) push((r - 1) >> i);
		}

		{
			int l2 = l, r2 = r;
			while (l < r) {
				if (l & 1) all_apply(l++, f);
				if (r & 1) all_apply(--r, f);
				l >>= 1;
				r >>= 1;
			}
			l = l2;
			r = r2;
		}

		for (int i = 1; i <= log; i++) {
			if (((l >> i) << i) != l) update(l >> i);
			if (((r >> i) << i) != r) update((r - 1) >> i);
		}
	}
};