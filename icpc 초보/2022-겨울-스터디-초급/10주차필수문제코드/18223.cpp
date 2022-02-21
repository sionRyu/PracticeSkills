#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int V, E, P;
int mx = 2000000000;
vector<pair<int, int>> adj[5005];
int dist[5005] = { 0 };
int visited[5005] = { 0 };

void dijkstra(int start) {
    fill(dist, dist + 5005, mx);
    fill(visited, visited + 5005, 0);
    priority_queue<pair<int, int>> pq;
    pq.push({ 0, start });
    dist[start] = 0;
    while (!pq.empty()) {
        int cur = pq.top().second; pq.pop();
        if (visited[cur]) { continue; }
        visited[cur] = 1;
        for (pair<int, int> u : adj[cur]) {
            int next = u.first, cost = u.second;
            if (dist[cur] + cost < dist[next]) {
                dist[next] = dist[cur] + cost;
                pq.push({ -dist[next], next });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> V >> E >> P;
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ b,c });
        adj[b].push_back({ a,c });
        //길 연결해주기
    }
    int min_dist, save_dist;
    dijkstra(1);
    min_dist = dist[V];
    save_dist = dist[P];
    dijkstra(P);
    save_dist += dist[V];

    if (min_dist == save_dist) { cout << "SAVE HIM\n"; }
    else { cout << "GOOD BYE\n"; }


    return 0;
}