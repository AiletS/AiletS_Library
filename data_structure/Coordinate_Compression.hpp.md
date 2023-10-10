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

座標圧縮をしてくれるライブラリです。

# コンストラクタ
```
 CC<T> cc
```

- 型 `T` (指定しない時、`long long` になります)

から宣言します。これによって、

- 空配列 `v` が作られます。
- 座標圧縮の状態を持つ bool 変数 `in` が作られます。


#### 計算量

- $\mathcal{O}(1)$

## add

```
void cc.add(T x)
```


配列 `v` に `x` を追加します。

#### 計算量

- $\mathcal{O}(1)$


## init

```
void cc.init()
```


現在の配列 `v` に対して、座標圧縮を行います。

#### 計算量

$N$ を `v` のサイズとして、

- $\mathcal{O}(N\log N)$

## operator()

```
int cc(T x)
```


`v` が座標圧縮されていない状態なら `cc.init()`を最初に行います。

`x` が `v` の何番目にあるかを返します。

#### 計算量

$N$ を `v` のサイズとして、

- $\mathcal{O}(\log N)$

## operator[]

```
T cc[int i]
```

`v` が座標圧縮されていない状態なら `cc.init()`を最初に行います。

`v` の `i` 番目の要素を返します。

#### 制約

$N$ を `v` のサイズとして、

- $0\leq i<N$

#### 計算量

- $\mathcal{O}(1)$

## size

```
int cc.size()
```


`v` が座標圧縮されていない状態なら `cc.init()`を最初に行います。

`v` のサイズを返します。

#### 計算量

- $\mathcal{O}(1)$

<details>
<summary>使用例</summary>

```cpp
int main()
{
    CC cc; // 宣言
    cc.add(2);
    cc.add(8);
    cc.add(4);
    cc.add(4);
    // cc.init() してもしなくてもいい
    // 現在 v = {2, 4, 8}
    cout << cc(4); // 1
    cout << cc[1]; // 4
    cout << cc.size(); // 3
    cc.add(3);
    // 現在 v = {2, 3, 4, 8}
    cout << cc(4); // 2
    cout << cc[1]; // 3
    cout << cc.size(); // 4
}
```
</details>

