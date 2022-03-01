#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    ll inf = 1e18;
    vector<pair<int, int>> adj[505];
    ll dist[505];
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        adj[s].push_back({ e,c });
    }
    int cycle = 0;
    fill(dist, dist + 505, inf);
    dist[1] = 0;
    for (int i = 1; i <= n; i++) {
        //각 정점이 i개 정점을 거쳐 오는 경우를 계속 갱신함
        for (int cur = 1; cur <= n; cur++) {
            for (pair<int, int> p : adj[cur]) {
                int next = p.first, cost = p.second;
                if (dist[cur] != inf && dist[next] > dist[cur] + cost) {
                    dist[next] = dist[cur] + cost;
                    if (i == n) { cycle = 1; }
                }
            }
        }
    }
    if (cycle) { cout << -1 << "\n"; }
    else {
        for (int i = 2; i <= n; i++) { cout << (dist[i] == inf ? -1 : dist[i]) << "\n"; }
    }

    return 0;
}