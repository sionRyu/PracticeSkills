#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, arr[1005], cur = 0, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> arr[i]; }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        cur += arr[i]; ans += cur;
    }
    cout << ans << "\n";

    return 0;
}