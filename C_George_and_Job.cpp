#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<long long> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i];
    }

    vector<long long> seg(n + 2, 0);

    for (int i = 1; i + m - 1 <= n; i++) {
        seg[i] = pref[i + m - 1] - pref[i - 1];
    }

    vector<vector<long long>> dp(n + m + 5,
                                 vector<long long>(k + 1, 0));

    for (int i = n - m + 1; i >= 1; i--) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = max(
                dp[i + 1][j],
                seg[i] + dp[i + m][j - 1]
            );
        }
    }

    cout << dp[1][k] << '\n';
    return 0;
}