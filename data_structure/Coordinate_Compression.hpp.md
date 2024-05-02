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
  bundledCode: "#line 2 \"data_structure/Coordinate_Compression.hpp\"\n\n\n// Coordinate\
    \ Comporession (\u5EA7\u6A19\u5727\u7E2E)\n// CC<T = long long>(), CC<T = long\
    \ long>(vector<T> v)\n// add(T x) \u3067\u8981\u7D20\u3092\u8FFD\u52A0\n// operator\
    \ [i] \u3067\u5727\u7E2E\u5F8C\u306E i \u756A\u76EE\u306E\u8981\u7D20\u3092\u53D6\
    \u5F97\n// operator (i) \u3067\u5727\u7E2E\u5F8C\u306E i \u304C\u4F55\u756A\u76EE\
    \u304B\u3092\u53D6\u5F97\ntemplate <typename T = long long>\nclass CC\n{\n  public:\n\
    \tCC() : CC(vector<T>(0)) {}\n\tCC(const vector<T>& _v)\n\t{\n\t\tis_build = false;\n\
    \t\tfor(T x : _v) v.add(x);\n\t}\n\n\tvoid add(T x) { v.push_back(x); is_build\
    \ = false; }\n\n\tint operator() (T x)\n\t{\n\t\tif (!is_build) init();\n\t\t\
    return upper_bound(v.begin(), v.end(), x) - v.begin() - 1;\n\t}\n\n\tT operator[]\
    \ (int i)\n\t{\n\t\tassert(i >= 0 && i < v.size());\n\t\tif (!is_build) init();\
    \  return v[i];\n\t}\n\n\tint size()\n\t{\n\t\tif (!is_build) init(); return v.size();\n\
    \t}\n\n  private:\n\tbool is_build;\n\tvector<T> v;\n\tvoid init()\n\t{\n\t\t\
    sort(v.begin(), v.end());\n\t\tv.erase(unique(v.begin(), v.end()), v.end());\n\
    \t\tis_build = true;\n\t}\n};\n"
  code: "#pragma once\n\n\n// Coordinate Comporession (\u5EA7\u6A19\u5727\u7E2E)\n\
    // CC<T = long long>(), CC<T = long long>(vector<T> v)\n// add(T x) \u3067\u8981\
    \u7D20\u3092\u8FFD\u52A0\n// operator [i] \u3067\u5727\u7E2E\u5F8C\u306E i \u756A\
    \u76EE\u306E\u8981\u7D20\u3092\u53D6\u5F97\n// operator (i) \u3067\u5727\u7E2E\
    \u5F8C\u306E i \u304C\u4F55\u756A\u76EE\u304B\u3092\u53D6\u5F97\ntemplate <typename\
    \ T = long long>\nclass CC\n{\n  public:\n\tCC() : CC(vector<T>(0)) {}\n\tCC(const\
    \ vector<T>& _v)\n\t{\n\t\tis_build = false;\n\t\tfor(T x : _v) v.add(x);\n\t\
    }\n\n\tvoid add(T x) { v.push_back(x); is_build = false; }\n\n\tint operator()\
    \ (T x)\n\t{\n\t\tif (!is_build) init();\n\t\treturn upper_bound(v.begin(), v.end(),\
    \ x) - v.begin() - 1;\n\t}\n\n\tT operator[] (int i)\n\t{\n\t\tassert(i >= 0 &&\
    \ i < v.size());\n\t\tif (!is_build) init();  return v[i];\n\t}\n\n\tint size()\n\
    \t{\n\t\tif (!is_build) init(); return v.size();\n\t}\n\n  private:\n\tbool is_build;\n\
    \tvector<T> v;\n\tvoid init()\n\t{\n\t\tsort(v.begin(), v.end());\n\t\tv.erase(unique(v.begin(),\
    \ v.end()), v.end());\n\t\tis_build = true;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/Coordinate_Compression.hpp
  requiredBy: []
  timestamp: '2024-05-03 01:16:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/Coordinate_Compression.hpp
layout: document
redirect_from:
- /library/data_structure/Coordinate_Compression.hpp
- /library/data_structure/Coordinate_Compression.hpp.html
title: data_structure/Coordinate_Compression.hpp
---
