/**
 * author:  colaman
 * github:  Amanthink
 * created: 07.08.2026 20:42:48
 */

#include <bits/stdc++.h>
using namespace std;

// ================= TYPES (long name -> short name) =================
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;

typedef map<int, int> mii;
typedef set<int> si;
typedef unordered_map<int, int> umii;

// ================= FUNCTION/METHOD SHORTCUTS =================
#define pb push_back
#define eb emplace_back
#define po pop_back
#define mp make_pair
#define ff first
#define ss second

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rsz(x, n) (x).resize(n)

// ================= USEFUL CONSTANTS =================
const ll inf = 1e18;
const int mod = 1e9 + 7;
const ld pi = acos(-1.0);

// ================= FAST IO =================
#define endl "\n"

void solve() {
    long long n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<long long> a(x), b(y);

    for (int i = 0; i < x; ++i)
        cin >> a[i];

    for (int i = 0; i < y; ++i)
        cin >> b[i];

    vector<long long> p, q, r;

    int i = 0, j = 0;

    while (i < x && j < y) {
        if (a[i] == b[j]) {
            r.push_back(a[i]);
            i++;
            j++;
        }
        else if (a[i] < b[j]) {
            p.push_back(a[i]);
            i++;
        }
        else {
            q.push_back(b[j]);
            j++;
        }
    }

    while (i < x) {
        p.push_back(a[i]);
        i++;
    }

    while (j < y) {
        q.push_back(b[j]);
        j++;
    }

    vector<long long> v = r;

    long long u = min((long long)p.size(), n);

    for (int k = 0; k < u; ++k) {
        v.push_back(p[p.size() - 1 - k]);
    }

    long long w = min((long long)q.size(), m);

    for (int k = 0; k < w; ++k) {
        v.push_back(q[q.size() - 1 - k]);
    }

    sort(v.rbegin(), v.rend());

    long long s = 0;
    long long z = min((long long)v.size(), n + m - 1);

    for (int k = 0; k < z; ++k) {
        s += v[k];
    }

    cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}