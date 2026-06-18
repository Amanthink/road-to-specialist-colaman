#include<bits/stdc++.h>
using namespace std;
bool check(vector<int> &vec){
    int n = vec.size();
    for(int i = 0; i < n; i++){
        if(abs(vec[i]-vec[n - 1 ]) > 1) return false;
    }
    return true;
}
int solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(int &x : a) cin>>x;
    unordered_map<int,vector<int>> freq;
    for(int i = 0; i < n; i++) freq[a[i]].push_back(i);
    
    for(auto &[key, vec] : freq){
       if(check(vec)){ cout<<"YES"<<endl; return 0; }
       else { cout<<"NO"<<endl; return 0; }
    }
}
int main(){
    int t;cin>>t;
    while(t--){ solve(); }
}