#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, arr[1000005];
    int ans = -1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = 2; i < n; i++) {
        if (arr[i] < arr[i - 1] + arr[i - 2]) {
            ans = max(ans, arr[i] + arr[i - 1] + arr[i - 2]);
        }
    }
    cout << ans << "\n";
    return 0;
}