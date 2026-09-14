#include <bits/stdc++.h>
using namespace std;
int a[101010],s[101010];
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);//why the hell scanf is faster than cin in this case? I don't know, but it is...
	for(int i=0;i<n;i++)s[i+1]=s[i]+a[i];//prefix sum 
	int q;scanf("%d",&q);
	while(q--){
		int l,r;scanf("%d%d",&l,&r);
		l--;
		printf("%d\n",(s[r]-s[l])/10);
	}
}