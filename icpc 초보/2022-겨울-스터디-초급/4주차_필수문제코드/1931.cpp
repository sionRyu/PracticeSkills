#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct use {
    int s, e;

    bool operator<(use other) {
        if (e == other.e) {
            return s < other.s;
        }
        return e < other.e;
    }
}use;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, cur, ans;
    use arr[100005];
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> arr[i].s >> arr[i].e; }
    sort(arr, arr + n);
    ans = cur = 0;
    for (int i = 0; i < n; i++) {
        //cout<<arr[i].s<<" "<<arr[i].e<<"\n";
        if (arr[i].s >= cur) {
            ans++; cur = arr[i].e;
        }
    }
    cout << ans << "\n";
    return 0;
}