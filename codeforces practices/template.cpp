#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;


// ============================================================
//                      NUMBER THEORY
// ============================================================

// GCD
// Use: common divisor / divisibility problems
ll gcd(ll a, ll b) {
    while (b) {
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}


// LCM
// Use: smallest number divisible by both
ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}


// Prime Check
// Use: single prime query
bool isPrime(ll n) {
    if (n < 2) return false;

    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}


// Sieve
// Use: many prime queries up to N
vector<bool> sieve(int n) {

    vector<bool> prime(n + 1, true);

    if (n >= 0) prime[0] = false;
    if (n >= 1) prime[1] = false;

    for (int i = 2; i * i <= n; i++) {

        if (prime[i]) {

            for (int j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }

    return prime;
}


// Prime Factorization
// Use: prime factors / divisor-count problems
vector<pair<ll, int>> factorize(ll n) {

    vector<pair<ll, int>> factors;

    for (ll p = 2; p * p <= n; p++) {

        if (n % p == 0) {

            int cnt = 0;

            while (n % p == 0) {
                n /= p;
                cnt++;
            }

            factors.push_back({p, cnt});
        }
    }

    if (n > 1)
        factors.push_back({n, 1});

    return factors;
}


// Number of Divisors
// n = p1^a1 * p2^a2 ...
// divisors = (a1+1)(a2+1)...
ll countDivisors(ll n) {

    ll ans = 1;

    for (ll p = 2; p * p <= n; p++) {

        if (n % p == 0) {

            int cnt = 0;

            while (n % p == 0) {
                n /= p;
                cnt++;
            }

            ans *= (cnt + 1);
        }
    }

    if (n > 1)
        ans *= 2;

    return ans;
}


// ============================================================
//                    FAST EXPONENTIATION
// ============================================================

// Calculate a^b
// Use: huge exponent
ll power(ll a, ll b) {

    ll ans = 1;

    while (b) {

        if (b & 1)
            ans *= a;

        a *= a;
        b >>= 1;
    }

    return ans;
}


// Calculate a^b % MOD
// Use: huge exponent + modulo
ll modPower(ll a, ll b, ll mod = MOD) {

    ll ans = 1;

    a %= mod;

    while (b) {

        if (b & 1)
            ans = ans * a % mod;

        a = a * a % mod;
        b >>= 1;
    }

    return ans;
}


// Modular Inverse
// Use: division under modulo when MOD is prime
ll modInverse(ll a, ll mod = MOD) {
    return modPower(a, mod - 2, mod);
}


// ============================================================
//                    MODULAR ARITHMETIC
// ============================================================

ll modAdd(ll a, ll b, ll mod = MOD) {
    return (a + b) % mod;
}

ll modSub(ll a, ll b, ll mod = MOD) {
    return (a - b + mod) % mod;
}

ll modMul(ll a, ll b, ll mod = MOD) {
    return (a % mod) * (b % mod) % mod;
}


// ============================================================
//                       BITWISE
// ============================================================

// Count set bits
// Use: number of 1s in binary representation
int countBits(int x) {
    return __builtin_popcount(x);
}

int countBits(ll x) {
    return __builtin_popcountll(x);
}


// Check ith bit
bool isSet(int x, int i) {
    return x & (1 << i);
}


// Set ith bit
int setBit(int x, int i) {
    return x | (1 << i);
}


// Clear ith bit
int clearBit(int x, int i) {
    return x & ~(1 << i);
}


// Toggle ith bit
int toggleBit(int x, int i) {
    return x ^ (1 << i);
}


// Lowest set bit
int lowestSetBit(int x) {
    return x & (-x);
}


// Unique element
// Use: every element appears twice except one
int uniqueElement(vector<int>& a) {

    int ans = 0;

    for (int x : a)
        ans ^= x;

    return ans;
}


// Maximum XOR - brute force
// Use only when N is small
int maxXOR(vector<int>& a) {

    int ans = 0;

    for (int i = 0; i < a.size(); i++) {

        for (int j = i + 1; j < a.size(); j++) {

            ans = max(ans, a[i] ^ a[j]);
        }
    }

    return ans;
}


// ============================================================
//                      PREFIX XOR
// ============================================================

// Prefix XOR
vector<int> prefixXOR(vector<int>& a) {

    int n = a.size();

    vector<int> px(n);

    px[0] = a[0];

    for (int i = 1; i < n; i++)
        px[i] = px[i - 1] ^ a[i];

    return px;
}


// Count subarrays having XOR = K
// Use: "number of subarrays with XOR K"
ll countXOR(vector<int>& a, int k) {

    unordered_map<int, ll> mp;

    mp[0] = 1;

    int xr = 0;
    ll ans = 0;

    for (int x : a) {

        xr ^= x;

        ans += mp[xr ^ k];

        mp[xr]++;
    }

    return ans;
}


// ============================================================
//                         STRINGS
// ============================================================

// Palindrome
// Use: string reads same forwards/backwards
bool isPalindrome(string& s, int l, int r) {

    while (l < r) {

        if (s[l] != s[r])
            return false;

        l++;
        r--;
    }

    return true;
}

bool isPalindrome(string& s) {
    return isPalindrome(s, 0, s.size() - 1);
}


// Pseudo Palindrome
// Use: palindrome after deleting at most one character
bool pseudoPalindrome(string& s) {

    int l = 0;
    int r = s.size() - 1;

    while (l < r) {

        if (s[l] != s[r]) {

            return isPalindrome(s, l + 1, r) ||
                   isPalindrome(s, l, r - 1);
        }

        l++;
        r--;
    }

    return true;
}


// String Rotation
// Use: check whether goal is a cyclic rotation of s
bool isRotation(string s, string goal) {

    if (s.size() != goal.size())
        return false;

    return (s + s).find(goal) != string::npos;
}


// Anagram
// Use: same characters with same frequencies
bool isAnagram(string& s, string& t) {

    if (s.size() != t.size())
        return false;

    vector<int> freq(256, 0);

    for (char c : s)
        freq[c]++;

    for (char c : t)
        freq[c]--;

    for (int x : freq) {

        if (x != 0)
            return false;
    }

    return true;
}


// Character Frequency
vector<int> frequency(string& s) {

    vector<int> freq(256, 0);

    for (char c : s)
        freq[c]++;

    return freq;
}


// Longest substring without repeating characters
// Use: sliding window problems
int longestUniqueSubstring(string& s) {

    vector<int> last(256, -1);

    int l = 0;
    int ans = 0;

    for (int r = 0; r < s.size(); r++) {

        if (last[s[r]] >= l)
            l = last[s[r]] + 1;

        last[s[r]] = r;

        ans = max(ans, r - l + 1);
    }

    return ans;
}


// ============================================================
//                          KMP
// ============================================================

// Prefix Function
// Use: KMP / pattern matching
vector<int> prefixFunction(string s) {

    int n = s.size();

    vector<int> pi(n);

    for (int i = 1; i < n; i++) {

        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];

        if (s[i] == s[j])
            j++;

        pi[i] = j;
    }

    return pi;
}


// KMP Search
// Returns starting positions of pattern in text
vector<int> KMP(string text, string pattern) {

    string s = pattern + "#" + text;

    vector<int> pi = prefixFunction(s);

    vector<int> positions;

    int m = pattern.size();

    for (int i = m + 1; i < s.size(); i++) {

        if (pi[i] == m)
            positions.push_back(i - 2 * m);
    }

    return positions;
}


// ============================================================
//                        Z FUNCTION
// ============================================================

// z[i] = longest prefix matching substring starting at i
// Use: prefix matching / pattern matching
vector<int> ZFunction(string s) {

    int n = s.size();

    vector<int> z(n);

    int l = 0;
    int r = 0;

    for (int i = 1; i < n; i++) {

        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);

        while (i + z[i] < n &&
               s[z[i]] == s[i + z[i]]) {

            z[i]++;
        }

        if (i + z[i] - 1 > r) {

            l = i;
            r = i + z[i] - 1;
        }
    }

    return z;
}


// ============================================================
//                       STRING HASHING
// ============================================================

// Use: compare substrings quickly
const ll BASE = 31;

vector<ll> hashValue;
vector<ll> powerBase;

void buildHash(string& s) {

    int n = s.size();

    hashValue.assign(n + 1, 0);
    powerBase.assign(n + 1, 1);

    for (int i = 0; i < n; i++) {

        hashValue[i + 1] =
            hashValue[i] * BASE + s[i];

        powerBase[i + 1] =
            powerBase[i] * BASE;
    }
}


// Hash of substring [l,r]
ll getHash(int l, int r) {

    return hashValue[r + 1]
         - hashValue[l] * powerBase[r - l + 1];
}


// ============================================================
//                          KADANE
// ============================================================

// Maximum contiguous subarray sum
// Use: "maximum subarray"
ll kadane(vector<ll>& a) {

    ll cur = a[0];
    ll ans = a[0];

    for (int i = 1; i < a.size(); i++) {

        cur = max(a[i], cur + a[i]);

        ans = max(ans, cur);
    }

    return ans;
}


// ============================================================
//                       0/1 KNAPSACK
// ============================================================

// Each item can be taken 0 or 1 time
// Use: choose items with maximum value
ll knapsack01(
    vector<int>& wt,
    vector<int>& val,
    int W
) {

    vector<ll> dp(W + 1, 0);

    for (int i = 0; i < wt.size(); i++) {

        for (int w = W; w >= wt[i]; w--) {

            dp[w] = max(
                dp[w],
                dp[w - wt[i]] + val[i]
            );
        }
    }

    return dp[W];
}


// ============================================================
//                         SUBSET SUM
// ============================================================

// Can we select elements whose sum = target?
bool subsetSum(vector<int>& a, int target) {

    vector<bool> dp(target + 1, false);

    dp[0] = true;

    for (int x : a) {

        for (int sum = target; sum >= x; sum--) {

            dp[sum] |= dp[sum - x];
        }
    }

    return dp[target];
}


// ============================================================
//                         COIN CHANGE
// ============================================================

// Minimum number of coins
// Coins can be used unlimited times
int minCoins(vector<int>& coins, int amount) {

    const int INF_INT = 1e9;

    vector<int> dp(amount + 1, INF_INT);

    dp[0] = 0;

    for (int x = 1; x <= amount; x++) {

        for (int coin : coins) {

            if (coin <= x) {

                dp[x] = min(
                    dp[x],
                    dp[x - coin] + 1
                );
            }
        }
    }

    return dp[amount] == INF_INT ? -1 : dp[amount];
}


// Number of combinations
// Coins can be used unlimited times
ll coinWays(vector<int>& coins, int amount) {

    vector<ll> dp(amount + 1, 0);

    dp[0] = 1;

    for (int coin : coins) {

        for (int x = coin; x <= amount; x++) {

            dp[x] += dp[x - coin];
        }
    }

    return dp[amount];
}


// ============================================================
//                            LIS
// ============================================================

// Longest Increasing Subsequence
// O(N^2)
// Use when N is relatively small
int LIS(vector<int>& a) {

    int n = a.size();

    vector<int> dp(n, 1);

    int ans = 1;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < i; j++) {

            if (a[j] < a[i]) {

                dp[i] = max(
                    dp[i],
                    dp[j] + 1
                );
            }
        }

        ans = max(ans, dp[i]);
    }

    return ans;
}


// ============================================================
//                            LCS
// ============================================================

// Longest Common Subsequence
// Use: two strings + common subsequence
int LCS(string& a, string& b) {

    int n = a.size();
    int m = b.size();

    vector<vector<int>> dp(
        n + 1,
        vector<int>(m + 1, 0)
    );

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= m; j++) {

            if (a[i - 1] == b[j - 1]) {

                dp[i][j] =
                    dp[i - 1][j - 1] + 1;
            }

            else {

                dp[i][j] =
                    max(
                        dp[i - 1][j],
                        dp[i][j - 1]
                    );
            }
        }
    }

    return dp[n][m];
}


// ============================================================
//                          GRID DP
// ============================================================

// Minimum cost path
// Movement: right / down
ll gridDP(vector<vector<int>>& grid) {

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<ll>> dp(
        n,
        vector<ll>(m, INF)
    );

    dp[0][0] = grid[0][0];

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            if (i == 0 && j == 0)
                continue;

            if (i > 0) {

                dp[i][j] = min(
                    dp[i][j],
                    dp[i - 1][j] + grid[i][j]
                );
            }

            if (j > 0) {

                dp[i][j] = min(
                    dp[i][j],
                    dp[i][j - 1] + grid[i][j]
                );
            }
        }
    }

    return dp[n - 1][m - 1];
}


// ============================================================
//                         BITMASK DP
// ============================================================

// Use when N <= ~20
// Typical: assignment / visit all / subset optimization
ll bitmaskDP(vector<vector<ll>>& cost) {

    int n = cost.size();

    int N = 1 << n;

    vector<ll> dp(N, INF);

    dp[0] = 0;

    for (int mask = 0; mask < N; mask++) {

        int i = __builtin_popcount(mask);

        if (i == n)
            continue;

        for (int j = 0; j < n; j++) {

            if (!(mask & (1 << j))) {

                int newMask =
                    mask | (1 << j);

                dp[newMask] = min(
                    dp[newMask],
                    dp[mask] + cost[i][j]
                );
            }
        }
    }

    return dp[N - 1];
}


// ============================================================
//                         SOLVE
// ============================================================

void solve() {

    /*
        Identify the pattern first:

        GCD / LCM       -> gcd(), lcm()
        Prime           -> isPrime(), sieve()
        Factors         -> factorize()
        a^b             -> power(), modPower()
        MOD             -> modPower(), modInverse()
        Unique XOR      -> uniqueElement()
        Max XOR         -> maxXOR() / Trie
        XOR subarray    -> countXOR()
        Set bits        -> countBits()
        Palindrome      -> isPalindrome()
        Pseudo-pal      -> pseudoPalindrome()
        Rotation        -> isRotation()
        Anagram         -> isAnagram()
        Pattern         -> KMP(), ZFunction()
        Substrings      -> buildHash(), getHash()
        Max subarray    -> kadane()
        0/1 choice      -> knapsack01()
        Target subset   -> subsetSum()
        Coins           -> minCoins(), coinWays()
        Increasing seq  -> LIS()
        Common sequence -> LCS()
        Grid             -> gridDP()
        N <= 20          -> bitmaskDP()
    */

}


// ============================================================
//                           MAIN
// ============================================================

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;

    // Uncomment if input contains T:
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}