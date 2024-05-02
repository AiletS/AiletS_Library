#pragma once

#include "graph/graph_base.hpp"

template <class G>
vector<vector<int>> scc(G& g)
{
    int n = g.n, m = g.m;
    const int inf = 1001001001;

    auto get_ids = [&]() -> pair<int, vector<int>>
    {
		int now_ord = 0, now_id = 0;
		vector<int> low(n), ord(n, -1), id(n);
		stack<int> visited;
		auto dfs = [&](auto dfs, int v) -> void
		{
			low[v] = ord[v] = now_ord++;
			visited.push(v);
			for (auto [_, p, __, ___] : g[v])
			{
				if (ord[p] == -1)
				{
					dfs(dfs, p);
					low[v] = min(low[v], low[p]);
				}
				else low[v] = min(low[v], ord[p]);
			}

			if (low[v] == ord[v])
			{
				while (true)
				{
					int u = visited.top(); visited.pop();
					ord[u] = inf;
					id[u] = now_id;
					if (u == v) break;
				}
				now_id++;
			}
		};

		for (int i = 0; i < n; i++)
		{
			if (ord[i] == -1) dfs(dfs, i);
		}
		for (auto& p : id) p = now_id - 1 - p;
		return { now_id, id };
    };

    auto ids = get_ids();
    vector<vector<int>> res(ids.first);
    for(int i = 0; i < n; i++) res[ids.second[i]].push_back(i);
    return res;
}