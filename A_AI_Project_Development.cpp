#include<bits/stdc++.h>
using namespace std;

int solve(){
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    int t1 = (n + x + y - 1) / (x + y);

    
    int t_x = x * z;
    int t2;
    if(t_x >= n){
        t2 = (n + x - 1) / x;
    } else {
        int remaining = n - t_x;
        t2 = z + (remaining + x + 10*y - 1) / (x + 10*y);
    }

    cout << min(t1, t2) << "\n";
    return 0;
}

int main(){
    int t; cin >> t;
    while(t--){ solve(); }
}