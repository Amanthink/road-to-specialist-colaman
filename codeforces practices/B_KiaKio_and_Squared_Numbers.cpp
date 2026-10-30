#include <bits/stdc++.h>
using namespace std;

long long f(long long x) {
    long long s = 0;
    while (x > 0) {
        long long d = x % 10;
        s += d * d;
        x /= 10;
    }
    return s;
}

void solve(){
    int n;
    cin >> n;
    const int T = 60; // safety margin
    unordered_map<long long,long long> cnt;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s; // handle overflow by reading as string
        long long cur = 0;
        for (char c : s) cur += (long long)(c-'0')*(c-'0'); // first application
        for (int t = 0; t < T; t++) cur = f(cur);
        cnt[cur]++;
    }
    long long ans = 0;
    for (auto &p : cnt) {
        long long c = p.second;
        ans += c*(c-1)/2;
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
    }
}