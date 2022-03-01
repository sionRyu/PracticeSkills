#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int m, n, k;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int mp[101][101] = { 0 };
int visited[100][100] = { 0 };
vector<int> ans;

int bfs(int x, int y) {
	int num = 1; //정점개수리턴
	list<pair<int, int>> q;
	q.push_front({ x,y });
	visited[x][y] = 1;
	while (!q.empty()) {
		pair<int, int> next = q.back(); q.pop_back();
		int x = next.first, y = next.second;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx<0 || ny<0 || nx>n - 1 || ny>m - 1) continue;
			if (visited[nx][ny]) continue;
			if (mp[nx][ny] == 2) continue; //2이면 못감

			visited[nx][ny] = 1;
			num++;
			q.push_front({ nx,ny });
		}
	}
	return num;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mp[i][j] = 1; //갈 수 있는 칸은 1
		}
	}
	int x1, y1, x2, y2;
	for (int z = 0; z < k; z++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i < x2; i++) {
			for (int j = y1; j < y2; j++) {
				mp[i][j] = 2; //2인 칸은 못 간다
			}
		}
	}
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mp[i][j] == 1 && !visited[i][j])
			{
				cnt++;
				ans.push_back(bfs(i, j));
			}
		}
	}

	sort(ans.begin(), ans.end());
	cout << cnt << "\n";
	for (int a : ans) {
		cout << a << " ";
	}
	cout << "\n";
	return 0;
}