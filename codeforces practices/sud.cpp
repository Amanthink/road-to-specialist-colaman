#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long w[52];
    w[0] = w[1] = 1;
    for (int i = 2; i <= 51; i++) w[i] = w[i - 1] + w[i - 2];

    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;
        cout << min(w[x], y) << "\n";
    }
    return 0;
}