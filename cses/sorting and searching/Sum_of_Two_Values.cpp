/**
 *    author:  colaman
 *    github:  Amanthink
 *    created: 25.07.2026 13:30:44
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
    int n,target;cin>>n>>target;
    vll arr(n);
    for(i,0,n)cin>>arr[i];  
    vll temp=arr;
    sort(all(temp));
    //sum==target
    int l=0,r=n-1;
    ll ele1,ele2;
    while(l<r){
        ll sum=temp[l]+temp[r];
        if(sum==target){
            ele1=temp[l];
            ele2=temp[r];
            break;
        }
        else if(sum<target)l++;
        else r--;
    }
    //if there is no such pair print IMPOSSIBLE
    if(l>=r){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    //print the indices of ele1 and ele2
    ll id1=-1,id2=-1;
    for(i,0,n){
        if(arr[i]==ele1){
           id1=i+1;
        }
    }
    for(i,0,n){
        if(arr[i]==ele2){
            id2=i+1;
            break;
        }
    }
    cout<<min(id1,id2)<<" "<<max(id1,id2)<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
solve();

    return 0;
}