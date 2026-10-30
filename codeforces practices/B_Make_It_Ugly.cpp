#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    if ((*min_element(a.begin(), a.end())) == 
        (*max_element(a.begin(), a.end()))) {
      cout << "-1\n";
      return;
    }
 
    int B = a[0];
 
    vector<int> diff;
    int ans = n + 1;
    for (int i = 0; i < n; i++) {
      if (a[i] != B) {
        diff.push_back(i);
        ans = min(ans, i);
        ans = min(ans, n - i - 1);
      }
    }
 
    for (int i = 1; i < diff.size(); i++) {
      ans = min(ans, diff[i] - diff[i - 1] - 1);
    }
 
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--){
        solve();
    }
}