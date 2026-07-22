/**
 *    author:  colaman
 *    github:  Amanthink
 *    created: 04.07.2026 11:40:30
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


// ================= USEFUL CONSTANTS =================
const ll inf = 1e18;        // a "big enough" number, used as infinity
const int mod = 1e9 + 7;    // common modulo used in many problems
const ld pi= acos(-1.0);   // value of pi

// ================= FAST IO =================
#define endl "\n"           // endl flushes (slow); "\n" doesn't (fast)

void solve(){
    string s;
    cin>>s;//bbacc
    //count of letters of a , b ,c 
    //we have to look for orders too a b c appears in sequence 
    int count[3]={0};//0->a,1->b,2->c
    int idx=0;
    bool t=true;
   for(int i=0;i<s.length()&&t==true;i++){
        if(s[i]=='a') {count[0]++;}
       else{
           t=false;
           idx=i;
       }
    }
    t=true;
    for(int i=idx;i<s.length()&&t==true;i++){
        if(s[i]=='b') {count[1]++; }
        else{
            t=false;
            idx=i;
        }
    }
   
    bool validTail = true;
    for (int i = idx; i < (int)s.length(); i++) {
        if (s[i] == 'c') count[2]++;
        else { validTail = false; break; }
    }

    bool flag1 = (count[0] > 0 && count[1] > 0 && count[2] > 0);
    bool flag2 = (count[2] == count[0] || count[2] == count[1]);

   
    if(validTail && flag1 && flag2) cout<<"YES"<<endl;//true
    else cout<<"NO"<<endl;//false
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

solve();

    return 0;
}