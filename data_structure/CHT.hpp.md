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
  bundledCode: "#line 2 \"data_structure/CHT.hpp\"\n\n/*\nconvex-hull trick\nvoid\
    \ add(T a, T b) \u76F4\u7DDA ax + b \u3092\u8FFD\u52A0\nT get(T x) \u6700\u5C0F\
    \u5024\u3092\u8FD4\u3059\n*/\ntemplate <typename T>\nstruct CHT\n{\n    map<T,\
    \ T> line, ator, rtoa;\n    CHT() {}\n\n    // \u50BE\u304D l > r \u3067\u76F4\
    \u7DDA l \u304C\u76F4\u7DDA r \u3088\u308A\u4E0B\u306B\u3042\u308B\u306E\u306F\
    \n    T f(T l, T r)\n    {\n        // alx + bl <= arx + br\n        return (line[r]\
    \ - line[l]) / (l - r);\n    }\n\n    void add(T a, T b)\n    {\n        // \u521D\
    \u3081\u3066\u306E\u76F4\u7DDA\u306E\u3068\u304D\n        if(line.empty())\n \
    \       {\n            line[a] = b, ator[a] = infty<T>, rtoa[infty<T>] = a;\n\
    \            return;\n        }\n\n        // \u65E2\u306B\u540C\u3058\u50BE\u304D\
    \u306E\u76F4\u7DDA\u304C\u5B58\u5728\u3059\u308B\u3068\u304D\n        if(line.find(a)\
    \ != line.end()) line[a] = min(line[a], b);\n        // \u76F4\u7DDA ax + b \u304C\
    \u5FC5\u8981\u304C\u5224\u5B9A\u3059\u308B\n        // \u3082\u3057 a \u304C\u4ECA\
    \u307E\u3067\u306E\u76F4\u7DDA\u3067\u6700\u5C0F\u5024\u304B\u6700\u5927\u5024\
    \u306E\u3068\u304D\u306F\u8FFD\u52A0\n        else if(a < line.begin()->first\
    \ || a > line.rbegin()->first) line[a] = b;\n        else // \u305D\u308C\u4EE5\
    \u5916\u306F\u8981\u78BA\u8A8D al > a > ar\n        {\n            line[a] = b;\n\
    \            auto itr = line.find(a);\n            if(f(next(itr)->first, a) >=\
    \ f(a, prev(itr)->first)) { line.erase(a); return; }\n        }\n\n\n        //\
    \ \u76F4\u7DDA\u306E\u8FFD\u52A0\u306B\u3088\u3063\u3066\u4E0D\u8981\u306B\u306A\
    \u3063\u305F\u76F4\u7DDA\u3092\u524A\u9664\u3059\u308B\n        // \u5DE6\u5074\
    \ all > al > a\n        while(1)\n        {\n            auto itr = line.find(a),\
    \ itrl = next(itr); if(itrl == line.end()) break;\n            auto itrll = next(itrl);\
    \ if(itrll == line.end()) break;\n            if(f(itrll->first, itrl->first)\
    \ >= f(itrl->first, a))\n            {\n                T x = itrl->first, y =\
    \ ator[x];\n                line.erase(x), ator.erase(x), rtoa.erase(y);\n   \
    \         }\n            else break;\n        }\n        // \u53F3\u5074 a > ar\
    \ > arr\n        while(1)\n        {\n            auto itr = line.find(a); if(itr\
    \ == line.begin()) break;\n            auto itrr = prev(itr); if(itrr == line.begin())\
    \ break;\n            auto itrrr = prev(itrr);\n            if(f(a, itrr->first)\
    \ >= f(itrr->first, itrrr->first))\n            {\n                T x = itrr->first,\
    \ y = ator[x];\n                line.erase(x), ator.erase(x), rtoa.erase(y);\n\
    \            }\n            else break;\n        }\n\n        // \u533A\u9593\u3092\
    \u66F4\u65B0\u3059\u308B al > a > ar\n        auto itr = line.find(a);\n     \
    \   if(next(itr) != line.end())\n        {\n            T l = next(itr)->first;\n\
    \            T x = f(l, a); rtoa.erase(ator[l]);\n            ator[l] = x, rtoa[x]\
    \ = l;\n        }\n        if(itr != line.begin())\n        {\n            T r\
    \ = prev(itr)->first;\n            T x = f(a, r);\n            ator[a] = x, rtoa[x]\
    \ = a;\n        }\n        if(itr == line.begin())\n        {\n            ator[a]\
    \ = infty<T>, rtoa[infty<T>] = a;\n        }\n    }\n\n    T get(T x)\n    {\n\
    \        T a = rtoa.lower_bound(x)->second;\n        return a * x + line[a];\n\
    \    }\n\n    void dump()\n    {\n        cout << \"==========line==========\"\
    \ << '\\n';\n        for(auto [x, y] : line) cout << x << \"x + \" << y << '\\\
    n';\n        cout << \"==========ator==========\" << '\\n';\n        for(auto\
    \ [x, y] : ator) cout << x << \" : \" << y << '\\n';\n        cout << \"==========rtoa==========\"\
    \ << '\\n';\n        for(auto [x, y] : rtoa) cout << x << \" : \" << y << '\\\
    n';  \n        cout << \"==========-----END-----==========\" << '\\n' << '\\n';\
    \      \n    }\n};\n"
  code: "#pragma once\n\n/*\nconvex-hull trick\nvoid add(T a, T b) \u76F4\u7DDA ax\
    \ + b \u3092\u8FFD\u52A0\nT get(T x) \u6700\u5C0F\u5024\u3092\u8FD4\u3059\n*/\n\
    template <typename T>\nstruct CHT\n{\n    map<T, T> line, ator, rtoa;\n    CHT()\
    \ {}\n\n    // \u50BE\u304D l > r \u3067\u76F4\u7DDA l \u304C\u76F4\u7DDA r \u3088\
    \u308A\u4E0B\u306B\u3042\u308B\u306E\u306F\n    T f(T l, T r)\n    {\n       \
    \ // alx + bl <= arx + br\n        return (line[r] - line[l]) / (l - r);\n   \
    \ }\n\n    void add(T a, T b)\n    {\n        // \u521D\u3081\u3066\u306E\u76F4\
    \u7DDA\u306E\u3068\u304D\n        if(line.empty())\n        {\n            line[a]\
    \ = b, ator[a] = infty<T>, rtoa[infty<T>] = a;\n            return;\n        }\n\
    \n        // \u65E2\u306B\u540C\u3058\u50BE\u304D\u306E\u76F4\u7DDA\u304C\u5B58\
    \u5728\u3059\u308B\u3068\u304D\n        if(line.find(a) != line.end()) line[a]\
    \ = min(line[a], b);\n        // \u76F4\u7DDA ax + b \u304C\u5FC5\u8981\u304C\u5224\
    \u5B9A\u3059\u308B\n        // \u3082\u3057 a \u304C\u4ECA\u307E\u3067\u306E\u76F4\
    \u7DDA\u3067\u6700\u5C0F\u5024\u304B\u6700\u5927\u5024\u306E\u3068\u304D\u306F\
    \u8FFD\u52A0\n        else if(a < line.begin()->first || a > line.rbegin()->first)\
    \ line[a] = b;\n        else // \u305D\u308C\u4EE5\u5916\u306F\u8981\u78BA\u8A8D\
    \ al > a > ar\n        {\n            line[a] = b;\n            auto itr = line.find(a);\n\
    \            if(f(next(itr)->first, a) >= f(a, prev(itr)->first)) { line.erase(a);\
    \ return; }\n        }\n\n\n        // \u76F4\u7DDA\u306E\u8FFD\u52A0\u306B\u3088\
    \u3063\u3066\u4E0D\u8981\u306B\u306A\u3063\u305F\u76F4\u7DDA\u3092\u524A\u9664\
    \u3059\u308B\n        // \u5DE6\u5074 all > al > a\n        while(1)\n       \
    \ {\n            auto itr = line.find(a), itrl = next(itr); if(itrl == line.end())\
    \ break;\n            auto itrll = next(itrl); if(itrll == line.end()) break;\n\
    \            if(f(itrll->first, itrl->first) >= f(itrl->first, a))\n         \
    \   {\n                T x = itrl->first, y = ator[x];\n                line.erase(x),\
    \ ator.erase(x), rtoa.erase(y);\n            }\n            else break;\n    \
    \    }\n        // \u53F3\u5074 a > ar > arr\n        while(1)\n        {\n  \
    \          auto itr = line.find(a); if(itr == line.begin()) break;\n         \
    \   auto itrr = prev(itr); if(itrr == line.begin()) break;\n            auto itrrr\
    \ = prev(itrr);\n            if(f(a, itrr->first) >= f(itrr->first, itrrr->first))\n\
    \            {\n                T x = itrr->first, y = ator[x];\n            \
    \    line.erase(x), ator.erase(x), rtoa.erase(y);\n            }\n           \
    \ else break;\n        }\n\n        // \u533A\u9593\u3092\u66F4\u65B0\u3059\u308B\
    \ al > a > ar\n        auto itr = line.find(a);\n        if(next(itr) != line.end())\n\
    \        {\n            T l = next(itr)->first;\n            T x = f(l, a); rtoa.erase(ator[l]);\n\
    \            ator[l] = x, rtoa[x] = l;\n        }\n        if(itr != line.begin())\n\
    \        {\n            T r = prev(itr)->first;\n            T x = f(a, r);\n\
    \            ator[a] = x, rtoa[x] = a;\n        }\n        if(itr == line.begin())\n\
    \        {\n            ator[a] = infty<T>, rtoa[infty<T>] = a;\n        }\n \
    \   }\n\n    T get(T x)\n    {\n        T a = rtoa.lower_bound(x)->second;\n \
    \       return a * x + line[a];\n    }\n\n    void dump()\n    {\n        cout\
    \ << \"==========line==========\" << '\\n';\n        for(auto [x, y] : line) cout\
    \ << x << \"x + \" << y << '\\n';\n        cout << \"==========ator==========\"\
    \ << '\\n';\n        for(auto [x, y] : ator) cout << x << \" : \" << y << '\\\
    n';\n        cout << \"==========rtoa==========\" << '\\n';\n        for(auto\
    \ [x, y] : rtoa) cout << x << \" : \" << y << '\\n';  \n        cout << \"==========-----END-----==========\"\
    \ << '\\n' << '\\n';      \n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/CHT.hpp
  requiredBy: []
  timestamp: '2024-06-17 21:21:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/CHT.hpp
layout: document
redirect_from:
- /library/data_structure/CHT.hpp
- /library/data_structure/CHT.hpp.html
title: data_structure/CHT.hpp
---
