#pragma once

long long extgcd(long long a, long long b, long long& x, long long& y)
{
	long long d = a;
	if (b != 0)
	{
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	else { x = 1; y = 0; return a; }

	return d;
}
// ax + by = gcd(a, b), return gcd(a, b), get x and y

pair<long long, long long> crt(const vector<long long> b, const vector<long long> m)
{
	long long r = 0, M = 1;
	for (int i = 0; i < b.size(); i++)
	{
		long long p, q;
		long long d = extgcd(M, m[i], p, q);
		if ((b[i] - r) % d != 0) return { 0, -1 };
		long long tmp = (b[i] - r) / d * p % (m[i] / d);
		r += M * tmp;
		M *= m[i] / d;
	}

	r = (r % M + M) % M; // if r < 0
	return { r, M };
}
// x = b[i] mod m[i], get x = r mod M {r, M}
// if there is no solution return {0, -1}