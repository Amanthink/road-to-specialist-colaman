/**
 *    author:  colaman
 *    github:  Amanthink
 *    created: 02.09.2026 12:14:32
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
    int n, tables, chairs;
    cin >> n >> tables >> chairs;

    string buf;
    cin >> buf;

    ll emptyTables = tables;
    ll freeOpen = 0;
    ll seated = 0;
    ll fillerA = 0;

    for (ll i = 0; i < n; ++i) {
        char c = buf[i];
        // Process each character in the input string
        if (c == 'I') {
            if (emptyTables > 0) {// If there are empty tables, seat the person at a new table
                emptyTables--;
                freeOpen += chairs - 1;// The remaining chairs at this table are now free
                seated++;
            }
        } else if (c == 'E') {// If the person is extroverted, they can sit at any free chair in a filled table 
            if (freeOpen > 0) {
                freeOpen--;
                seated++;
            } else if (fillerA > 0 && emptyTables > 0) {// If there are no free chairs but there are filled tables and empty tables, seat the person at a new table
                fillerA--;
                emptyTables--;
                freeOpen += chairs - 1;
                seated++;
            }
        } else {
            if (freeOpen > 0) {
                freeOpen--;
                seated++;
                // If there are empty tables, add a filled table
                if (emptyTables > 0) fillerA++;
            } else if (emptyTables > 0) {
                emptyTables--;
                freeOpen += chairs - 1;
                seated++;
            }
        }
    }
    printf("%lld\n", seated);
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