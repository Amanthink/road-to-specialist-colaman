
#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  const int M = int(2e5) + 10;
  // Precompute the number of operations needed to reduce each number to 0
  vector<int> ops(M);
  for (int i = 0; i < M; i++) {
    ops[i] = 0;
    int x = i;
    while (x > 0) {
      ops[i] += 1;
      x /= 3;
    }
  }
  // Compute the prefix sums of the operations
  vector<int> pref(M + 1);
  for (int i = 0; i < M; i++) {
    pref[i + 1] = pref[i] + ops[i];
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int l, r;
    cin >> l >> r;
    // Calculate the total number of operations needed
    int ans = pref[r + 1] - pref[l];
    ans += ops[l];
    cout << ans << '\n';
  }
  return 0;
}
