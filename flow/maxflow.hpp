#pragma once

struct maxflow // max flow, dinic, O(EV^2)
{
    struct edge
    {
        int to;
        long long cap;
        int rev;
    };
    int n;

    vector<vector<edge>> g;
    vector<int> level;
    vector<int> iter;

    maxflow() : n(0) {}
    maxflow(int n) : n(n), g(n), level(n), iter(n) {}

    void add_edge(int from, int to, long long cap)
    {
        g[from].push_back(edge{ to, cap, (int)g[to].size() });
        g[to].push_back(edge{ from, 0, (int)g[from].size() - 1 });
    }

    void bfs(int s)
    {
        level = vector<int>(n, -1);
        queue<int> q;
        level[s] = 0;
        q.push(s);
        while (q.size())
        {
            int v = q.front(); q.pop();
            for (int i = 0; i < g[v].size(); i++)
            {
                edge& e = g[v][i];
                if (e.cap > 0 && level[e.to] < 0)
                {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }

    int dfs(int v, int t, long long f)
    {
        if (v == t) return f;
        for (int& i = iter[v]; i < g[v].size(); i++)
        {
            edge& e = g[v][i];
            if (e.cap > 0 && level[v] < level[e.to])
            {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0)
                {
                    e.cap -= d;
                    g[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int flow(int s, int t, int limit = 1001001001)
    {
        long long res = 0;
        while(res < limit)
        {
            bfs(s);
            if (level[t] < 0) break;;
            iter = vector<int>(n, 0);
            int f;
            while(res < limit){
                f = dfs(s, t, limit - res);
                if(!f) break;
                res += f;
            }
        }
        return res;
    }
};