#pragma once

#include "graph/graph_base.hpp"


/*
ダイクストラ法 (dist, pre) の pair を返す
dijkstra<int>(g, 0) のように呼ぶ
*/
template <class T = long long, class GT>
pair<vector<T>, vector<int>> dijkstra(GT& g, int start, T inf_off = 0)
{
    if(inf_off == 0) inf_off = infty<T>;
    const int n = g.n;
    using PT = pair<T, int>;

    vector<T> dist(n, inf_off);
    vector<int> pre(n, -1);

    dist[start] = 0;
    priority_queue<PT, vector<PT>, greater<PT>> q;
    q.emplace(dist[start], start);

    while(q.size())
    {
        auto [d, a] = q.top(); q.pop();
        if(dist[a] < d) continue;
        for(auto p : g[a])
        {
            if(d + p.cost < dist[p.to])
            {
                dist[p.to] = d + p.cost;
                pre[p.to] = a;
                q.emplace(dist[p.to], p.to);
            }
        }
    }
    return { dist, pre };
}