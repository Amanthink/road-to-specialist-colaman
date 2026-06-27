/**
 *    author:  colaman
 *    github:  Amanthink
 *    created: 26.06.2026 11:12:41
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

// ================= LOOP SHORTCUTS =================
//#define for(i,a,b) for (int i = (a); i < (b); i++)   // for(i=a;i<b;i++) -> FOR(i,a,b)
//#define rep(i,n) for(i,0,n)                          // for(i=0;i<n;i++) -> REP(i,n)
//#define rof(i,n) for (int i = (n)-1; i >= 0; i--)    // for(i=n-1;i>=0;i--) -> ROF(i,n)

// ================= USEFUL CONSTANTS =================
const ll inf = 1e18;        // a "big enough" number, used as infinity
const int mod = 1e9 + 7;    // common modulo used in many problems
const ld pi= acos(-1.0);   // value of pi

// ================= FAST IO =================
#define endl "\n"           // endl flushes (slow); "\n" doesn't (fast)

void brute_force_solve() {
    //brute force solution
    int a, b, c;
    cin >> a >> b >> c;

    int diff = 2 * b - a - c;

    if (diff == 0) {
        cout << "YES\n";
        return;
    }

    if (diff > 0) {

        // Increase a
        for (int i = 2; i <= (2 * b - c) / a; i++) {
            if (2 * b - a * i - c == 0) {
                cout << "YES\n";
                return;
            }
        }

        // Increase c
        for (int i = 2; i <= (2 * b - a) / c; i++) {
            if (2 * b - a - c * i == 0) {
                cout << "YES\n";
                return;
            }
        }

        cout << "NO\n";
    }
    else {

        // Increase b
        for (int i = 2; i <= (a + c) / b; i++) {
            if (2 * b * i - a - c == 0) {
                cout << "YES\n";
                return;
            }
        }

        cout << "NO\n";
    }
}
void optimal_solve() {
    int a, b, c;
    cin >> a >> b >> c;

    // Change a
    int x = 2 * b - c;
    if (x > 0 && x % a == 0) {
        cout << "YES\n";
        return;
    }

    // Change b
    x = a + c;
    if (x % 2 == 0) {
        x /= 2;
        if (x > 0 && x % b == 0) {
            cout << "YES\n";
            return;
        }
    }

    // Change c
    x = 2 * b - a;
    if (x > 0 && x % c == 0) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        optimal_solve();
    }

    return 0;
}