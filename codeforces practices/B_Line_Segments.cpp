#include <bits/stdc++.h>
using namespace std;

#define int double

void solve() {
    double n; 
    cin >> n;
    double px, py, qx, qy; 
    cin >> px >> py >> qx >> qy;
    
    double dis = sqrt((px - qx) * (px - qx) + (py - qy) * (py - qy));
    
    double suma = 0;
    vector<double> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
        suma += l[i];
    }
    
    if (n == 1) {
        if (dis == l[0]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        return;
    }
    else if (n == 2) {
        if (px == qx && py == qy) {
            if (l[0] == l[1]) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
            return;
        }
    }
    l.push_back(dis);
    suma += dis;
    bool possible = true;
    for (int i = 0; i < l.size(); i++) {
        if (l[i] > suma - l[i]) {
            possible = false;
            break;
        }
    }
    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    while (t--) {
        solve();
    }
}