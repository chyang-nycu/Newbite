#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q, n, a, b;
    cin>>q;
    while(q--){
        cin>>n>>a>>b;
        int cnt = n;
        n++;
        while((a+b) != n && (n > 3)){
            cnt /= 2;
            if(a > n/2) a = n - a;
            if(b > n/2) b = n - b;
            n -= n/2;
        }
        cout<<cnt<<'\n';
    }
}
