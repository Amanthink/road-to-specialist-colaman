/**
 *    author:  colaman
 *    github:  Amanthink
 *    created: 31.08.2026 14:11:36
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
#include <bits/stdc++.h>

ll getLen(ll x) {
    if (x <= 1) return 1;

    return 2 * getLen(x / 2) + 1;
}

ll countOnes(ll x, ll l, ll r) {
    if (x == 0) return 0;

    if (x == 1) {
        return (l <= 1 && 1 <= r);
    }

    ll half = getLen(x / 2);

    ll ans = 0;

    // Left part: [1 ... half]
    if (l <= half) {
        ans += countOnes(x / 2, l, min(r, half));
    }

    // Middle element
    ll mid = half + 1;

    if (l <= mid && mid <= r) {
        ans += x % 2;
    }

    // Right part
    if (r > mid) {
        ans += countOnes(
            x / 2,
            max(1LL, l - mid),
            r - mid
        );
    }

    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, l, r;
    cin >> n >> l >> r;

    cout << countOnes(n, l, r) << '\n';

    return 0;
}