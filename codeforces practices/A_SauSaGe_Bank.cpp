#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    long long  ans=pow(2,n-k+1)+2*(k-1);
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}