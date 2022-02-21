#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int A[51], B[51], ans = 0;
    for (int i = 0; i < n; i++) { cin >> A[i]; }
    for (int i = 0; i < n; i++) { cin >> B[i]; }
    sort(A, A + n);
    sort(B, B + n, greater<>());
    for (int i = 0; i < n; i++) { ans += A[i] * B[i]; }
    cout << ans << "\n";

    return 0;
}