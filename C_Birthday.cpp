 #include<iostream>

#include<algorithm>

using namespace std;

int main()

{



    int n,i;

    cin>>n;

    int a[n+1];

    for(i=0; i<n; i++)

    {

        cin>>a[i];

    }

    sort(a,a+n);

    for(i=0; i<n; i+=2)

    {

            cout<<a[i]<<" ";

    }

    for(i=n-1; i>=0; i--)

    {

        if(i%2!=0)

            cout<<a[i]<<" ";

    }

    cout<<endl;
}