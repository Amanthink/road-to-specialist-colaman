
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

int qpow(int a, int b) {
  a %= mod;
  int res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod, b >>= 1;
  }
  return res;
}

void solve() {
  int n, m, r, c; cin >> n >> m >> r >> c;
  int ans = qpow(2, n * m - (n - r + 1) * (m - c + 1));
  cout << ans << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T; cin >> T; while (T--) solve();
  return 0;
}