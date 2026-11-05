/**
 *    author:  colaman
 *    github:  Amanthink
 *    created: 04.11.2026 20:31:48
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
void smallest_prime_factor(vi &spf, int n)
{ // Function to compute the smallest prime factor for every number up to n
    for (int i = 2; i <= n; ++i)
    {
        if (spf[i] == 0)
        { // i is prime
            for (int j = i; j <= n; j += i)
            {
                if (spf[j] == 0)
                {
                    spf[j] = i;
                }
            }
        }
    }
}
void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int popular = 0;

    for (int p : a)
    {
        int cnt = 0;

        for (int x : a)
        {
            if (x % p == 0)
            {
                cnt++;
            }
        }

        popular = max(popular, cnt);
    }

    cout << n - popular << '\n';
}

/*void solve(){
    int n;cin>>n;
    vi a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    int maxi = *max_element(all(a));
    vi freq(maxi + 1), div(maxi + 1);
    for (int x : a) {
        ++freq[x];
    }

    vi spf(maxi + 1);
    smallest_prime_factor(spf,maxi);

    for (int value = 1; value <= maxi; ++value) {// Loop through all possible values in the array
        if (freq[value] == 0) continue;

        vi divisors{1};
        int rem = value;
        while (rem > 1) {
            int prime = spf[rem];
            int power = 0;
            while (rem % prime == 0) {
                rem /= prime;
                ++power;
            }

            int csize = sz(divisors);
            int mtplr = 1;
            for (int exp = 1; exp <= power; ++exp) {
                mtplr *= prime;
                for (int i = 0; i < csize; ++i) {
                    divisors.pb(divisors[i] * mtplr);
                }
            }
        }

        for (int divisor : divisors) {
            div[divisor] += freq[value];
        }
    }

    int popular = INT_MIN;
    for (int value : a) {
        popular = max(popular, div[value]);
    }
    cout << n - popular << endl;
}
    */

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