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
  bundledCode: "#line 2 \"data_structure/range_set.hpp\"\n\n\n/*\nrange_set\nrange_set<T\
    \ = long long>()\nbool covered(T l, T r) [l, r) \u304C\u30AB\u30D0\u30FC\u3055\
    \u308C\u3066\u3044\u308B\u304B\npair<T, T> covered_by(T l, T r) [l, r) \u304C\u30AB\
    \u30D0\u30FC\u3055\u308C\u3066\u3044\u308B\u533A\u9593\u3092\u8FD4\u3059\nT insert(T\
    \ l, T r) [l, r) \u3092\u633F\u5165\u3059\u308B\u3002\u5897\u52A0\u5206\u3092\u8FD4\
    \u3059\nT erase(T l, T r) [l, r) \u3092\u6D88\u3059\u3002\u6E1B\u5C11\u5206\u3092\
    \u8FD4\u3059\nint size() \u533A\u9593\u306E\u500B\u6570\u3092\u8FD4\u3059\nT mex(T\
    \ x = 0) mex \u3092\u8FD4\u3059\nT sum_all() \u3059\u3079\u3066\u306E\u533A\u9593\
    \u306E\u548C(\u7D76\u5BFE\u5024)\u3092\u8FD4\u3059\nset<pair<T, T>> get() \u533A\
    \u9593(set)\u3092\u305D\u306E\u307E\u307E\u8FD4\u3059\nvoid dump() \u30C7\u30D0\
    \u30C3\u30B0\u7528\n*/\ntemplate <class T = long long>\nclass range_set\n{\n \
    \ private:\n    const T inf = infty<T>;\n    T sum;\n    set<pair<T, T>> S;\n\
    \  public:\n    range_set() : sum(0)\n    {   // [-inf, -inf) ... [inf, inf)\n\
    \        S.emplace(-inf, -inf);\n        S.emplace(inf, inf);\n    }\n\n    //\
    \ [l, r) is covered?\n    bool covered(const T l, const T r)\n    {\n        assert(l\
    \ <= r);\n        if(l == r) return true;\n        auto itr = prev(S.upper_bound({l,\
    \ inf}));\n        return itr->first <= l && r <= itr->second;\n    }\n\n    //\
    \ return section which covers[l, r)\n    // if not exists, return [-inf, inf)\n\
    \    pair<T, T> covered_by(const T l, const T r)\n    {\n        assert(l <= r);\n\
    \        if(l == r) return {-inf, -inf};\n        auto itr = prev(S.upper_bound({l,\
    \ inf}));\n        if(itr->first <= l && r <= itr->second) return *itr;\n    \
    \    return {-inf, -inf};\n    }\n\n    // insert[l, r), and return increment\n\
    \    T insert(T l, T r)\n    {\n        assert(l <= r);\n        if(l == r) return\
    \ T(0);\n        auto itr = prev(S.upper_bound({l, inf}));\n        if(itr->first\
    \ <= l && r <= itr->second) return T(0);\n        T sum_erased = T(0);\n     \
    \   if(itr->first <= l && l <= itr->second)\n        {\n            l = itr->first;\n\
    \            sum_erased += itr->second - itr->first;\n            itr = S.erase(itr);\n\
    \        }\n        else itr = next(itr);\n        while(r > itr->second)\n  \
    \      {\n            sum_erased += itr->second - itr->first;\n            itr\
    \ = S.erase(itr);\n        }\n\t\tif(itr->first <= r) \n        {\n\t\t\tsum_erased\
    \ += itr->second - itr->first;\n\t\t\tr = itr->second;\n\t\t\tS.erase(itr);\n\t\
    \t}\n\t\tS.emplace(l, r);\n\t\tsum += r - l - sum_erased;\n\t\treturn r - l -\
    \ sum_erased;\n    }\n\n    // erase [l, r), and return decrement\n\tT erase(const\
    \ T l, const T r) \n    {\n\t\tassert(l <= r);\n\t\tif(l == r) return T(0);\n\t\
    \tauto itr = prev(S.upper_bound({l, inf}));\n\t\tif(itr->first <= l and r <= itr->second)\
    \ \n        {\n\t\t\tif(itr->first < l) S.emplace(itr->first, l);\n\t\t\tif(r\
    \ < itr->second) S.emplace(r, itr->second);\n\t\t\tS.erase(itr);\n\t\t\tsum -=\
    \ r - l;\n\t\t\treturn r - l;\n\t\t}\n\t\tT ret = T(0);\n\t\tif(itr->first <=\
    \ l and l < itr->second) \n        {\n\t\t\tret += itr->second - l;\n\t\t\tif(itr->first\
    \ < l) S.emplace(itr->first, l);\n\t\t\titr = S.erase(itr);\n\t\t} \n        else\
    \ itr = next(itr);\n\t\twhile(itr->second <= r) \n        {\n\t\t\tret += itr->second\
    \ - itr->first;\n\t\t\titr = S.erase(itr);\n\t\t}\n\t\tif(itr->first < r) \n \
    \       {\n\t\t\tret += r - itr->first;\n\t\t\tS.emplace(r, itr->second);\n\t\t\
    \tS.erase(itr);\n\t\t}\n\t\tsum -= ret;\n\t\treturn ret;\n\t}\n\n    int size()\
    \ const { return (int)S.size() - 2; }\n\n    \n\tT mex(const T x = 0) const \n\
    \    {\n\t\tauto itr = prev(S.upper_bound({x, inf}));\n\t\tif(itr->first <= x\
    \ and x < itr->second)\n\t\t\treturn itr->second;\n\t\telse\n\t\t\treturn x;\n\
    \t}\n\n    T sum_all() const { return sum; }\n\n    // get set\n\tset<pair<T,\
    \ T>> get() const \n    {\n\t\tset<pair<T, T>> res;\n\t\tfor(auto &p : S) {\n\t\
    \t\tif(abs(p.first) == inf) continue;\n\t\t\tres.emplace(p.first, p.second);\n\
    \t\t}\n\t\treturn res;\n\t}\n\n    // debug\n\tvoid dump() const \n    {\n\t\t\
    cout << \"range_set:\";\n\t\tfor(auto &p : S) {\n\t\t\tif(abs(p.first) == inf)\
    \ continue;\n\t\t\tcout << \"[\" << p.first << \",\" << p.second << \"),\";\n\t\
    \t}\n\t\tcout << '\\n';\n\t}\n};\n"
  code: "#pragma once\n\n\n/*\nrange_set\nrange_set<T = long long>()\nbool covered(T\
    \ l, T r) [l, r) \u304C\u30AB\u30D0\u30FC\u3055\u308C\u3066\u3044\u308B\u304B\n\
    pair<T, T> covered_by(T l, T r) [l, r) \u304C\u30AB\u30D0\u30FC\u3055\u308C\u3066\
    \u3044\u308B\u533A\u9593\u3092\u8FD4\u3059\nT insert(T l, T r) [l, r) \u3092\u633F\
    \u5165\u3059\u308B\u3002\u5897\u52A0\u5206\u3092\u8FD4\u3059\nT erase(T l, T r)\
    \ [l, r) \u3092\u6D88\u3059\u3002\u6E1B\u5C11\u5206\u3092\u8FD4\u3059\nint size()\
    \ \u533A\u9593\u306E\u500B\u6570\u3092\u8FD4\u3059\nT mex(T x = 0) mex \u3092\u8FD4\
    \u3059\nT sum_all() \u3059\u3079\u3066\u306E\u533A\u9593\u306E\u548C(\u7D76\u5BFE\
    \u5024)\u3092\u8FD4\u3059\nset<pair<T, T>> get() \u533A\u9593(set)\u3092\u305D\
    \u306E\u307E\u307E\u8FD4\u3059\nvoid dump() \u30C7\u30D0\u30C3\u30B0\u7528\n*/\n\
    template <class T = long long>\nclass range_set\n{\n  private:\n    const T inf\
    \ = infty<T>;\n    T sum;\n    set<pair<T, T>> S;\n  public:\n    range_set()\
    \ : sum(0)\n    {   // [-inf, -inf) ... [inf, inf)\n        S.emplace(-inf, -inf);\n\
    \        S.emplace(inf, inf);\n    }\n\n    // [l, r) is covered?\n    bool covered(const\
    \ T l, const T r)\n    {\n        assert(l <= r);\n        if(l == r) return true;\n\
    \        auto itr = prev(S.upper_bound({l, inf}));\n        return itr->first\
    \ <= l && r <= itr->second;\n    }\n\n    // return section which covers[l, r)\n\
    \    // if not exists, return [-inf, inf)\n    pair<T, T> covered_by(const T l,\
    \ const T r)\n    {\n        assert(l <= r);\n        if(l == r) return {-inf,\
    \ -inf};\n        auto itr = prev(S.upper_bound({l, inf}));\n        if(itr->first\
    \ <= l && r <= itr->second) return *itr;\n        return {-inf, -inf};\n    }\n\
    \n    // insert[l, r), and return increment\n    T insert(T l, T r)\n    {\n \
    \       assert(l <= r);\n        if(l == r) return T(0);\n        auto itr = prev(S.upper_bound({l,\
    \ inf}));\n        if(itr->first <= l && r <= itr->second) return T(0);\n    \
    \    T sum_erased = T(0);\n        if(itr->first <= l && l <= itr->second)\n \
    \       {\n            l = itr->first;\n            sum_erased += itr->second\
    \ - itr->first;\n            itr = S.erase(itr);\n        }\n        else itr\
    \ = next(itr);\n        while(r > itr->second)\n        {\n            sum_erased\
    \ += itr->second - itr->first;\n            itr = S.erase(itr);\n        }\n\t\
    \tif(itr->first <= r) \n        {\n\t\t\tsum_erased += itr->second - itr->first;\n\
    \t\t\tr = itr->second;\n\t\t\tS.erase(itr);\n\t\t}\n\t\tS.emplace(l, r);\n\t\t\
    sum += r - l - sum_erased;\n\t\treturn r - l - sum_erased;\n    }\n\n    // erase\
    \ [l, r), and return decrement\n\tT erase(const T l, const T r) \n    {\n\t\t\
    assert(l <= r);\n\t\tif(l == r) return T(0);\n\t\tauto itr = prev(S.upper_bound({l,\
    \ inf}));\n\t\tif(itr->first <= l and r <= itr->second) \n        {\n\t\t\tif(itr->first\
    \ < l) S.emplace(itr->first, l);\n\t\t\tif(r < itr->second) S.emplace(r, itr->second);\n\
    \t\t\tS.erase(itr);\n\t\t\tsum -= r - l;\n\t\t\treturn r - l;\n\t\t}\n\t\tT ret\
    \ = T(0);\n\t\tif(itr->first <= l and l < itr->second) \n        {\n\t\t\tret\
    \ += itr->second - l;\n\t\t\tif(itr->first < l) S.emplace(itr->first, l);\n\t\t\
    \titr = S.erase(itr);\n\t\t} \n        else itr = next(itr);\n\t\twhile(itr->second\
    \ <= r) \n        {\n\t\t\tret += itr->second - itr->first;\n\t\t\titr = S.erase(itr);\n\
    \t\t}\n\t\tif(itr->first < r) \n        {\n\t\t\tret += r - itr->first;\n\t\t\t\
    S.emplace(r, itr->second);\n\t\t\tS.erase(itr);\n\t\t}\n\t\tsum -= ret;\n\t\t\
    return ret;\n\t}\n\n    int size() const { return (int)S.size() - 2; }\n\n   \
    \ \n\tT mex(const T x = 0) const \n    {\n\t\tauto itr = prev(S.upper_bound({x,\
    \ inf}));\n\t\tif(itr->first <= x and x < itr->second)\n\t\t\treturn itr->second;\n\
    \t\telse\n\t\t\treturn x;\n\t}\n\n    T sum_all() const { return sum; }\n\n  \
    \  // get set\n\tset<pair<T, T>> get() const \n    {\n\t\tset<pair<T, T>> res;\n\
    \t\tfor(auto &p : S) {\n\t\t\tif(abs(p.first) == inf) continue;\n\t\t\tres.emplace(p.first,\
    \ p.second);\n\t\t}\n\t\treturn res;\n\t}\n\n    // debug\n\tvoid dump() const\
    \ \n    {\n\t\tcout << \"range_set:\";\n\t\tfor(auto &p : S) {\n\t\t\tif(abs(p.first)\
    \ == inf) continue;\n\t\t\tcout << \"[\" << p.first << \",\" << p.second << \"\
    ),\";\n\t\t}\n\t\tcout << '\\n';\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/range_set.hpp
  requiredBy: []
  timestamp: '2024-05-03 01:19:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/range_set.hpp
layout: document
redirect_from:
- /library/data_structure/range_set.hpp
- /library/data_structure/range_set.hpp.html
title: data_structure/range_set.hpp
---
