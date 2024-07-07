---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/tree/tree_diameter.hpp
    title: graph/tree/tree_diameter.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/restore_path.hpp\"\n\n/*\n\u7D4C\u8DEF\u5FA9\u5143\
    \ndist_bfs, dist_dijkstra\u306A\u3069\u306E par \u304C\u5FC5\u8981\n*/\nvector<int>\
    \ restore_path(vector<int> par, int t)\n{\n    vector<int> res = { t };\n    while(par[res.back()]\
    \ != -1) res.push_back(par[res.back()]);\n    reverse(res.begin(), res.end());\n\
    \    return res;\n}\n"
  code: "#pragma once\n\n/*\n\u7D4C\u8DEF\u5FA9\u5143\ndist_bfs, dist_dijkstra\u306A\
    \u3069\u306E par \u304C\u5FC5\u8981\n*/\nvector<int> restore_path(vector<int>\
    \ par, int t)\n{\n    vector<int> res = { t };\n    while(par[res.back()] != -1)\
    \ res.push_back(par[res.back()]);\n    reverse(res.begin(), res.end());\n    return\
    \ res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/restore_path.hpp
  requiredBy:
  - graph/tree/tree_diameter.hpp
  timestamp: '2024-07-07 18:01:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/restore_path.hpp
layout: document
redirect_from:
- /library/graph/restore_path.hpp
- /library/graph/restore_path.hpp.html
title: graph/restore_path.hpp
---
