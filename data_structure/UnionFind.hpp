#pragma once

/* 
UnionFind
Unionfind(int n) サイズ n で生成
find(int x) x の代表を取得
unite(int x, int y) x, y を結合
same(int x, int y) x, y が同じグループであるかを取得
group() 現在のグループの個数を取得
size(int x) x が含まれているグループのサイズを取得
*/
struct UnionFind
{
	UnionFind(int n) : gr(n), par(n), rk(n, 0), SIZE(n, 1) // initialize
	{
		iota(par.begin(), par.end(), 0);
	}

	int find(int x) // find parent
	{
		if (par[x] == x) return x;
		else return par[x] = find(par[x]);
	}

	bool unite(int x, int y) // unite two nodes
	{
		x = find(x), y = find(y);
		if (x == y) return false;

		gr--;
		if (rk[x] < rk[y]) { par[x] = y, SIZE[y] += SIZE[x]; }
		else
		{
			par[y] = x; SIZE[x] += SIZE[y];
			if (rk[x] == rk[y]) rk[x]++;
		}
		return true;
	}

	bool same(int x, int y) { return find(x) == find(y); }
	// judge two nodes' parents are the same

	int group() { return gr; }
	// total number of connectivity components

	int size(int x) { return SIZE[find(x)]; }
	// number of nodes in the connection component containing x  

private:
	vector<int> par, rk, SIZE;
	int gr;
};
