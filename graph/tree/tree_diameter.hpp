#pragma once

#include "graph/tree/tree_base.hpp"
#include "graph/dist_bfs.hpp"
#include "graph/restore_path.hpp"

/*
木の直径を求める
[直径の距離, 直径を成すパス]を返す
*/
template <class TREE, typename T = long long>
pair<T, vector<int>> tree_diameter(TREE& tree)
{
    vector<int> path;
    int s, t;
    auto [dist1, par1] = dist_bfs<T>(tree, tree.root);
    s = max_element(dist1.begin(), dist1.end()) - dist1.begin();
    auto [dist2, par2] = dist_bfs<T>(tree, s);
    t = max_element(dist2.begin(), dist2.end()) - dist2.begin();
    path = restore_path(par2, t);

    return { dist2[t], path };
}