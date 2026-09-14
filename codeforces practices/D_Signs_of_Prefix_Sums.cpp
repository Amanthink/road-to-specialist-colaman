/**
 *    author:  colaman
 *    github:  Amanthink
 *    created: 08.09.2026 20:56:53
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

// ================= USEFUL CONSTANTS =================
const ll inf = 1e18;      // a "big enough" number, used as infinity
const int mod = 1e9 + 7;  // common modulo used in many problems
const ld pi = acos(-1.0); // value of pi

// ================= FAST IO =================
#define endl "\n" // endl flushes (slow); "\n" doesn't (fast)

int solve()
{
    int n;
    string s;
    cin >> n >> s;

    bool bad = s[0] == '0';
    for (int i = 1; i < n; i++)
    {
        if (s[i] == '0' && s[i - 1] == '0')
            bad = true;
    }

    if (bad)
    {
        cout << -1 << '\n';
        return 1;
    }

    bool ok = true;
    int len = 0;
    char c = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            if (len % 2 == 0)
                ok = false;
            len = 0;
            c = 0;
        }
        else
        {
            if (c && c != s[i])
                ok = false;
            c = s[i];
            len++;
        }
    }

    if (ok)
    {
        cout << 1 << '\n';
        return 1;
    }

    bool three = false;
    int i = 0;
    while (i < n)
    {
        if (s[i] == '0')
        {
            i++;
            continue;
        }
        int j = i;
        while (j < n && s[j] == s[i])
            j++;

        if (j - i == 2 && i > 0 && j < n && s[i - 1] != '0' && s[j] != '0')
        {
            three = true;
        }
        i = j;
    }

    cout << (three ? 3 : 2) << '\n';
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}