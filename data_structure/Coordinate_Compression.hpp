#pragma once


// Coordinate Comporession (座標圧縮)
// CC<T = long long>(), CC<T = long long>(vector<T> v)
// add(T x) で要素を追加
// operator [i] で圧縮後の i 番目の要素を取得
// operator (i) で圧縮後の i が何番目かを取得
template <typename T = long long>
class CC
{
  public:
	CC() : CC(vector<T>(0)) {}
	CC(const vector<T>& _v)
	{
		is_build = false;
		for(T x : _v) add(x);
	}

	void add(T x) { v.push_back(x); is_build = false; }

	int operator() (T x)
	{
		if (!is_build) init();
		return upper_bound(v.begin(), v.end(), x) - v.begin() - 1;
	}

	T operator[] (int i)
	{
		assert(i >= 0 && i < v.size());
		if (!is_build) init();  return v[i];
	}

	int size()
	{
		if (!is_build) init(); return v.size();
	}

  private:
	bool is_build;
	vector<T> v;
	void init()
	{
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		is_build = true;
	}
};