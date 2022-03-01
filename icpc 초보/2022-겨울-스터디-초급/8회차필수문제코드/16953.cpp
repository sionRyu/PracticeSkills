#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    ll a, b, ans = -1;
    list<pair<ll, ll>> q;
    cin >> a >> b;
    q.push_front({ a,0 });
    while (!q.empty()) {
        pair<ll, ll> cur = q.back(); q.pop_back();
        if (cur.first == b) { ans = cur.second + 1; break; }
        if (cur.first * 2 <= b) { q.push_front({ cur.first * 2, cur.second + 1 }); }
        if (cur.first * 10 + 1 <= b) { q.push_front({ cur.first * 10 + 1, cur.second + 1 }); }
    }
    cout << ans << "\n";


    return 0;
}