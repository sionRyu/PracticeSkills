#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    pair<int, int> arr[100005];
    int g[100005];
    int ans = 0;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
        ans += arr[i].second;
        g[i] = arr[i].first - arr[i].second;
        x -= 1000;
    }
    sort(g, g + n, greater<>());
    for (int i = 0; i < n; i++) {
        if (x >= 4000 && g[i] >= 0) {
            x -= 4000;
            ans += g[i];
        }
        else {
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}