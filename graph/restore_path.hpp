#pragma once

/*
経路復元
dist_bfs, dist_dijkstraなどの par が必要
*/
vector<int> restore_path(vector<int> par, int t)
{
    vector<int> res = { t };
    while(par[res.back()] != -1) res.push_back(par[res.back()]);
    reverse(res.begin(), res.end());
    return res;
}