#pragma once

/*
Weighted_UnionFind<T = long long>(int n, T off = 0) : 重みは最初 off のサイズ n で生成
find(int x) x の代表を取得
weight(int x) x が含まれているグループの重みを取得
unite(int x, int y, T weight) x, y を重みが y - x = weight になるように結合
same(int x, int y) x, y が同じグループであるかを取得
group() 現在のグループの個数を取得
size(int x) x が含まれているグループのサイズを取得
diff(int x, int y) 重みの差 weight(y) - weight(x) を取得
*/
template <class T = long long>
class Weighted_UnionFind
{
  private:
    vector<int> par, rk, SIZE;
    vector<T> w;
    int gr;

  public:
    Weighted_UnionFind(int n, T off = 0) : gr(n), par(n), rk(n, 0), SIZE(n, 1), w(n, off) // initialize
    {
        iota(par.begin(), par.end(), 0);
    }

    int find(int x) // find parent
    {
        if (par[x] == x) return x;
        else { int r = find(par[x]); w[x] += w[par[x]]; return par[x] = r; }
    }

    T weight(int x) { find(x); return w[x]; }

    bool unite(int x, int y, T _weight) // unite two nodes, y - x = _weight
    {
        _weight += weight(x); _weight -= weight(y);
        x = find(x), y = find(y);
        if (x == y) return diff(x, y) == _weight;

        gr--;
        if(rk[x] < rk[y]) swap(x, y) , _weight = -_weight;
        if(rk[x] == rk[y]) rk[x]++;
        par[y] = x; SIZE[x] += SIZE[y];
        w[y] = _weight;
        return true;
    }

    bool same(int x, int y) { return find(x) == find(y); }
    // judge two nodes' parents are the same

    int group() { return gr; }
    // total number of connectivity components

    int size(int x) { return SIZE[find(x)]; }
    // number of nodes in the connection component containing x

    T diff(int x, int y) { return weight(y) - weight(x); }
    // return weight(y - x)
};
