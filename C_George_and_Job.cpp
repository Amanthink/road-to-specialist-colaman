
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k;
    cin>>n>>m>>k;   
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //holding prefix sum to calculate sum of any window in O(1) time
    vector<int>prefix(n+1,0);
    for(int i=1;i<=n;i++){
        prefix[i]=prefix[i-1]+arr[i-1];
    }   
    //calculating sum of all windows of size m and storing them in a vector
    vector<int>window_sum;
    for(int i=0;i<=n-m;i++){
        window_sum.push_back(prefix[i+m]-prefix[i]);
    }   
    //sorting the window sums in descending order and summing up the top k sums
    sort(window_sum.rbegin(),window_sum.rend());
    long long ans=0;

    for(int i=0;i<k;i++){
        ans+=window_sum[i];
    }
    cout<<ans<<endl;
    return 0;
}