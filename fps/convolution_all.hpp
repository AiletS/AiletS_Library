#pragma once

#include "fps/fps.hpp"

/*
fps すべてを convolution する
O(n log^2 n) n は項の長さの総和
*/
fps convolution_all(vector<fps>& v)
{
    queue<fps> q;
    for(auto p : v) q.push(p);
    while(q.size() >= 2)
    {
        auto l = q.front(); q.pop();
        auto r = q.front(); q.pop();
        q.push(l * r);
    }
    return q.front();
}