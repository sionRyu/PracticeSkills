#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, s, arr[25];
int ans, cur_sum;

void dfs(int cur) {
    if (cur == n) { return; } //n개 원소
    if (cur_sum + arr[cur] == s) { ans++; }
    dfs(cur + 1);
    cur_sum += arr[cur];
    dfs(cur + 1);
    cur_sum -= arr[cur];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    dfs(0);
    cout << ans << "\n";

    return 0;
}