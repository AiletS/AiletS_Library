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
  bundledCode: "#line 2 \"string/zalgo.hpp\"\n\nstruct Zalgo\n{\n\tvector<int> z;\n\
    \tZalgo() {}\n\tZalgo(const string& s) : z(s.size())\n\t{\n\t\tz[0] = s.size();\n\
    \t\tint l = 0, r = 0;\n\t\tfor (int i = 1; i < s.size(); i++)\n\t\t{\n\t\t\tif\
    \ (i > r)\n\t\t\t{\n\t\t\t\tl = r = i;\n\t\t\t\twhile (r < s.size() && s[r - l]\
    \ == s[r]) r++;\n\t\t\t\tz[i] = r - l;\n\t\t\t\tr--;\n\t\t\t}\n\t\t\telse\n\t\t\
    \t{\n\t\t\t\tint k = i - l;\n\t\t\t\tif (z[k] < r - i + 1) z[i] = z[k];\n\t\t\t\
    \telse\n\t\t\t\t{\n\t\t\t\t\tl = i;\n\t\t\t\t\twhile (r < s.size() && s[r - l]\
    \ == s[r]) r++;\n\t\t\t\t\tz[i] = r - l;\n\t\t\t\t\tr--;\n\t\t\t\t}\n\t\t\t}\n\
    \t\t}\n\t}\n\tint operator[](int i) { return z[i]; }\n};\n"
  code: "#pragma once\n\nstruct Zalgo\n{\n\tvector<int> z;\n\tZalgo() {}\n\tZalgo(const\
    \ string& s) : z(s.size())\n\t{\n\t\tz[0] = s.size();\n\t\tint l = 0, r = 0;\n\
    \t\tfor (int i = 1; i < s.size(); i++)\n\t\t{\n\t\t\tif (i > r)\n\t\t\t{\n\t\t\
    \t\tl = r = i;\n\t\t\t\twhile (r < s.size() && s[r - l] == s[r]) r++;\n\t\t\t\t\
    z[i] = r - l;\n\t\t\t\tr--;\n\t\t\t}\n\t\t\telse\n\t\t\t{\n\t\t\t\tint k = i -\
    \ l;\n\t\t\t\tif (z[k] < r - i + 1) z[i] = z[k];\n\t\t\t\telse\n\t\t\t\t{\n\t\t\
    \t\t\tl = i;\n\t\t\t\t\twhile (r < s.size() && s[r - l] == s[r]) r++;\n\t\t\t\t\
    \tz[i] = r - l;\n\t\t\t\t\tr--;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\tint operator[](int\
    \ i) { return z[i]; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/zalgo.hpp
  requiredBy: []
  timestamp: '2024-05-03 01:16:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/zalgo.hpp
layout: document
redirect_from:
- /library/string/zalgo.hpp
- /library/string/zalgo.hpp.html
title: string/zalgo.hpp
---
