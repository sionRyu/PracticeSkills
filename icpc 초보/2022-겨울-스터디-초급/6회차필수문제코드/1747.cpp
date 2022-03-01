#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int notprime[2000005] = { 1,1,0 }; //소수가 아니면 1

void sieve(void) {
    for (int i = 2; i <= 2000000; i++) {
        if (notprime[i] == 0) {
            for (int j = 2 * i; j <= 2000000; j += i) {
                notprime[j] = 1;
            }
        }
    }
}

int check(int n) {
    vector<int> digit;
    while (n != 0) {
        digit.push_back(n % 10);
        n /= 10;
    }
    int len = digit.size();
    for (int i = 0; i < len / 2; i++) {
        if (digit[i] != digit[len - i - 1]) { return 0; }
    }
    //for (int i : digit) { cout << i << " "; }cout << "\n";
    return 1;//팰린드롬이면 1
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    sieve();

    int n, ans = 0;
    cin >> n;
    while (1) {
        if (notprime[n] == 0 && check(n) == 1) {
            ans = n; break;
        }
        n++;
    }
    cout << ans << "\n";

    return 0;

}