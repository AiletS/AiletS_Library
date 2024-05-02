#pragma once

template<typename T>
int mex(vector<T> &v)
{
    int n = v.size();
    vector<int> check(n + 1, 0);
    for(auto p : v) if(p < check.size()) check[p] |= 1;
    for(int i = 0; i < n + 1; i++) if(check[i] == 0) return i;
}