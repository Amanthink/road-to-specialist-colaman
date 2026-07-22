#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> b(n);
    for(auto &x : b) cin >> x;

    sort(b.begin(), b.end(), greater<long long>());

    if(n == 2) {
        cout << b[0] << " " << b[1] << "\n";
        return;
    }

    bool ok = true;
    for(int i = 0; i < n-2; i++) {
        if(b[i] % b[i+1] != b[i+2]) {
            ok = false;
            break;
        }
    }

    if(ok) cout << b[0] << " " << b[1] << "\n";
    else cout << -1 << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}