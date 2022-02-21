#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int n;
	ll len[100005] = { 0 }, price[100005] = { 0 };
	ll cur = 1000000000, ans = 0;
	cin >> n;
	for (int i = 0; i < n - 1; i++) { //i번째 도시에서 i+1번째 도시까지의 거리
		cin >> len[i];
	}
	for (int i = 0; i < n; i++) { //i번째 도시에서 리터당 가격
		cin >> price[i];
	}

	for (int i = 0; i < n - 1; i++) {
		cur = min(cur, price[i]);
		ans += cur * len[i];
	}
	cout << ans << "\n";

    return 0;
}