/**
 *    author:  colaman
 *    github:  Amanthink
 *    created: 23.07.2026 02:40:44
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
    string s;
    cin>>s;
    unordered_map<char,int> mp;
    for(auto c:s) mp[c]++;
    if(s.length()%2){
        //case whe it is odd length array 
        int cnt=0;//to track the number of odd frequency characters
        for(auto p:mp){
            if(p.ss%2) cnt++;
        }
        if(cnt>1) cout<<"NO SOLUTION\n";
        else {
            string first_half="",second_half="";
            char mid_char;
            for(auto p:mp){
                if(p.ss%2) mid_char=p.ff;
                first_half+=string(p.ss/2,p.ff);
            }
            second_half=first_half;
            reverse(all(second_half));
            cout<<first_half<<mid_char<<second_half<<"\n";
        }
    }
    else{
        //case when it is even length array
        for(auto p:mp){
            if(p.ss%2) {//if any character has odd frequency then it is not possible to form a palindrome
                cout<<"NO SOLUTION\n";
                return;
            }
        }
        string first_half="",second_half="";
        for(auto p:mp){
            first_half+=string(p.ss/2,p.ff);
        }
        second_half=first_half;
        reverse(all(second_half));
        cout<<first_half<<second_half<<"\n";
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
   solve();
 
    return 0;
