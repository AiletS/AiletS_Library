---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/Coordinate_Compression.hpp\"\ntemplate <typename\
    \ T = long long>\nstruct CC\n{\n\tbool in;\n\tvector<T> v;\n\tCC() : in(false)\
    \ {}\n\n\tvoid add(T x) { v.push_back(x); in = false; }\n\tvoid init()\n\t{\n\t\
    \tsort(v.begin(), v.end());\n\t\tv.erase(unique(v.begin(), v.end()), v.end());\n\
    \t\tin = true;\n\t}\n\n\tint operator() (T x)\n\t{\n\t\tif (!in) init();\n\t\t\
    return upper_bound(v.begin(), v.end(), x) - v.begin() - 1;\n\t}\n\n\tT operator[]\
    \ (int i)\n\t{\n\t\tif (!in) init();  return v[i];\n\t}\n\n\tint size()\n\t{\n\
    \t\tif (!in) init(); return v.size();\n\t}\n};\n"
  code: "#pragma once\ntemplate <typename T = long long>\nstruct CC\n{\n\tbool in;\n\
    \tvector<T> v;\n\tCC() : in(false) {}\n\n\tvoid add(T x) { v.push_back(x); in\
    \ = false; }\n\tvoid init()\n\t{\n\t\tsort(v.begin(), v.end());\n\t\tv.erase(unique(v.begin(),\
    \ v.end()), v.end());\n\t\tin = true;\n\t}\n\n\tint operator() (T x)\n\t{\n\t\t\
    if (!in) init();\n\t\treturn upper_bound(v.begin(), v.end(), x) - v.begin() -\
    \ 1;\n\t}\n\n\tT operator[] (int i)\n\t{\n\t\tif (!in) init();  return v[i];\n\
    \t}\n\n\tint size()\n\t{\n\t\tif (!in) init(); return v.size();\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/Coordinate_Compression.hpp
  requiredBy: []
  timestamp: '2023-09-05 17:18:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/Coordinate_Compression.hpp
layout: document
title: data_structure/Coordinate_Compression.hpp
---

座標圧縮をしてくれるライブラリです．

`CC<T> cc;` で宣言します．Tはクラス名です．基本は long long になっています．

`cc.add(T x)` T 型の変数 x を座標圧縮対象に入れます．計算量は $\mathcal{O}(1)$

`cc.init()` 座標圧縮を行います．計算量は配列のサイズを $N$ として $\mathcal{O}(N\log N)$

`cc(T x)` T 型の変数 x が座標圧縮した時何番目にあるかを返します．計算量は配列のサイズを $N$ として $\mathcal{O}(\log N)$．もし，座標圧縮されてなかった状態なら `cc.init()` を実行するため，計算量が追加にかかります．

`cc[i]` 座標圧縮した時 i 番目にある値を返します．計算量は $\mathcal{O}(1)$ もし，座標圧縮されてなかった状態なら `cc.init()` を実行するため，計算量が追加にかかります．

`cc.size()` 座標圧縮した時の配列の長さを返します．つまり，重複要素を除いたときのサイズを返します．計算量は $\mathcal{O}(1)$ もし，座標圧縮されてなかった状態なら `cc.init()` を実行するため，計算量が追加にかかります．