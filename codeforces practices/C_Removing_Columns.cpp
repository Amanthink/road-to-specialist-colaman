/**
 *    author:  colaman
 *    github:  Amanthink
 *    created: 07.11.2026 16:12:28
 **/
#include <bits/stdc++.h>
using namespace std;

// ================= TYPES (long name -> short name) =================
typedef long long ll;           // long long -> ll
typedef unsigned long long ull; // unsigned long long -> ull
typedef long double ld;         // long double -> ld

typedef pair<int, int> pii; // pair<int,int> -> pii
typedef pair<ll, ll> pll;   // pair<long long,long long> -> pll

typedef vector<int> vi;          // vector<int> -> vi
typedef vector<ll> vll;          // vector<long long> -> vll
typedef vector<pii> vpii;        // vector<pair<int,int>> -> vpii
typedef vector<vector<int>> vvi; // vector<vector<int>> (2D grid) -> vvi
typedef vector<string> vs;       // vector<string> -> vs

typedef map<int, int> mii;            // map<int,int> -> mii
typedef set<int> si;                  // set<int> -> si
typedef unordered_map<int, int> umii; // unordered_map<int,int> -> umii

// ================= FUNCTION/METHOD SHORTCUTS =================
#define pb push_back    // v.push_back(x) -> v.pb(x)
#define eb emplace_back // v.emplace_back(x) -> v.eb(x)
#define po pop_back     // v.pop_back() -> v.po()
#define mp make_pair    // make_pair(a,b) -> mp(a,b)
#define ff first        // p.first -> p.ff
#define ss second       // p.second -> p.ss

#define all(x) (x).begin(), (x).end() // v.begin(),v.end() -> all(v)
#define sz(x) (int)(x).size()         // (int)v.size() -> sz(v)
#define rsz(x, n) (x).resize(n)       // v.resize(n) -> rsz(v,n)

// ================= LOOP SHORTCUTS =================

// ================= USEFUL CONSTANTS =================
const ll inf = 1e18;      // a "big enough" number, used as infinity
const int mod = 1e9 + 7;  // common modulo used in many problems
const ld pi = acos(-1.0); // value of pi

// ================= FAST IO =================
#define endl "\n" // endl flushes (slow); "\n" doesn't (fast)

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<string> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<bool> sorted(n - 1, false);

    int ans = 0;

    for (int j = 0; j < m; j++)
    {
        bool remove = false;

        // Check column-wise
        for (int i = 0; i < n - 1; i++)
        {
            if (!sorted[i] && a[i][j] > a[i + 1][j])
            {
                remove = true;
                break;
            }
        }

        if (remove)
        {
            ans++;
        }
        else
        {
            // Mark pairs that are now sorted
            for (int i = 0; i < n - 1; i++)
            {
                if (a[i][j] < a[i + 1][j])
                    sorted[i] = true;
            }
        }
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

  solve();

    return 0;
}