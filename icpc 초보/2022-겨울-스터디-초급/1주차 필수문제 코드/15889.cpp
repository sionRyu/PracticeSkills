#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t, success = 1, tsuc = 0;
    int pos[30005], range[1000005];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> pos[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> t;
        range[pos[i]] = max(range[pos[i]], t);
        //그 좌표에서 던질 수 있는 사거리
    }
    for (int i = 0; i < n - 1; i++) {
        if (pos[i] == pos[i + 1]) { continue; }
        for (int j = 0; j <= i; j++) {
            if (pos[j] == pos[j + 1]) { continue; }
            if (pos[i + 1] <= pos[j] + range[pos[j]]) {
                //전진 가능
                tsuc = 1; break;
            }
        }
        if (tsuc == 0) {
            success = 0; break;
        }
        tsuc = 0;
    }
    if (success) { cout << "권병장님, 중대장님이 찾으십니다\n"; }
    else { cout << "엄마 나 전역 늦어질 것 같아\n"; }
    return 0;
}