#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (long long &x : a) cin >> x;

    long long health = 0;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    long long answer = 0;

    for (long long x : a) {
        if (health + x >= 0) {
            health += x;
            pq.push(x);
            ++answer;
        } else if (!pq.empty() && x > pq.top()) {
            health += x - pq.top();
            pq.pop();
            pq.push(x);
        }
    }

    cout << answer << '\n';
    return 0;
}
