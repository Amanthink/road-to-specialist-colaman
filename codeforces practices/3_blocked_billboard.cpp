/**
 *    author:  colaman
 *    github:  Amanthink
 *    created: 14.09.2026 15:44:05
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

void solve(){
    pair<int,int> r1l,r1u;
    cin>>r1l.ff>>r1l.ss;
    cin>>r1u.ff>>r1u.ss;

    pair<int,int> r2l,r2u;
    cin>>r2l.ff>>r2l.ss;
    cin>>r2u.ff>>r2u.ss;

    pair<int,int> trl,tru;
    cin>>trl.ff>>trl.ss;
    cin>>tru.ff>>tru.ss;

    int area1=(r1u.ff-r1l.ff)*(r1u.ss-r1l.ss);
    int area2=(r2u.ff-r2l.ff)*(r2u.ss-r2l.ss);

    // Check overlap with rectangle 1
    int overlap_x=max(0, min(r1u.ff,tru.ff)-max(r1l.ff,trl.ff));
    int overlap_y=max(0, min(r1u.ss,tru.ss)-max(r1l.ss,trl.ss));

    area1-=overlap_x*overlap_y;

    // Check overlap with rectangle 2
    overlap_x=max(0, min(r2u.ff,tru.ff)-max(r2l.ff,trl.ff));
    overlap_y=max(0, min(r2u.ss,tru.ss)-max(r2l.ss,trl.ss));

    area2-=overlap_x*overlap_y;

    cout<<area1+area2<<endl;
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