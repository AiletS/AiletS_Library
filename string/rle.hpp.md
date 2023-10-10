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
  bundledCode: "#line 2 \"string/rle.hpp\"\n\ntemplate <typename STRING = string,\
    \ typename CHAR = char>\nvector<pair<CHAR, int>> rle(STRING s) {\n\tvector<pair<CHAR,\
    \ int>> res;\n\tfor (CHAR c : s) {\n\t\tif (!res.empty() && c == res.back().first)\
    \ {\n\t\t\tres.back().second += 1;\n\t\t}\n\t\telse {\n\t\t\tres.emplace_back(c,\
    \ 1);\n\t\t}\n\t}\n\treturn res;\n}\n"
  code: "#pragma once\n\ntemplate <typename STRING = string, typename CHAR = char>\n\
    vector<pair<CHAR, int>> rle(STRING s) {\n\tvector<pair<CHAR, int>> res;\n\tfor\
    \ (CHAR c : s) {\n\t\tif (!res.empty() && c == res.back().first) {\n\t\t\tres.back().second\
    \ += 1;\n\t\t}\n\t\telse {\n\t\t\tres.emplace_back(c, 1);\n\t\t}\n\t}\n\treturn\
    \ res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/rle.hpp
  requiredBy: []
  timestamp: '2023-09-26 16:34:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/rle.hpp
layout: document
redirect_from:
- /library/string/rle.hpp
- /library/string/rle.hpp.html
title: string/rle.hpp
---
