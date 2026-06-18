#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        string a1, alast;
        cin >> a1 >> alast;

        ll ones_a1    = count(a1.begin(), a1.end(), '1');
        ll ones_alast = count(alast.begin(), alast.end(), '1');
        
        ll ones_xor = 0;
        for(int i = 0; i < n; i++)
            if(a1[i] != alast[i]) ones_xor++;

        ll A = ones_a1    * (n - ones_a1);   
        ll B = ones_alast * (n - ones_alast); 
        ll C = ones_xor   * (n - ones_xor);   

        
        ll total = (1LL << k) + 1;  

        ll base = total / 3;  
        ll rem  = total % 3;  

        ll count10, count01, count11;
        if(rem == 0) {
            count10 = count01 = count11 = base;
        } else {
            count10 = count01 = base + 1;
            count11 = base;
        }
        ll ans = count10 * A + count01 * B + count11 * C;
        cout << ans << "\n";
    }
}