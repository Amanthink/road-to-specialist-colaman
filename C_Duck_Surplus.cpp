//what we have to do 
/*Choose two adjacent piles such that the left pile contains more ducks than the right pile. Ja swaps these two piles, and then adds the number of ducks in the new left pile to the new right pile.
Formally, choose an index i
 such that 1≤i<n
 and ai>ai+1
. Then replace the adjacent pair (ai,ai+1)
 with (ai+1,ai+ai+1)
*/
#include <bits/stdc++.h>
using namespace std;
int sol(){
    int n;cin>>n;
    vector<int64_t> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            int64_t temp=a[i]+a[i+1];
            a[i+1]=temp;;
        }
    }
    cout<<*max_element(a.begin(),a.end())<<endl;
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--){ 
        sol();
    }
    return 0;
}