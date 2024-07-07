#pragma once

#include "graph/graph_base.hpp"

/*
グラフからBFSを行う
dist_bfs<T = long long>(G& g, int start, T inf_off = 0)
[dist, par] を返す
inf_off は 0 のとき infty<T>、0 ではないとき最大値を任意に設定
*/
template <class T = long long, class G>
pair<vector<T>, vector<int>> dist_bfs(G& g, int start, T inf_off = 0)
{
    if(inf_off == 0) inf_off = infty<T>;
    vector<T> dist(g.n, inf_off); dist[start] = 0;
    vector<int> par(g.n, -1);
    queue<T> q; q.push(start);
    while(q.size())
    {
        int a = q.front(); q.pop();
        for(auto p : g[a])
        {
            if(dist[a] + p.cost < dist[p.to])
            {
                dist[p.to] = dist[a] + p.cost;
                par[p.to] = p.from;
                q.push(p.to);
            }
        }
    }
    return { dist, par };
}

/*
グラフからBFSを行う(多点スタート)
dist_bfs<T = long long>(G& g, int start, T inf_off = 0)
[dist, par, root] を返す
root はその頂点がどこの頂点からきたか
inf_off は 0 のとき infty<T>、0 ではないとき最大値を任意に設定
*/
template <class T = long long, class G>
tuple<vector<T>, vector<int>, vector<int>> dist_bfs(G& g, vector<int>& starts, T inf_off = 0)
{
    if(inf_off == 0) inf_off = infty<T>;
    vector<T> dist(g.n, inf_off);
    vector<int> par(g.n, -1), root(g.n, -1);
    queue<T> q;
    for(auto p : starts) dist[p] = 0, q.push(p), root[p] = p;

    while(q.size())
    {
        int a = q.front(); q.pop();
        for(auto p : g[a])
        {
            if(dist[a] + p.cost < dist[p.to])
            {
                dist[p.to] = dist[a] + p.cost;
                par[p.to] = p.from;
                root[p.to] = root[p.from];
                q.push(p.to);
            }
        }
    }
    return { dist, par, root };
}