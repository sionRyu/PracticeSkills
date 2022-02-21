#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<vector<int>> a;

int solve(int len, int r, int c) {
	if (len == 2) {
		int x[4] = { a[r][c], a[r][c + 1], a[r + 1][c], a[r + 1][c + 1] };
		sort(x, x + 4);
		return x[2];
	}
	int x[4];
	x[0] = solve(len / 2, r, c), x[1] = solve(len / 2, r, c + len / 2);
	x[2] = solve(len / 2, r + len / 2, c), x[3] = solve(len / 2, r + len / 2, c + len / 2);
	sort(x, x + 4);

	return x[2];	
}

int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	a.resize(N);
	for (int i = 0; i < N; i++)
		a[i].resize(N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &a[i][j]);

	printf("%d", solve(N, 0, 0));

	return 0;
}