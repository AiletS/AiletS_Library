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
  bundledCode: "#line 2 \"string/suffix_array.hpp\"\n\nvector<int> SA_IS(vector<int>&\
    \ s, int char_type = 256)\n{\n\tint n = s.size();\n\tvector<int> SL(n, 0); //\
    \ S : 0, L : 1\n\tvector<int> bin(char_type, 0);\n\tvector<int> SA(n);\n\n\tfor\
    \ (int i = n - 2; i >= 0; i--)\n\t{\n\t\tSL[i] = (s[i] == s[i + 1]) ? SL[i + 1]\
    \ : s[i] > s[i + 1];\n\t}\n\n\tfor (auto& p : s) bin[p]++;\n\tint sum = 0;\n\t\
    for (int i = 0; i < char_type; i++)\n\t{\n\t\tint add = bin[i];\n\t\tbin[i] =\
    \ sum;\n\t\tsum += add;\n\t}\n\n\tauto induced_sort = [&](vector<int>& lms) ->\
    \ void\n\t{\n\t\tfill(SA.begin(), SA.end(), -1);\n\t\tvector<int> count(char_type);\n\
    \t\tcopy(bin.begin(), bin.end(), count.begin());\n\t\tfor (int i = lms.size()\
    \ - 1; i >= 0; i--)\n\t\t{\n\t\t\tint p = lms[i];\n\t\t\tSA[--count[s[p] + 1]]\
    \ = p;\n\t\t}\n\t\tcopy(bin.begin(), bin.end(), count.begin());\n\t\tfor (int\
    \ i = 0; i < n; i++)\n\t\t{\n\t\t\tint p = SA[i];\n\t\t\tif (p > 0 && SL[p - 1]\
    \ == 1)\n\t\t\t{\n\t\t\t\tSA[count[s[p - 1]]++] = p - 1;\n\t\t\t}\n\t\t}\n\t\t\
    copy(bin.begin(), bin.end(), count.begin());\n\t\tfor (int i = n - 1; i >= 0;\
    \ i--)\n\t\t{\n\t\t\tint p = SA[i];\n\t\t\tif (p > 0 && SL[p - 1] == 0)\n\t\t\t\
    {\n\t\t\t\tSA[--count[s[p - 1] + 1]] = p - 1;\n\t\t\t}\n\t\t}\n\t};\n\n\tauto\
    \ chlms = [&](int i) -> bool\n\t{\n\t\tif (i > 0 && SL[i - 1] && !SL[i]) return\
    \ true;\n\t\telse return false;\n\t};\n\n\tvector<int> lms;\n\tfor (int i = 1;\
    \ i < n; i++)\n\t{\n\t\tif (chlms(i)) lms.push_back(i);\n\t}\n\n\tinduced_sort(lms);\n\
    \n\tvector<int> new_lms;\n\tfor (int i = 0; i < n; i++)\n\t{\n\t\tif (chlms(SA[i]))\
    \ new_lms.push_back(SA[i]);\n\t}\n\tvector<int> new_group(n, -1);\n\tnew_group[new_lms[0]]\
    \ = 0;\n\tint id = 0;\n\tfor (int i = 1; i < new_lms.size(); i++)\n\t{\n\t\tbool\
    \ diff = false;\n\t\tfor (int j = 0; ; j++)\n\t\t{\n\t\t\tint x = new_lms[i],\
    \ y = new_lms[i - 1];\n\t\t\tif (s[x + j] != s[y + j] || chlms(x + j) != chlms(y\
    \ + j))\n\t\t\t{\n\t\t\t\tdiff = true;\n\t\t\t\tbreak;\n\t\t\t}\n\t\t\telse if\
    \ (j > 0 && (chlms(x + j) || chlms(y + j)))\n\t\t\t{\n\t\t\t\tbreak;\n\t\t\t}\n\
    \t\t}\n\n\t\tid += diff;\n\t\tnew_group[new_lms[i]] = id;\n\t}\n\n\tvector<int>\
    \ tmp;\n\tfor (int i = 0; i < n; i++) if (new_group[i] != -1)\n\t{\n\t\ttmp.push_back(new_group[i]);\n\
    \t}\n\tswap(tmp, new_group);\n\n\tvector<int> new_SA;\n\tvector<int> sorted_lms;\n\
    \n\tif (id + 1 < new_group.size())\n\t{\n\t\tnew_SA = SA_IS(new_group, id + 1);\n\
    \t}\n\telse\n\t{\n\t\tnew_SA.resize(new_group.size());\n\t\tfor (int i = 0; i\
    \ < new_group.size(); i++)\n\t\t{\n\t\t\tnew_SA[new_group[i]] = i;\n\t\t}\n\t\
    }\n\n\tfor (int i = 0; i < new_SA.size(); i++)\n\t{\n\t\tsorted_lms.push_back(lms[new_SA[i]]);\n\
    \t}\n\n\tinduced_sort(sorted_lms);\n\treturn SA;\n}\n\nvector<int> SA_IS(string&\
    \ s)\n{\n\ts.push_back('#');\n\tvector<int> tmp(s.size());\n\tfor (int i = 0;\
    \ i < s.size(); i++) tmp[i] = s[i];\n\treturn SA_IS(tmp, 256);\n}\n\nvector<int>\
    \ suffix_array(string s)\n{\n\tvector<int> sa = SA_IS(s);\n    sa.erase(sa.begin());\n\
    \    return sa;\n}\n\ntemplate <class T>\nvector<int> lcp_array(const vector<T>&\
    \ s, const vector<int>& sa) {\n\tint n = int(s.size());\n\tvector<int> rnk(n);\n\
    \tfor (int i = 0; i < n; i++) {\n\t\trnk[sa[i]] = i;\n\t}\n\tvector<int> lcp(n\
    \ - 1);\n\tint h = 0;\n\tfor (int i = 0; i < n; i++) {\n\t\tif (h > 0) h--;\n\t\
    \tif (rnk[i] == 0) continue;\n\t\tint j = sa[rnk[i] - 1];\n\t\tfor (; j + h <\
    \ n && i + h < n; h++) {\n\t\t\tif (s[j + h] != s[i + h]) break;\n\t\t}\n\t\t\
    lcp[rnk[i] - 1] = h;\n\t}\n\treturn lcp;\n}\n\nvector<int> lcp_array(const string&\
    \ s, const vector<int>& sa) {\n\tint n = int(s.size());\n\tvector<int> s2(n);\n\
    \tfor (int i = 0; i < n; i++) {\n\t\ts2[i] = s[i];\n\t}\n\treturn lcp_array(s2,\
    \ sa);\n}\n"
  code: "#pragma once\n\nvector<int> SA_IS(vector<int>& s, int char_type = 256)\n\
    {\n\tint n = s.size();\n\tvector<int> SL(n, 0); // S : 0, L : 1\n\tvector<int>\
    \ bin(char_type, 0);\n\tvector<int> SA(n);\n\n\tfor (int i = n - 2; i >= 0; i--)\n\
    \t{\n\t\tSL[i] = (s[i] == s[i + 1]) ? SL[i + 1] : s[i] > s[i + 1];\n\t}\n\n\t\
    for (auto& p : s) bin[p]++;\n\tint sum = 0;\n\tfor (int i = 0; i < char_type;\
    \ i++)\n\t{\n\t\tint add = bin[i];\n\t\tbin[i] = sum;\n\t\tsum += add;\n\t}\n\n\
    \tauto induced_sort = [&](vector<int>& lms) -> void\n\t{\n\t\tfill(SA.begin(),\
    \ SA.end(), -1);\n\t\tvector<int> count(char_type);\n\t\tcopy(bin.begin(), bin.end(),\
    \ count.begin());\n\t\tfor (int i = lms.size() - 1; i >= 0; i--)\n\t\t{\n\t\t\t\
    int p = lms[i];\n\t\t\tSA[--count[s[p] + 1]] = p;\n\t\t}\n\t\tcopy(bin.begin(),\
    \ bin.end(), count.begin());\n\t\tfor (int i = 0; i < n; i++)\n\t\t{\n\t\t\tint\
    \ p = SA[i];\n\t\t\tif (p > 0 && SL[p - 1] == 1)\n\t\t\t{\n\t\t\t\tSA[count[s[p\
    \ - 1]]++] = p - 1;\n\t\t\t}\n\t\t}\n\t\tcopy(bin.begin(), bin.end(), count.begin());\n\
    \t\tfor (int i = n - 1; i >= 0; i--)\n\t\t{\n\t\t\tint p = SA[i];\n\t\t\tif (p\
    \ > 0 && SL[p - 1] == 0)\n\t\t\t{\n\t\t\t\tSA[--count[s[p - 1] + 1]] = p - 1;\n\
    \t\t\t}\n\t\t}\n\t};\n\n\tauto chlms = [&](int i) -> bool\n\t{\n\t\tif (i > 0\
    \ && SL[i - 1] && !SL[i]) return true;\n\t\telse return false;\n\t};\n\n\tvector<int>\
    \ lms;\n\tfor (int i = 1; i < n; i++)\n\t{\n\t\tif (chlms(i)) lms.push_back(i);\n\
    \t}\n\n\tinduced_sort(lms);\n\n\tvector<int> new_lms;\n\tfor (int i = 0; i < n;\
    \ i++)\n\t{\n\t\tif (chlms(SA[i])) new_lms.push_back(SA[i]);\n\t}\n\tvector<int>\
    \ new_group(n, -1);\n\tnew_group[new_lms[0]] = 0;\n\tint id = 0;\n\tfor (int i\
    \ = 1; i < new_lms.size(); i++)\n\t{\n\t\tbool diff = false;\n\t\tfor (int j =\
    \ 0; ; j++)\n\t\t{\n\t\t\tint x = new_lms[i], y = new_lms[i - 1];\n\t\t\tif (s[x\
    \ + j] != s[y + j] || chlms(x + j) != chlms(y + j))\n\t\t\t{\n\t\t\t\tdiff = true;\n\
    \t\t\t\tbreak;\n\t\t\t}\n\t\t\telse if (j > 0 && (chlms(x + j) || chlms(y + j)))\n\
    \t\t\t{\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\n\t\tid += diff;\n\t\tnew_group[new_lms[i]]\
    \ = id;\n\t}\n\n\tvector<int> tmp;\n\tfor (int i = 0; i < n; i++) if (new_group[i]\
    \ != -1)\n\t{\n\t\ttmp.push_back(new_group[i]);\n\t}\n\tswap(tmp, new_group);\n\
    \n\tvector<int> new_SA;\n\tvector<int> sorted_lms;\n\n\tif (id + 1 < new_group.size())\n\
    \t{\n\t\tnew_SA = SA_IS(new_group, id + 1);\n\t}\n\telse\n\t{\n\t\tnew_SA.resize(new_group.size());\n\
    \t\tfor (int i = 0; i < new_group.size(); i++)\n\t\t{\n\t\t\tnew_SA[new_group[i]]\
    \ = i;\n\t\t}\n\t}\n\n\tfor (int i = 0; i < new_SA.size(); i++)\n\t{\n\t\tsorted_lms.push_back(lms[new_SA[i]]);\n\
    \t}\n\n\tinduced_sort(sorted_lms);\n\treturn SA;\n}\n\nvector<int> SA_IS(string&\
    \ s)\n{\n\ts.push_back('#');\n\tvector<int> tmp(s.size());\n\tfor (int i = 0;\
    \ i < s.size(); i++) tmp[i] = s[i];\n\treturn SA_IS(tmp, 256);\n}\n\nvector<int>\
    \ suffix_array(string s)\n{\n\tvector<int> sa = SA_IS(s);\n    sa.erase(sa.begin());\n\
    \    return sa;\n}\n\ntemplate <class T>\nvector<int> lcp_array(const vector<T>&\
    \ s, const vector<int>& sa) {\n\tint n = int(s.size());\n\tvector<int> rnk(n);\n\
    \tfor (int i = 0; i < n; i++) {\n\t\trnk[sa[i]] = i;\n\t}\n\tvector<int> lcp(n\
    \ - 1);\n\tint h = 0;\n\tfor (int i = 0; i < n; i++) {\n\t\tif (h > 0) h--;\n\t\
    \tif (rnk[i] == 0) continue;\n\t\tint j = sa[rnk[i] - 1];\n\t\tfor (; j + h <\
    \ n && i + h < n; h++) {\n\t\t\tif (s[j + h] != s[i + h]) break;\n\t\t}\n\t\t\
    lcp[rnk[i] - 1] = h;\n\t}\n\treturn lcp;\n}\n\nvector<int> lcp_array(const string&\
    \ s, const vector<int>& sa) {\n\tint n = int(s.size());\n\tvector<int> s2(n);\n\
    \tfor (int i = 0; i < n; i++) {\n\t\ts2[i] = s[i];\n\t}\n\treturn lcp_array(s2,\
    \ sa);\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/suffix_array.hpp
  requiredBy: []
  timestamp: '2024-07-16 01:07:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/suffix_array.hpp
layout: document
redirect_from:
- /library/string/suffix_array.hpp
- /library/string/suffix_array.hpp.html
title: string/suffix_array.hpp
---
