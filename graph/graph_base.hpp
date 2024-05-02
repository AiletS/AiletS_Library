#pragma once

template <typename T>
struct Edge
{
    int from, to;
    T cost;
    int id;
    Edge(int from, int to, T cost, int id) : from(from), to(to), cost(cost), id(id) {}
};

/*
Graph ライブラリ
Graph<T = long long, directed = false> (int n) : n 個の頂点を持つグラフ
T は重みの型、directedは有向が無向か false なら無向
operator[] が定義されている G[x] : x の隣接リスト
add(int from, int to, T cost = 1, int id = -1) 辺を追加する
mkg(int m, bool weighted = false, int off = 1) 入力からグラフを作る m は変数 off-index
mkg_ancestor(bool weighted = false, int off = 1) n-1辺のグラフを入力から作る
*/
template <typename T = long long, bool directed = false>
struct Graph
{
    using cost_type = T;
    int n, m;
    vector<vector<Edge<T>>> G;
    vector<Edge<T>> edges;
    vector<int> in_deg, out_deg;

    Graph() {}
    Graph(int N) 
    {
        n = N; m = 0;
        G = vector<vector<Edge<T>>>(N);
        in_deg = vector<int>(N, 0);
        out_deg = vector<int>(N, 0);
    }

    vector<Edge<T>> operator[](int x) const { return G[x]; }

    void add(int from, int to, T cost = 1, int id = -1)\
    {
        if(id == -1) id = m++;
        G[from].emplace_back(from, to, cost, id);
        edges.emplace_back(from, to, cost, id);
        out_deg[from]++, in_deg[to]++;
        if(directed == false) 
        {
            G[to].emplace_back(to, from, cost, id);
            out_deg[to]++, in_deg[from]++;
        }
    }

    void mkg(int M, bool weighted = false, int off = 1)
    {
        for(int i = 0; i < M; i++)
        {
            int x, y; cin >> x >> y;
            x -= off, y -= off;
            if(weighted == false) add(x, y);
            else { T z; cin >> z; add(x, y, z); }
        }
    }

    void mkg_ancestor(bool weighted = false, int off = 1)
    {
        for(int i = 1; i < n; i++)
        {
            int x; cin >> x; x -= off;
            if(weighted == false) add(x, i);
            else { T z; cin >> z; add(x, i, z); }
        }
    }
};