#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
vector<int> xlist;
int l[10000], r[10000], N,v[20002];
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> l[i] >> r[i];
		xlist.push_back(l[i]);
		xlist.push_back(r[i]);
	}
	sort(all(xlist));
	xlist.erase(unique(all(xlist)), xlist.end());
    memset(v, -1, sizeof v);
	for (int i = 0; i < N; i++) {
		l[i] = lower_bound(all(xlist), l[i]) - xlist.begin();
		r[i] = lower_bound(all(xlist), r[i]) - xlist.begin();
        for (int j = l[i]; j <= r[i]; j++) v[j] = i;
	}
    
	vector<int> ans;
	for (int i = 0; i <= 20001; i++)
		ans.push_back(v[i]);
	sort(all(ans));
	ans.erase(unique(all(ans)), ans.end());
	cout << (int)ans.size() - 1;
	return 0;
}