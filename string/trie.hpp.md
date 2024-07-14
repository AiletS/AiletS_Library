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
  bundledCode: "#line 2 \"string/trie.hpp\"\n\n/*\nTrie\u6728 Trie<sigma> trie;\n\
    sigma\u306F\u6587\u5B57\u306E\u500B\u6570\nint add(STRING s, int off = 'a')\n\
    */\ntemplate <int sigma = 26>\nstruct Trie\n{\n    int n_node;\n    vector<array<int,\
    \ sigma>> nodes;\n    vector<int> parent;\n    vector<int> words; // add \u3055\
    \u308C\u305F\u5358\u8A9E\u304C\u4F55\u756A\u306E\u9802\u70B9\u3067\u5B8C\u6210\
    \u3055\u308C\u305F\u304B\n\n    Trie() : n_node(0) { create_node(); }\n    const\
    \ array<int, sigma>& operator [](int x) const { return nodes[x]; }\n\n    template\
    \ <typename STRING>\n    int add(STRING s, int off = 'a')\n    {\n        int\
    \ id = 0;\n        for(auto& p : s)\n        {\n            int q = p - off;\n\
    \            assert(0 <= q && q < sigma);\n            if(nodes[id][q] == -1)\
    \ // \u305D\u306E\u6587\u5B57\u304C\u898B\u3064\u304B\u3089\u306A\u304B\u3063\u305F\
    \n            {\n                nodes[id][q] = create_node();\n             \
    \   parent.back() = id;\n            }\n            id = nodes[id][q];\n     \
    \   }\n        words.emplace_back(id);\n        return id;\n    }\n\nprivate:\n\
    \    int create_node()\n    {\n        nodes.emplace_back(array<int, sigma>());\n\
    \        fill(nodes.back().begin(), nodes.back().end(), -1);\n        parent.emplace_back(-1);\n\
    \        return n_node++;\n    }\n};\n"
  code: "#pragma once\n\n/*\nTrie\u6728 Trie<sigma> trie;\nsigma\u306F\u6587\u5B57\
    \u306E\u500B\u6570\nint add(STRING s, int off = 'a')\n*/\ntemplate <int sigma\
    \ = 26>\nstruct Trie\n{\n    int n_node;\n    vector<array<int, sigma>> nodes;\n\
    \    vector<int> parent;\n    vector<int> words; // add \u3055\u308C\u305F\u5358\
    \u8A9E\u304C\u4F55\u756A\u306E\u9802\u70B9\u3067\u5B8C\u6210\u3055\u308C\u305F\
    \u304B\n\n    Trie() : n_node(0) { create_node(); }\n    const array<int, sigma>&\
    \ operator [](int x) const { return nodes[x]; }\n\n    template <typename STRING>\n\
    \    int add(STRING s, int off = 'a')\n    {\n        int id = 0;\n        for(auto&\
    \ p : s)\n        {\n            int q = p - off;\n            assert(0 <= q &&\
    \ q < sigma);\n            if(nodes[id][q] == -1) // \u305D\u306E\u6587\u5B57\u304C\
    \u898B\u3064\u304B\u3089\u306A\u304B\u3063\u305F\n            {\n            \
    \    nodes[id][q] = create_node();\n                parent.back() = id;\n    \
    \        }\n            id = nodes[id][q];\n        }\n        words.emplace_back(id);\n\
    \        return id;\n    }\n\nprivate:\n    int create_node()\n    {\n       \
    \ nodes.emplace_back(array<int, sigma>());\n        fill(nodes.back().begin(),\
    \ nodes.back().end(), -1);\n        parent.emplace_back(-1);\n        return n_node++;\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/trie.hpp
  requiredBy: []
  timestamp: '2024-07-16 01:07:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/trie.hpp
layout: document
redirect_from:
- /library/string/trie.hpp
- /library/string/trie.hpp.html
title: string/trie.hpp
---
