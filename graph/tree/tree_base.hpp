#pragma once

template <typename T>
struct Edge
{
    int from, to;
    T cost;
    int id;
    Edge(int from, int to, T cost, int id) : from(from), to(to), cost(cost), id(id) {}
};

template <typename T = long long, bool directed = false>
struct Tree
{
    using cost_type = T;
    int n, m, root;
    vector<vector<Edge<T>>> G;
    vector<Edge<T>> edges;
    vector<int> in_deg, out_deg;

    Tree() {}
    Tree(int N, int ROOT = 0) 
    {
        n = N; m = 0, root = ROOT;
        G = vector<vector<Edge<T>>>(N);
        in_deg = vector<int>(N, 0);
        out_deg = vector<int>(N, 0);
    }

    vector<Edge<T>> operator[](int x) const { return G[x]; }

    void add(int from, int to, T cost = 1, int id = -1)
    {
        assert(from >= 0 && from < n && to >= 0 && to < n);
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

    void mkg(bool weighted = false, int off = 1)
    {
        for(int i = 0; i < n - 1; i++)
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