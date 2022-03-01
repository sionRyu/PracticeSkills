#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int to1d(int x, int y) {
    return x * 505 + y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, inf = 1000000000;
    char arr[505][505];
    vector<pair<int, int>> adj[300005];
    int dist[300005], visited[300005] = { 0 };
    priority_queue<pair<int, int>> pq;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            //cout<<to1d(i,j)<<"\n";
            if (arr[i][j] == '/') {
                adj[to1d(i - 1, j)].push_back({ to1d(i,j - 1),0 });
                adj[to1d(i, j - 1)].push_back({ to1d(i - 1,j),0 });
                adj[to1d(i - 1, j - 1)].push_back({ to1d(i,j),1 });
                adj[to1d(i, j)].push_back({ to1d(i - 1,j - 1),1 });
            }
            else {
                adj[to1d(i - 1, j)].push_back({ to1d(i,j - 1),1 });
                adj[to1d(i, j - 1)].push_back({ to1d(i - 1,j),1 });
                adj[to1d(i - 1, j - 1)].push_back({ to1d(i,j),0 });
                adj[to1d(i, j)].push_back({ to1d(i - 1,j - 1),0 });
            }
        }
    }
    fill(dist, dist + 300005, inf);
    fill(visited, visited + 300005, 0);
    dist[to1d(0, 0)] = 0;
    pq.push({ 0, to1d(0,0) });
    while (!pq.empty()) {
        //cout<<pq.top().first<<" "<<pq.top().second<<"\n";
        int cur = pq.top().second; pq.pop();
        if (visited[cur]) { continue; }
        visited[cur] = 1;
        for (pair<int, int> u : adj[cur]) {
            int next = u.first, cost = u.second;
            if (dist[next] > dist[cur] + cost) {
                dist[next] = dist[cur] + cost;
                pq.push({ -dist[next],next });
            }
        }
    }
    if (dist[to1d(n, m)] == inf) { cout << "NO SOLUTION\n"; }
    else { cout << dist[to1d(n, m)] << "\n"; }

    return 0;
}