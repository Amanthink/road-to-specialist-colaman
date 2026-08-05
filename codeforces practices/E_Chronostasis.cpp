/**
 *    author:  colaman
 *    github:  Amanthink
 *    created: 04.08.2026 20:53:49
 **/
#include <bits/stdc++.h>
using namespace std;

// ================= TYPES (long name -> short name) =================
typedef long long ll;           // long long -> ll
typedef unsigned long long ull; // unsigned long long -> ull
typedef long double ld;         // long double -> ld

typedef pair<int, int> pii; // pair<int,int> -> pii
typedef pair<ll, ll> pll;   // pair<long long,long long> -> pll

typedef vector<int> vi;          // vector<int> -> vi
typedef vector<ll> vll;          // vector<long long> -> vll
typedef vector<pii> vpii;        // vector<pair<int,int>> -> vpii
typedef vector<vector<int>> vvi; // vector<vector<int>> (2D grid) -> vvi
typedef vector<string> vs;       // vector<string> -> vs

typedef map<int, int> mii;            // map<int,int> -> mii
typedef set<int> si;                  // set<int> -> si
typedef unordered_map<int, int> umii; // unordered_map<int,int> -> umii

// ================= FUNCTION/METHOD SHORTCUTS =================
#define pb push_back    // v.push_back(x) -> v.pb(x)
#define eb emplace_back // v.emplace_back(x) -> v.eb(x)
#define po pop_back     // v.pop_back() -> v.po()
#define mp make_pair    // make_pair(a,b) -> mp(a,b)
#define ff first        // p.first -> p.ff
#define ss second       // p.second -> p.ss

#define all(x) (x).begin(), (x).end() // v.begin(),v.end() -> all(v)
#define sz(x) (int)(x).size()         // (int)v.size() -> sz(v)
#define rsz(x, n) (x).resize(n)       // v.resize(n) -> rsz(v,n)

// ================= USEFUL CONSTANTS =================
const ll inf = 1e18;      // a "big enough" number, used as infinity
const int mod = 1e9 + 7;  // common modulo used in many problems
const ld pi = acos(-1.0); // value of pi

// ================= FAST IO =================
#define endl "\n" // endl flushes (slow); "\n" doesn't (fast)

struct Fenwick
{
    int n;
    vector<int> bit;

    Fenwick() : n(0) {}
    explicit Fenwick(int n) { init(n); }

    void init(int n_)
    {
        n = n_;
        bit.assign(n + 1, 0);
    }

    void add(int idx, int delta)
    {
        for (idx++; idx <= n; idx += idx & -idx)
            bit[idx] += delta;
    }

    int sumPrefix(int idx) const
    {
        int res = 0;
        for (idx++; idx > 0; idx -= idx & -idx)
            res += bit[idx];
        return res;
    }

    int kth(int k) const
    {
        int idx = 0;
        int step = 1;
        while ((step << 1) <= n)
            step <<= 1;
        for (; step > 0; step >>= 1)
        {
            int next = idx + step;
            if (next <= n && bit[next] < k)
            {
                idx = next;
                k -= bit[next];
            }
        }
        return idx;
    }
};

struct SegTree
{
    int n;
    vector<ll> sum, mn;

    SegTree() : n(0) {}

    explicit SegTree(const vector<ll> &a) { build(a); }

    void build(const vector<ll> &a)
    {
        n = (int)a.size();
        sum.assign(4 * n + 4, 0);
        mn.assign(4 * n + 4, 0);
        build(1, 0, n - 1, a);
    }

    void build(int node, int l, int r, const vector<ll> &a)
    {
        if (l == r)
        {
            sum[node] = a[l];
            mn[node] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(node << 1, l, mid, a);
        build(node << 1 | 1, mid + 1, r, a);
        pull(node);
    }

    void pull(int node)
    {
        sum[node] = sum[node << 1] + sum[node << 1 | 1];
        mn[node] = min(mn[node << 1], sum[node << 1] + mn[node << 1 | 1]);
    }

    void update(int pos, ll val)
    {
        update(1, 0, n - 1, pos, val);
    }

    void update(int node, int l, int r, int pos, ll val)
    {
        if (l == r)
        {
            sum[node] = val;
            mn[node] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)
            update(node << 1, l, mid, pos, val);
        else
            update(node << 1 | 1, mid + 1, r, pos, val);
        pull(node);
    }

    ll minPrefix() const
    {
        return n ? mn[1] : 0;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<ll> b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];

    vector<pair<ll, int>> asc(n);
    for (int i = 0; i < n; i++)
        asc[i] = {b[i], i};
    sort(asc.begin(), asc.end());

    vector<ll> descValues(n);
    for (int i = 0; i < n; i++)
        descValues[i] = asc[n - 1 - i].first;

    Fenwick bit(n);
    for (int i = 0; i < n; i++)
        bit.add(i, 1);

    SegTree seg(descValues);
    vector<char> alive(n, 1);

    ll cur = 0;
    vector<ll> answer;
    answer.reserve(n);

    for (int step = 0; step < n; step++)
    {
        int lo = 1, hi = n - step, bestRank = -1;
        while (lo <= hi)
        {
            int mid = (lo + hi) >> 1;
            int posAsc = bit.kth(mid);
            ll val = asc[posAsc].first;
            int posDesc = n - 1 - posAsc;

            seg.update(posDesc, 0);
            ll need = cur + val;
            bool ok = (need > 0 && need + seg.minPrefix() > 0);
            seg.update(posDesc, val);

            if (ok)
            {
                bestRank = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        if (bestRank == -1)
        {
            cout << -1 << endl;
            return;
        }

        int posAsc = bit.kth(bestRank);
        ll val = asc[posAsc].first;
        int posDesc = n - 1 - posAsc;

        bit.add(posAsc, -1);
        seg.update(posDesc, 0);
        cur += val;
        answer.pb(cur);
    }

    for (int i = 0; i < n; i++)
    {
        cout << answer[i] << (i + 1 == n ? '\n' : ' ');
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}