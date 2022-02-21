#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int n, m;
int arr[1005][1005];
int dist[1005][1005];
pair<int, int> start;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                dist[i][j] = 100000000;
                //애초에 못 가는 땅을 표시함
            }
            if (arr[i][j] == 2) {
                start = { i,j };
            }
        }
    }

    list<pair<int, int>> q;
    q.push_front(start);
    dist[start.first][start.second] = 0;
    //시작하는 곳
    while (!q.empty()) {
        pair<int, int> cur = q.back(); q.pop_back();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i], ny = cur.second + dy[i];
            if (dist[nx][ny]) { continue; }
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) { continue; }
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push_front({ nx,ny });
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == start.first && j == start.second) { cout << 0 << " "; }
            else if (dist[i][j] == 100000000) { cout << 0 << " "; }
            else if (dist[i][j] == 0) { cout << -1 << " "; }
            else { cout << dist[i][j] << " "; }
        }
        cout << "\n";
    }


    return 0;
}