#pragma once
template <typename STRING = string, typename CHAR = char>
vector<pair<CHAR, int>> rle(STRING s) {
	vector<pair<CHAR, int>> res;
	for (CHAR c : s) {
		if (!res.empty() && c == res.back().first) res.back().second += 1;
		else res.emplace_back(c, 1);
	}
	return res;
}