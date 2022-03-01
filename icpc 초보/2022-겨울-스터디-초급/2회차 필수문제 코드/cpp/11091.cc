#include <bits/stdc++.h>
using namespace std;

int ci(char c) {
	if (c >= 'a' && c <= 'z') return c - 'a';
	if (c >= 'A' && c <= 'Z') return c - 'A';
	return -1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tc; cin >> tc;
	cin.ignore(1);
	while (tc--) {
		string s; 
		getline(cin, s);
        bitset<26> vis;
        
		for (char c : s) {
            int nc = ci(c);
			if (nc != -1) vis[nc] = 1;
		}

		if(vis.all()) cout<<"pangram\n";
		else {
			cout << "missing ";
			for (int i = 0; i < 26; ++i)
				if (!vis[i]) cout << (char)(i + 'a');
			cout << '\n';
		}
	}
	return 0;
}