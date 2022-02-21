#include <bits/stdc++.h>
using namespace std;
using lint = long long;

const lint p = 27;

int psz, ssz;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s, P;
	cin >> s >> P;
	ssz = s.size(), psz = P.size();

	lint ph = 0, h = 0, pp = 1;
	for (int i = 0; P[i]; i++) {
		ph = ph + 1LL * P[psz - 1 - i] * pp;
		h = h + 1LL * s[psz - 1 - i] * pp;
		if (i < psz - 1) pp *= p;
	}
	if (ph == h) return cout << 1, 0;
	for (int i = 1; i <= ssz - psz; i++) {
		h = p * (h - 1LL * s[i - 1] * pp) + s[i + psz - 1];
		if (ph == h) return cout << 1, 0;
	}

	return cout << 0, 0;
}