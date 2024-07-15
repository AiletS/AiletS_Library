#pragma once

vector<int> SA_IS(vector<int>& s, int char_type = 256)
{
	int n = s.size();
	vector<int> SL(n, 0); // S : 0, L : 1
	vector<int> bin(char_type, 0);
	vector<int> SA(n);

	for (int i = n - 2; i >= 0; i--)
	{
		SL[i] = (s[i] == s[i + 1]) ? SL[i + 1] : s[i] > s[i + 1];
	}

	for (auto& p : s) bin[p]++;
	int sum = 0;
	for (int i = 0; i < char_type; i++)
	{
		int add = bin[i];
		bin[i] = sum;
		sum += add;
	}

	auto induced_sort = [&](vector<int>& lms) -> void
	{
		fill(SA.begin(), SA.end(), -1);
		vector<int> count(char_type);
		copy(bin.begin(), bin.end(), count.begin());
		for (int i = lms.size() - 1; i >= 0; i--)
		{
			int p = lms[i];
			SA[--count[s[p] + 1]] = p;
		}
		copy(bin.begin(), bin.end(), count.begin());
		for (int i = 0; i < n; i++)
		{
			int p = SA[i];
			if (p > 0 && SL[p - 1] == 1)
			{
				SA[count[s[p - 1]]++] = p - 1;
			}
		}
		copy(bin.begin(), bin.end(), count.begin());
		for (int i = n - 1; i >= 0; i--)
		{
			int p = SA[i];
			if (p > 0 && SL[p - 1] == 0)
			{
				SA[--count[s[p - 1] + 1]] = p - 1;
			}
		}
	};

	auto chlms = [&](int i) -> bool
	{
		if (i > 0 && SL[i - 1] && !SL[i]) return true;
		else return false;
	};

	vector<int> lms;
	for (int i = 1; i < n; i++)
	{
		if (chlms(i)) lms.push_back(i);
	}

	induced_sort(lms);

	vector<int> new_lms;
	for (int i = 0; i < n; i++)
	{
		if (chlms(SA[i])) new_lms.push_back(SA[i]);
	}
	vector<int> new_group(n, -1);
	new_group[new_lms[0]] = 0;
	int id = 0;
	for (int i = 1; i < new_lms.size(); i++)
	{
		bool diff = false;
		for (int j = 0; ; j++)
		{
			int x = new_lms[i], y = new_lms[i - 1];
			if (s[x + j] != s[y + j] || chlms(x + j) != chlms(y + j))
			{
				diff = true;
				break;
			}
			else if (j > 0 && (chlms(x + j) || chlms(y + j)))
			{
				break;
			}
		}

		id += diff;
		new_group[new_lms[i]] = id;
	}

	vector<int> tmp;
	for (int i = 0; i < n; i++) if (new_group[i] != -1)
	{
		tmp.push_back(new_group[i]);
	}
	swap(tmp, new_group);

	vector<int> new_SA;
	vector<int> sorted_lms;

	if (id + 1 < new_group.size())
	{
		new_SA = SA_IS(new_group, id + 1);
	}
	else
	{
		new_SA.resize(new_group.size());
		for (int i = 0; i < new_group.size(); i++)
		{
			new_SA[new_group[i]] = i;
		}
	}

	for (int i = 0; i < new_SA.size(); i++)
	{
		sorted_lms.push_back(lms[new_SA[i]]);
	}

	induced_sort(sorted_lms);
	return SA;
}

vector<int> SA_IS(string& s)
{
	s.push_back('#');
	vector<int> tmp(s.size());
	for (int i = 0; i < s.size(); i++) tmp[i] = s[i];
	return SA_IS(tmp, 256);
}

vector<int> suffix_array(string s)
{
	vector<int> sa = SA_IS(s);
    sa.erase(sa.begin());
    return sa;
}

template <class T>
vector<int> lcp_array(const vector<T>& s, const vector<int>& sa) {
	int n = int(s.size());
	vector<int> rnk(n);
	for (int i = 0; i < n; i++) {
		rnk[sa[i]] = i;
	}
	vector<int> lcp(n - 1);
	int h = 0;
	for (int i = 0; i < n; i++) {
		if (h > 0) h--;
		if (rnk[i] == 0) continue;
		int j = sa[rnk[i] - 1];
		for (; j + h < n && i + h < n; h++) {
			if (s[j + h] != s[i + h]) break;
		}
		lcp[rnk[i] - 1] = h;
	}
	return lcp;
}

vector<int> lcp_array(const string& s, const vector<int>& sa) {
	int n = int(s.size());
	vector<int> s2(n);
	for (int i = 0; i < n; i++) {
		s2[i] = s[i];
	}
	return lcp_array(s2, sa);
}