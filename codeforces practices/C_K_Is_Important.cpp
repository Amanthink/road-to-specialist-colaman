#include<bits/stdc++.h>
using namespace std;

 
void solve() {
   int n,k;
   cin>>n>>k;
   vector<long long> a(n);
    for (auto &x : a) cin >> x;
    long long sum=0;
    for (auto x : a) sum += x;
    int p = min(k-1,n-k+1);// number of pairs we can take from the ends
    long long deleted=0;
    for (int j=1;j<=p;j++) {
        deleted += min(a[j-1], a[n-j]); 
    }
    if (p < k - 1) {
        long long deleted_middle = 0;
        for (int i=p;i<=n-p-1;i++) deleted_middle+= a[i];
        deleted+=deleted_middle;
    }
    cout << sum-deleted << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
     solve();
    }
}