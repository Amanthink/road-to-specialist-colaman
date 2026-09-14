#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1000000007;

ll modPow(ll a, ll b) {
    ll result = 1;

    while (b > 0) {
        if (b & 1) {
            result = result * a % MOD;
        }

        a = a * a % MOD;
        b >>= 1;
    }

    return result;
}

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= MOD;
    }

    ll suffix = 0;
    ll pairSum = 0;

    for (int i = n - 1; i >= 0; i--) {
        pairSum = (pairSum + a[i] * suffix) % MOD;
        suffix = (suffix + a[i]) % MOD;
    }

    // Number of ways to choose 2 distinct balls
    ll pairs = 1LL * n * (n - 1) / 2;

    // answer = pairSum / pairs (mod MOD)
    ll inversePairs = modPow(pairs % MOD, MOD - 2);

    ll answer = pairSum * inversePairs % MOD;

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}