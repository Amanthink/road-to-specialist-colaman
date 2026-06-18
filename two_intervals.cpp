#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int l = max(a, c);
    int r = min(b, d);

    if (l <= r)
        cout << l << " " << r << '\n';
    else
        cout << -1 << '\n';   // or whatever the problem requires
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}