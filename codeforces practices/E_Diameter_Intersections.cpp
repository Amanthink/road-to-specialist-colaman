/**
 *    author:  colaman
 *    github:  Amanthink
 *    created: 07.08.2026 21:52:10
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


int n;
vector<vector<int>> vv;
vector<int> p, d;

void helper1(int a, int b) {
    p[a] = b;

    for (int v : vv[a]) {
        if (v != b) {
            d[v] = d[a] + 1;
            helper1(v, a);
        }
    }
}

int helper2(int a, int b, int c, int l, set<int>& s) {
    int m = c, cnt = 0;

    for (int v : vv[a]) {
        if (v != b) {
            int r = helper2(v, a, c + 1, l, s);

            if (r == l)
                cnt++;

            m = max(m, r);
        }
    }

    if (cnt >=2)
        s.insert(c);

    return m;
}

void solve() {
    cin >> n;

    vv.assign(n + 1, vector<int>());

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        vv[u].push_back(v);
        vv[v].push_back(u);
    }

    p.assign(n + 1, 0);
    d.assign(n + 1, 0);

    helper1(1, 0);

    int a = 1;

    for (int i = 1; i <= n; i++)
        if (d[i] > d[a])
            a = i;

    d[a] = 0;

    helper1(a, 0);

    int b = 1;

    for (int i = 1; i <= n; i++)
        if (d[i] > d[b])
            b = i;

    int k = d[b];
    int l = k / 2;

    int c = b;
    vector<int> w;

    while (c != 0) {
        w.push_back(c);
        c = p[c];
    }

    int u = w[l];
    int v = w[l + 1];

    set<int> x, y, z;

    x.insert(l);
    y.insert(l);

    helper2(u, v, 0, l, x);
    helper2(v, u, 0, l, y);

    for (int i : x) {
        for (int j : y) {
            z.insert(1 + i + j);
        }
    }

    cout << z.size();

    for (int i : z)
        cout << " " << i;

    cout << "\n";
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