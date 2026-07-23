/**
 *    author:  colaman
 *    github:  Amanthink
 *    created: 23.07.2026 14:28:24
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

void solve(){
    int n;cin>>n;
    
    // Division is possible iff n*(n+1)/2 is even AND n%4==0 or n%4==3
    // The second condition is equivalent to n%4 != 1 and n%4 != 2
    if (n % 4 == 1 || n % 4 == 2) {
        cout << "NO\n";
        return;
    }
    
    cout << "YES\n";
    
    vector<int> set1, set2;
    
    if (n % 2 == 0) {
        // Even n: pair elements (i, n+1-i) and alternate which set gets them
        // Pairs: (1,n), (2,n-1), ..., (n/2, n/2+1)
        // Set1 gets odd-indexed pairs: (1,n), (3,n-2), (5,n-4), ...
        // Set2 gets even-indexed pairs: (2,n-1), (4,n-3), (6,n-5), ...
        for (int i = 1; i <= n / 2; i += 2) {
            set1.push_back(i);
            set1.push_back(n - i + 1);
        }
        for (int i = 2; i <= n / 2; i += 2) {
            set2.push_back(i);
            set2.push_back(n - i + 1);
        }
    } else {
        // Odd n: group consecutive numbers in sets of 4
        // Take groups [4k+1, 4k+2] for set1 and [4k+3, 4k+4] for set2
        for (int i = 1; i <= n; i += 4) {
            set1.push_back(i);
            set1.push_back(i + 1);
            if (i + 2 <= n) set2.push_back(i + 2);
            if (i + 3 <= n) set2.push_back(i + 3);
        }
    }
    
    cout << set1.size() << endl;
    for (int x : set1) {
        cout << x << " ";
    }
    cout << "\n";
    
    cout << set2.size() << endl;
    for (int x : set2) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}