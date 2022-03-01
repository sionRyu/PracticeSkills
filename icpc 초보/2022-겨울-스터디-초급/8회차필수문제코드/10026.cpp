#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


struct coor { int x, y; };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };

	int n, ans = 0, ans2 = 0;
	char arr[105][105];
	int visited[105][105] = { 0 };

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j])continue;
			list<coor> q;
			q.push_front({ i,j });
			visited[i][j] = 1;
			while (!q.empty()) {
				coor cur = q.back(); q.pop_back();
				int x = cur.x, y = cur.y;
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k], ny = y + dy[k];
					if (visited[nx][ny])continue;
					if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
					if (arr[nx][ny] != arr[x][y])continue;
					visited[nx][ny] = 1;
					q.push_front({ nx,ny });
				}
			}
			ans++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 'R') arr[i][j] = 'G';
			visited[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j])continue;
			list<coor> q;
			q.push_front({ i,j });
			visited[i][j] = 1;
			while (!q.empty()) {
				coor cur = q.back(); q.pop_back();
				int x = cur.x, y = cur.y;
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k], ny = y + dy[k];
					if (visited[nx][ny])continue;
					if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
					if (arr[nx][ny] != arr[x][y])continue;
					visited[nx][ny] = 1;
					q.push_front({ nx,ny });
				}
			}
			ans2++;
		}
	}

	cout << ans << " " << ans2 << "\n";

	return 0;
}