#include <bits/stdc++.h>
using namespace std;

int tc;
string s;

int f(int l, int r) {
	if (l == r) return 1;
	int m = (l + r) / 2, lenHalf = (r - l + 1) / 2;
	if (!(f(l, m - 1) & f(m + 1, r))) return 0;
	for (int i = 0; i < lenHalf; i++)
		if (1 - (s[l + i] - '0') != s[r - i] - '0') return 0;
	return 1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> tc;
	while (tc--) {
		cin >> s;
		int res = f(0, (int)s.size() - 1);
		if (res) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}