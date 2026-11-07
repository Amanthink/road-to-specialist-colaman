/**
 *    author:  colaman
 *    github:  Amanthink
 *    created: 06.11.2026 20:32:50
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

// ================= FUnCTIOn/METHOD SHORTCUTS =================
#define pb push_back    // v.push_back(x) -> v.pb(x)
#define eb emplace_back // v.emplace_back(x) -> v.eb(x)
#define po pop_back     // v.pop_back() -> v.po()
#define mp make_pair    // make_pair(a,b) -> mp(a,b)
#define ff first        // p.first -> p.ff
#define ss second       // p.second -> p.ss

#define all(x) (x).begin(), (x).end() // v.begin(),v.end() -> all(v)
#define sz(x) (int)(x).size()         // (int)v.size() -> sz(v)
#define rsz(x, n) (x).resize(n)       // v.resize(n) -> rsz(v,n)

// ================= USEFUL COnSTAnTS =================
const ll inf = 1e18;      // a "big enough" number, used as infinity
const int mod = 1e9 + 7;  // common modulo used in many problems
const ld pi = acos(-1.0); // value of pi

// ================= FAST IO =================
#define endl "\n" // endl flushes (slow); "\n" doesn't (fast)
const int N = 200005;

vector<int> prime; // making a vector to store all prime numbers up to N

void sieve_of_eras()
{
    vector<bool> isPrime(N, true);

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < N; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j < N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i < N; i++)
    {
        if (isPrime[i])
            prime.push_back(i);
    }
}

void solve()
{
    int n;
    cin >> n;
    vll ans;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        ans.push_back(*upper_bound(prime.begin(), prime.end(), a));
    }
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve_of_eras();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}