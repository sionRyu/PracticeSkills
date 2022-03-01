#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    pair<int, int> arr[55];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        for (int c = 0; c < n; c++) {
            if (arr[i].first < arr[c].first && arr[i].second < arr[c].second) { cnt++; }
        }
        cout << cnt << " ";
    }cout << "\n";

    return 0;
}