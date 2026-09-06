/**
 *    author:  colaman
 *    github:  Amanthink
 *    created: 05.09.2026 21:48:14
**/
#include <bits/stdc++.h>
using namespace std;

// ================= TYPES (long name -> short name) =================
typedef long long ll;                 // long long -> ll
typedef unsigned long long ull;       // unsigned long long -> ull
typedef long double ld;               // long double -> ld

typedef pair<int,int> pii;            // pair<int,int> -> pii
typedef pair<ll,ll> pll;              // pair<long long,long long> -> pll

typedef vector<int> vi;               // vector<int> -> vi
typedef vector<ll> vll;               // vector<long long> -> vll
typedef vector<pii> vpii;             // vector<pair<int,int>> -> vpii
typedef vector<vector<int>> vvi;      // vector<vector<int>> (2D grid) -> vvi
typedef vector<string> vs;            // vector<string> -> vs

typedef map<int,int> mii;             // map<int,int> -> mii
typedef set<int> si;                  // set<int> -> si
typedef unordered_map<int,int> umii;  // unordered_map<int,int> -> umii

// ================= FUNCTION/METHOD SHORTCUTS =================
#define pb push_back               // v.push_back(x) -> v.pb(x)
#define eb emplace_back            // v.emplace_back(x) -> v.eb(x)
#define po pop_back                // v.pop_back() -> v.po()
#define mp make_pair                // make_pair(a,b) -> mp(a,b)
#define ff first                    // p.first -> p.ff
#define ss second                   // p.second -> p.ss

#define all(x) (x).begin(), (x).end()   // v.begin(),v.end() -> all(v)
#define sz(x) (int)(x).size()           // (int)v.size() -> sz(v)
#define rsz(x,n) (x).resize(n)          // v.resize(n) -> rsz(v,n)



// ================= USEFUL CONSTANTS =================
const ll inf = 1e18;        // a "big enough" number, used as infinity
const int mod = 1e9 + 7;    // common modulo used in many problems
const ld pi= acos(-1.0);   // value of pi

// ================= FAST IO =================
#define endl "\n"           // endl flushes (slow); "\n" doesn't (fast)

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);

    int left = -1, right = -1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        if (a[i] != 0) {
            if (left == -1)
                left = i;

            right = i;
        }
    }

    // No possible pair of 1s
    if (left == -1 || left == right) {
        for (int i = 0; i < n; i++) {
            // Replace -1 by 0
            if (a[i] == -1)
                a[i] = 0;

            cout << a[i] << " ";
        }
        cout << '\n';
        return;
    }

    // Everything becomes 0 first
    for (int i = 0; i < n; i++) {
        a[i] = 0;
    }

    // Put 1s at the two farthest possible endpoints
    a[left] = 1;
    a[right] = 1;

    // Print
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}