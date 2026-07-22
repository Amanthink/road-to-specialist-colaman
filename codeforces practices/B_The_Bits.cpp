/**
 *    author:  colaman
 *    github:  Amanthink
 *    created: 08.07.2026 09:25:00
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
#define for(i,a,b) for (int i = (a); i < (b); i++)   // for(i=a;i<b;i++) -> FOR(i,a,b)
#define rep(i,n) for(i,0,n)                          // for(i=0;i<n;i++) -> REP(i,n)
#define rof(i,n) for (int i = (n)-1; i >= 0; i--)    // for(i=n-1;i>=0;i--) -> ROF(i,n)

// ================= USEFUL CONSTANTS =================
const ll inf = 1e18;        // a "big enough" number, used as infinity
const int mod = 1e9 + 7;    // common modulo used in many problems
const ld pi= acos(-1.0);   // value of pi

// ================= FAST IO =================
#define endl "\n"           // endl flushes (slow); "\n" doesn't (fast)
//function to calculate nCr
int combi(int n,int r){// 4 1
    if(r>n){return 0;}//false
    if(r==0||r==n){return 1;}//false;
    r=min(r,n-r);//4c1  
    int res=1;
    for(i,0,r){//i=0,1
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}
void solve(){
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    long long  zero = 0, oneone = 0, onezero = 0, zerozero = 0;
    for (i,0,n) {
        if (a[i] == '0') zero++;
        if (a[i] == '1' && b[i] == '1') oneone++;
        if (a[i] == '1' && b[i] == '0') onezero++;
        if (a[i] == '0' && b[i] == '0') zerozero++;
    }

    cout << (zero * onezero) + (oneone * zerozero) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}