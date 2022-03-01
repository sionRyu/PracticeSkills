#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    vector<int> adj[105];
    int visited[105] = { 0 };
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    int ans = 0;
    list<int> q;
    q.push_back(1);
    visited[1] = 1;
    while (!q.empty()) {
        int cur = q.back(); q.pop_back();
        for (int next : adj[cur]) {
            if (visited[next]) { continue; }
            ans++;
            visited[next] = 1;
            q.push_back(next);
        }
    }
    cout << ans << "\n";

    return 0;
}