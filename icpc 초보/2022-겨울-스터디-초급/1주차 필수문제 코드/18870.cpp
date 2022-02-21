#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, cnt = 0;
    int arr[1000005];
    int order[1000005];
    unordered_map<int, int> mp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        order[i] = arr[i];
    }
    sort(arr, arr + n);
    mp[arr[0]] = cnt;
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] != arr[i]) {
            cnt++;
            mp[arr[i]] = cnt;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << mp[order[i]] << " ";
    }
    cout << "\n";

    return 0;
}