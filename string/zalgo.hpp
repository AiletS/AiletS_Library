#pragma once

struct Zalgo
{
	vector<int> z;
	Zalgo() {}
	Zalgo(const string& s) : z(s.size())
	{
		z[0] = s.size();
		int l = 0, r = 0;
		for (int i = 1; i < s.size(); i++)
		{
			if (i > r)
			{
				l = r = i;
				while (r < s.size() && s[r - l] == s[r]) r++;
				z[i] = r - l;
				r--;
			}
			else
			{
				int k = i - l;
				if (z[k] < r - i + 1) z[i] = z[k];
				else
				{
					l = i;
					while (r < s.size() && s[r - l] == s[r]) r++;
					z[i] = r - l;
					r--;
				}
			}
		}
	}
	int operator[](int i) { return z[i]; }
};