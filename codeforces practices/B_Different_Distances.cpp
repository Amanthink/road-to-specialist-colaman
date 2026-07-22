#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> ans;
        ans.reserve(4 * n);

        for(int x = 1; x <= n; x++) ans.push_back(x);          
        for(int x = 1; x <= n; x++) ans.push_back(x);         
        for(int x = 1; x <= n; x++) ans.push_back(x % n + 1);  
        for(int x = 1; x <= n; x++) ans.push_back(x);         

        for(int i = 0; i < 4*n; i++){
            cout << ans[i];
            if(i < 4*n - 1) cout << " ";
            else cout << "\n";
        }
    }

    return 0;
}