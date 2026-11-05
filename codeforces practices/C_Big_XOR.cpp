
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int p = 1;
    while (p * 2 <= n) {
        p *= 2;
    }

    int k = 2 * p - 1;

    // XOR of numbers from 1 to n
    int x;

    if (n % 4 == 0) x = n;
    else if (n % 4 == 1) x = 1;
    else if (n % 4 == 2) x = n + 1;
    else x = 0;

    // XOR when every element is doubled
    int base = 2 * x;

    // Required target
    int target = 2 * k;

    if ((__builtin_popcount(base) % 2) !=
        (__builtin_popcount(target) % 2)) {
        target++;
    }

    // Required XOR difference
    int diff = base ^ target;

    vector<int> d(n, 1);

    // Find which powers of two should NOT be doubled
    int prev = 0;

    for (int j = 0; (1 << j) <= p; j++) {
        int bit = (diff >> j) & 1;

        int cur = bit ^ prev;

        if (cur == 1) {
            d[(1 << j) - 1] = 0;
        }

        prev = cur;
    }

    for (int i = 0; i < n; i++) {
        cout << d[i] << " ";
    }

    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int noTsts;
    cin >> noTsts;

    while (noTsts--) {
        solve();
    }

    return 0;
}
