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
redirect_from:
- /library/data_structure/Coordinate_Compression.hpp
- /library/data_structure/Coordinate_Compression.hpp.html
title: data_structure/Coordinate_Compression.hpp
---
