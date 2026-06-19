//sum of minimum elements till now 
#include <bits/stdc++.h>
using namespace std;
int solve(){
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long sum=0;
    int minm=INT_MAX;
    for(int i=0;i<n;i++){   
        minm=min(minm,a[i]);
        sum+=minm;
    }
    cout<<sum<<endl;
    return 0;   
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--){ 
        solve();
    }
    return 0;
}