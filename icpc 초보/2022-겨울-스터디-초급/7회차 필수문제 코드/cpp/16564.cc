#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int N, k, a[1000100];

int f(lint x) {
	lint ret = k;
	for (int i = 0; i < N; i++)
		ret -= max(x - a[i], 0LL);

	return ret >= 0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> N >> k;
	for (int i = 0; i < N; i++) cin >> a[i];

	lint l = *min_element(a, a + N), r = (1LL << 31) - 1, ans = 0;
	while (l <= r) {
		lint m = l + r >> 1;
		if (f(m)) ans = m, l = m + 1;
		else r = m - 1;
	}
	cout << ans;

	return 0;
}