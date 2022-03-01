#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
using lint = long long;

int N, M;
string s[1001];
lint h[1001][1001];

lint p = 27;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> s[i];
	lint pp = 1;
	for (int r = N - 1; r >= 0; r--, pp = pp * p)
		for (int c = 0; c < M; c++)
			h[r][c] = h[r + 1][c] + (s[r][c]-'a' + 1) * pp;
	for (int i = 1; i < N; i++) {
        sort(h[i], h[i]+M);
		for (int j = 0; j < M - 1; j++) if (h[i][j] == h[i][j + 1]) 
            return cout << i - 1, 0;
	}
	cout << N-1;
	return 0;
}