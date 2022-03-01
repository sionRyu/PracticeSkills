#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    vector<int> v1, v2;
    cin >> n >> k;
    while (k > 0) {
        if (k >= n - 1) {
            k -= n - 1;
            v1.push_back(n);
            n--;
        }
        else {
            v2.push_back(n);
            n--;
        }
    }
    for (int i = n; i > 0; i--) {
        v2.push_back(i);
    }
    sort(v2.begin(), v2.end());
    for (int num : v1) { cout << num << " "; }
    for (int num : v2) { cout << num << " "; }cout << "\n";


    return 0;
}