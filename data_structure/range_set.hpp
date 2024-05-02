#pragma once


/*
range_set
range_set<T = long long>()
bool covered(T l, T r) [l, r) がカバーされているか
pair<T, T> covered_by(T l, T r) [l, r) がカバーされている区間を返す
T insert(T l, T r) [l, r) を挿入する。増加分を返す
T erase(T l, T r) [l, r) を消す。減少分を返す
int size() 区間の個数を返す
T mex(T x = 0) mex を返す
T sum_all() すべての区間の和(絶対値)を返す
set<pair<T, T>> get() 区間(set)をそのまま返す
void dump() デバッグ用
*/
template <class T = long long>
class range_set
{
  private:
    const T inf = infty<T>;
    T sum;
    set<pair<T, T>> S;
  public:
    range_set() : sum(0)
    {   // [-inf, -inf) ... [inf, inf)
        S.emplace(-inf, -inf);
        S.emplace(inf, inf);
    }

    // [l, r) is covered?
    bool covered(const T l, const T r)
    {
        assert(l <= r);
        if(l == r) return true;
        auto itr = prev(S.upper_bound({l, inf}));
        return itr->first <= l && r <= itr->second;
    }

    // return section which covers[l, r)
    // if not exists, return [-inf, inf)
    pair<T, T> covered_by(const T l, const T r)
    {
        assert(l <= r);
        if(l == r) return {-inf, -inf};
        auto itr = prev(S.upper_bound({l, inf}));
        if(itr->first <= l && r <= itr->second) return *itr;
        return {-inf, -inf};
    }

    // insert[l, r), and return increment
    T insert(T l, T r)
    {
        assert(l <= r);
        if(l == r) return T(0);
        auto itr = prev(S.upper_bound({l, inf}));
        if(itr->first <= l && r <= itr->second) return T(0);
        T sum_erased = T(0);
        if(itr->first <= l && l <= itr->second)
        {
            l = itr->first;
            sum_erased += itr->second - itr->first;
            itr = S.erase(itr);
        }
        else itr = next(itr);
        while(r > itr->second)
        {
            sum_erased += itr->second - itr->first;
            itr = S.erase(itr);
        }
		if(itr->first <= r) 
        {
			sum_erased += itr->second - itr->first;
			r = itr->second;
			S.erase(itr);
		}
		S.emplace(l, r);
		sum += r - l - sum_erased;
		return r - l - sum_erased;
    }

    // erase [l, r), and return decrement
	T erase(const T l, const T r) 
    {
		assert(l <= r);
		if(l == r) return T(0);
		auto itr = prev(S.upper_bound({l, inf}));
		if(itr->first <= l and r <= itr->second) 
        {
			if(itr->first < l) S.emplace(itr->first, l);
			if(r < itr->second) S.emplace(r, itr->second);
			S.erase(itr);
			sum -= r - l;
			return r - l;
		}
		T ret = T(0);
		if(itr->first <= l and l < itr->second) 
        {
			ret += itr->second - l;
			if(itr->first < l) S.emplace(itr->first, l);
			itr = S.erase(itr);
		} 
        else itr = next(itr);
		while(itr->second <= r) 
        {
			ret += itr->second - itr->first;
			itr = S.erase(itr);
		}
		if(itr->first < r) 
        {
			ret += r - itr->first;
			S.emplace(r, itr->second);
			S.erase(itr);
		}
		sum -= ret;
		return ret;
	}

    int size() const { return (int)S.size() - 2; }

    
	T mex(const T x = 0) const 
    {
		auto itr = prev(S.upper_bound({x, inf}));
		if(itr->first <= x and x < itr->second)
			return itr->second;
		else
			return x;
	}

    T sum_all() const { return sum; }

    // get set
	set<pair<T, T>> get() const 
    {
		set<pair<T, T>> res;
		for(auto &p : S) {
			if(abs(p.first) == inf) continue;
			res.emplace(p.first, p.second);
		}
		return res;
	}

    // debug
	void dump() const 
    {
		cout << "range_set:";
		for(auto &p : S) {
			if(abs(p.first) == inf) continue;
			cout << "[" << p.first << "," << p.second << "),";
		}
		cout << '\n';
	}
};