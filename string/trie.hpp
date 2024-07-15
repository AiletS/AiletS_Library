#pragma once

/*
Trie木 Trie<sigma> trie;
sigmaは文字の個数
int add(STRING s, int off = 'a')
*/
template <int sigma = 26>
struct Trie
{
    int n_node;
    vector<array<int, sigma>> nodes;
    vector<int> parent;
    vector<int> words; // add された単語が何番の頂点で完成されたか

    Trie() : n_node(0) { create_node(); }
    const array<int, sigma>& operator [](int x) const { return nodes[x]; }

    template <typename STRING>
    int add(STRING s, int off = 'a')
    {
        int id = 0;
        for(auto& p : s)
        {
            int q = p - off;
            assert(0 <= q && q < sigma);
            if(nodes[id][q] == -1) // その文字が見つからなかった
            {
                nodes[id][q] = create_node();
                parent.back() = id;
            }
            id = nodes[id][q];
        }
        words.emplace_back(id);
        return id;
    }

private:
    int create_node()
    {
        nodes.emplace_back(array<int, sigma>());
        fill(nodes.back().begin(), nodes.back().end(), -1);
        parent.emplace_back(-1);
        return n_node++;
    }
};