/**
 *    author:  colaman (fixed)
 *    created: 17.07.2026
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

void solve(){
    int n; ll c;
    cin >> n >> c;
    vll a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<ll> dp(n+3, LLONG_MIN/4);
    dp[n] = 0;
    for (int i = n-1; i >= 0; --i){
        ll take1 = dp[i+1] + a[i] - c;
        ll take2 = LLONG_MIN/4;
        if (i+1 < n) take2 = dp[i+2] + max(a[i], a[i+1]) - c;
        dp[i] = max(take1, take2);
    }
    cout << dp[0] << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; if (!(cin >> t)) return 0;
    while (t--) solve();
    return 0;
}
