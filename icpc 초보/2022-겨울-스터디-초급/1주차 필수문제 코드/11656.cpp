#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;
    vector<string> v;
    int len = S.length();
    for (int i = 0; i < len; i++) {
        v.push_back(S.substr(i, len - i));
    }
    sort(v.begin(), v.end());
    for (string st : v) {
        cout << st << "\n";
    }
    return 0;
}