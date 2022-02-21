#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc, inf = 2100000000;
    cin >> tc;
    for (int z = 0; z < tc; z++) {
        int n, m;
        vector<pair<int, int>> adj[25];
        priority_queue<pair<int, int>> pq;
        int visited[25] = { 0 };
        int dist[25] = { 0 };
        int prev[25];
        cin >> m >> n;
        for (int i = 0; i < m; i++) {
            int s, e, c;
            cin >> s >> e >> c;
            adj[s].push_back({ e,c });
            adj[e].push_back({ s,c });
        }
        fill(dist, dist + 25, inf);
        pq.push({ 0,0 });
        dist[0] = 0;
        while (!pq.empty()) {
            int cur = pq.top().second; pq.pop();
            if (visited[cur]) { continue; }
            visited[cur] = 1;
            for (pair<int, int> u : adj[cur]) {
                int next = u.first, cost = u.second;
                if (dist[next] > dist[cur] + cost) {
                    prev[next] = cur;
                    dist[next] = dist[cur] + cost;
                    pq.push({ -dist[next], next });
                }
            }
        }
        cout << "Case #" << z + 1 << ": ";
        if (dist[n - 1] == inf) { cout << -1 << "\n"; continue; }
        vector<int> ans;
        int cur = n - 1;
        while (cur) {
            ans.push_back(cur);
            cur = prev[cur];
        }
        ans.push_back(0);
        for (int i = ans.size() - 1; i >= 0; i--) {
            cout << ans[i] << " ";
        }cout << "\n";
    }

    return 0;
}