#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[500000];
int n, m;
void binary(int v) {
	int cnt = 0;
	auto lower = lower_bound(arr, arr + n, v);
	auto upper = upper_bound(arr, arr + n, v);
	cnt = upper - lower;
	printf("%d ", cnt);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr+n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int tmp;
		scanf("%d", &tmp);
		binary(tmp);
	}
	
	printf("\n");

	return 0;
}