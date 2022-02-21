#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    ll n, m, start, dest, inf = 1e18;
    vector<pair<ll, ll>> adj[1005];
    priority_queue<pair<ll, ll>> pq;
    ll dist[1005] = { 0 }, visited[1005] = { 0 };
    int prev[1005];
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        adj[s].push_back({ e,c });
    }
    cin >> start >> dest;
    pq.push({ 0,start });
    fill(dist, dist + 1005, inf);
    dist[start] = 0;
    while (!pq.empty()) {
        ll cur = pq.top().second; pq.pop();
        if (visited[cur]) { continue; }
        visited[cur] = 1;
        for (pair<int, int> u : adj[cur]) {
            ll next = u.first, cost = u.second;
            if (dist[next] > dist[cur] + cost) {
                dist[next] = dist[cur] + cost;
                prev[next] = cur;
                pq.push({ -dist[next], next });
            }
        }
    }
    vector<int> order;
    int c = dest;
    while (c != start) {
        order.push_back(c);
        c = prev[c];
    }
    order.push_back(start);
    cout << dist[dest] << "\n";
    cout << order.size() << "\n";
    for (int i = order.size() - 1; i >= 0; i--) {
        cout << order[i] << " ";
    }cout << "\n";

    return 0;
}