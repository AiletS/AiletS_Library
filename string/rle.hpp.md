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
  bundledCode: "#line 2 \"string/rle.hpp\"\ntemplate <typename STRING = string, typename\
    \ CHAR = char>\nvector<pair<CHAR, int>> rle(STRING s) {\n\tvector<pair<CHAR, int>>\
    \ res;\n\tfor (CHAR c : s) {\n\t\tif (!res.empty() && c == res.back().first) res.back().second\
    \ += 1;\n\t\telse res.emplace_back(c, 1);\n\t}\n\treturn res;\n}\n"
  code: "#pragma once\ntemplate <typename STRING = string, typename CHAR = char>\n\
    vector<pair<CHAR, int>> rle(STRING s) {\n\tvector<pair<CHAR, int>> res;\n\tfor\
    \ (CHAR c : s) {\n\t\tif (!res.empty() && c == res.back().first) res.back().second\
    \ += 1;\n\t\telse res.emplace_back(c, 1);\n\t}\n\treturn res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/rle.hpp
  requiredBy: []
  timestamp: '2024-05-03 01:19:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/rle.hpp
layout: document
redirect_from:
- /library/string/rle.hpp
- /library/string/rle.hpp.html
title: string/rle.hpp
---
