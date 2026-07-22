#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

pair<ll, ll> solve() {
    ll n; cin >> n;
    
    auto ispalindrome = [](ll x) {
        string s = to_string(x);
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        return s == rev_s;
    };
    
    
    ll a = n % 12;  
    ll b = n - a;   
    
    while (a <= n && b >= 0) {
        if (ispalindrome(a)) {
            return {a, b};  
        }
        a += 12;
        b -= 12;
    }
    
    return {-1, -1};
}

int main() {
    int t; cin >> t;
    while (t--) {
        auto [a, b] = solve();
        if (a == -1) cout << -1 << "\n";
        else cout << a << " " << b << "\n";
    }
}