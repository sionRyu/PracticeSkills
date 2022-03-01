#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,arr[10];

void solve(int cur, int idx){
    //cur는 현재 들어갈 숫자, idx는 현재 들어갈 인덱스
    if(idx==m+1){
        for(int i=1;i<=m;i++){cout<<arr[i]<<" ";}
        cout<<"\n";
        return;
    }
    if(cur==n+1){return;}
    arr[idx]=cur;
    //idx에 cur을 넣을 경우
    solve(cur+1,idx+1);
    solve(cur+1,idx);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;
    solve(1,1);
    return 0;
}