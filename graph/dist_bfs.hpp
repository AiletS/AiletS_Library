#pragma once

#include "graph/graph_base.hpp"

/*
グラフからBFSを行う
dist_bfs<T = long long>(G& g, int start, T inf_off = 0)
startからの距離 vector<T> を返す
inf_off は 0 のとき infty<T>、0 ではないとき最大値を任意に設定
*/
template <class T = long long, class G>
vector<T> dist_bfs(G& g, int start, T inf_off = 0)
{
    if(inf_off == 0) inf_off = infty<T>;
    vector<T> dist(g.n, inf_off); dist[start] = 0;
    queue<T> q; q.push(start);
    while(q.size())
    {
        int a = q.front(); q.pop();
        for(auto p : g[a])
        {
            if(dist[a] + p.cost < dist[p.to])
            {
                dist[p.to] = dist[a] + p.cost;
                q.push(p.to);
            }
        }
    }
    return dist;
}

/*
グラフからBFSを行う(多点スタート)
dist_bfs<T = long long>(G& g, int start, T inf_off = 0)
vector<int> startからの距離 vector<T> を返す
inf_off は 0 のとき infty<T>、0 ではないとき最大値を任意に設定
*/
template <class T = long long, class G>
vector<T> dist_bfs(G& g, vector<int>& starts, T inf_off = 0)
{
    if(inf_off == 0) inf_off = infty<T>;
    vector<T> dist(g.n, inf_off); 
    queue<T> q;
    for(auto p : starts) dist[p] = 0, q.push(p);
    
    while(q.size())
    {
        int a = q.front(); q.pop();
        for(auto p : g[a])
        {
            if(dist[a] + p.cost < dist[p.to])
            {
                dist[p.to] = dist[a] + p.cost;
                q.push(p.to);
            }
        }
    }
    return dist;
}