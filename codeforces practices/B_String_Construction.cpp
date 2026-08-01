/**
 *    author:  colaman
 *    github:  Amanthink
 *    created: 29.07.2026 20:50:45
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

static string build_even_length_string(int n, int k) {
    string s;
    if (k % 2 == 0) {
        int side = k / 2 + 1;
        int middle = (n - k - 2) / 2;
        s.append(side, '0');
        for (int i = 0; i < middle; i++) s += "10";
        s.append(side, '1');
    } else {
        int left = (k + 1) / 2;
        int right = (k + 3) / 2;
        int middle = (n - k - 3) / 2;
        s.append(left, '0');
        s.append(right, '1');
        for (int i = 0; i < middle; i++) s += "01";
        s.push_back('0');
    }
    return s;
}

void solve() {
    int n, k;
    cin >> n >> k;

    if (n == 1) {
        if (k == 0) cout << "0\n";
        else cout << "-1\n";
        return;
    }

    if (k > n - 2) {
        cout << "-1\n";
        return;
    }

    if (n % 2 == 0) {
        cout << build_even_length_string(n, k) << '\n';
        return;
    }

    if (k == n - 2) {
        cout << string(n / 2, '0') + string(n / 2 + 1, '1') << '\n';
        return;
    }

    string s = build_even_length_string(n - 1, k);
    s.push_back(s.back() == '0' ? '1' : '0');
    cout << s << '\n';
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
