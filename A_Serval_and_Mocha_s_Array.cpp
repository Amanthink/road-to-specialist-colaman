#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        bool flag = false;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int g = __gcd(v[i], v[j]);
                if (g <= 2) {
                    flag = true;
                    break; 
                }
            }
            if (flag) break; 
        }

        if (flag)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}