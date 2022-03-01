#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
using lint = long long;

const int p = 2, MOD = 1e9 + 7;
int N, M;
char s[1000100], pat[1000100];
lint h[2];
int main() {
	scanf("%d%d", &M, &N);
	getchar();
	scanf("%[^\n]s", s);
	M = 2 * M + 1;
	for (int i = 0; i < M; i++)
		pat[i] = (i % 2 ? 'O' : 'I');
	lint pw = 1;

	for (int i = 0; i < M; i++) {
		h[0] = (h[0] * p + pat[i]) % MOD;
		h[1] = (h[1] * p + s[i]) % MOD;
		if (i) pw = (pw * p) % MOD;
	}
	int ans = 0;
	if (h[0] == h[1]) ans++;
	for (int i = 1; i + M - 1< N; i++) {
		h[1] = (p * (h[1] - pw * s[i - 1]) + s[i + M - 1]) % MOD;
		if (h[1] < 0) h[1] += MOD;
		if (h[0] == h[1]) ans++;
	}

	printf("%d\n", ans);

	return 0;
}