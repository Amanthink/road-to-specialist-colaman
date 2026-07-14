/**
 *    author:  colaman
 *    github:  Amanthink
 *    created: 12.07.2026 20:34:48
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

vector<ll> pw2(200000 + 5);

ll mod_pow2(int exp) {
    return pw2[exp];
}

// ================= FAST IO =================
#define endl "\n"           // endl flushes (slow); "\n" doesn't (fast)

void solve(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int blocks = 0;
    int consecutive_pairs = 0;
    bool has_minus_one = false;

    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && a[j] == a[i]) j++;
        blocks++;
        if (a[i] == -1) {
            has_minus_one = true;
        } else if (i > 0 && a[i - 1] + 1 == a[i]) {
            consecutive_pairs++;
        }
        i = j;
    }

    ll base = mod_pow2(n - blocks);
    ll ans = base;
    if (has_minus_one) {
        ans = ans * (consecutive_pairs + 1LL) % mod;
    }
    cout << ans % mod << '\n';
}
/*void func(vi &a,int i,bool even,int &cnt,int sum){
    if(sum==0){
        cnt++;
        cnt%=mod;
    }
    if(i==a.size())return;
    //take current element
    if(even){
        func(a,i+1,false,cnt,sum+a[i]);
    }
    else{
        func(a,i+1,true,cnt,sum-a[i]);
    }
    //backtrack and not take current element
    func(a,i+1,even,cnt,sum);
    
 }
void solve_by_recursion(){
    int n;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    bool even=true;
    int cnt=0;
    func(a,0,even,cnt,0);
 }
    */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pw2[0] = 1;
    for (int i = 1; i < (int)pw2.size(); i++) {
        pw2[i] = (pw2[i - 1] * 2) % mod;
    }

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}