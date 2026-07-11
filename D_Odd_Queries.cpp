/**
 *    author:  colaman
 *    github:  Amanthink
 *    created: 09.07.2026 11:56:10
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
    int n,q;cin>>n>>q;
    vll a(n);
    vll prefix_sum(n);
    ll total_sum=0;
    for(i,0,n){ cin>>a[i];prefix_sum[i] = a[i];total_sum+=a[i];}
    for(i,1,n) prefix_sum[i] += prefix_sum[i-1];
    while(q--){
        ll l,r,k;cin>>l>>r>>k;
        l--;r--;
        ll final_sum = total_sum + (r-l+1)*k - (prefix_sum[r] - (l>0?prefix_sum[l-1]:0));
        if(final_sum%2==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
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