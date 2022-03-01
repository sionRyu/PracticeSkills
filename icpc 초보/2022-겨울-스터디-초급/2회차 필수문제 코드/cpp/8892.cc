#include <bits/stdc++.h>
using namespace std;

int N;
string s[101];

int ispal(int x, int y){
    string str = s[x] + s[y];
    int ssz = (int)str.size();
    
    for(int i = 0; i < ssz/2; i++)
        if(str[i] != str[ssz - i - 1]) return 0;
    
    return 1;
}

void f(){
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) if(i!=j){
            if(ispal(i,j)) {
                cout<<s[i]<<s[j]<<'\n';
                return;
            }
        }
    cout << "0\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int tc; cin>>tc;
    while(tc--){
        cin >> N;
        for(int i = 0; i < N; i++) cin >> s[i];
        f();
    }
    
    return 0;
}