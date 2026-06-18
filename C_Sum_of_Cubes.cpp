#include <bits/stdc++.h>
using namespace std;
//brute force method 
/*
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set<long long> cubes;

    for (long long i = 1; i * i * i <= 1000000000000LL; i++) {
        cubes.insert(i * i * i);
    }

    int t;
    cin >> t;

    while (t--) {
        long long x;
        cin >> x;

        bool ok = false;

        for (long long i = 1; i * i * i < x; i++) {
            long long cube = i * i * i;

            if (cubes.count(x - cube)) {
                ok = true;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}*/
//using two pointer method
void solve(){
    int64_t x;cin>>x;
     int64_t a=1;
    int64_t  b=cbrt(x);
    bool flag=false;
    while(a<=b){
        int64_t sum=a*a*a+b*b*b;
        if(sum==x){
            {flag=true;break;}
        }
        else if(sum<x){
            a++;
        }
        else{
            b--;
        }
    }
    if(flag){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  int64_t t;
  cin>>t;
  while(t--){solve();}
  return 0;
}