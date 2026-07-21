#include <bits/stdc++.h>
using namespace std;

bool totalAmount(int X, int Y)
{
   
    if (X > Y) {int t=X; X=Y; Y=t;}

    long long sum = 0;

    for (int i = X; i <= Y; i++)
    {
        int n = i;
        int digitSum = 0;
        int largest = 0;

        while (n > 0)
        {
            int d = n % 10;
            digitSum += d;
            largest = max(largest, d);
            n /= 10;
        }

        if (digitSum - largest == largest)
            sum += i;
    }

    return sum;
}

int main()
{   ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int X, Y;
    cin >> X >> Y;

    cout << totalAmount(X, Y);
    return 0;
}