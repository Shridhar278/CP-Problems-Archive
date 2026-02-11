#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// deletions
// SoluTION UNDERSTOOD
// dp TO GRIND

void solve() {
    // feels TOUGH
    // soln:
    int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) cin >> i;
	// dp[i] = minimum deletions needed to make the suffix a[i..n-1] beautiful
	vector<int> dp(n + 1);
	dp[n] = 0; // empty suffix requires 0 deletions
	for (int i = n - 1; i >= 0; --i) {
		// Option 1: delete a[i]
		dp[i] = dp[i + 1] + 1;
		// Option 2: keep a block starting at i of size (1 + a[i])
		// After keeping this block, we jump to index j
		int j = i + a[i] + 1;
		if (j <= n) {
			// No deletions inside the kept block, then solve from j
			dp[i] = min(dp[i], dp[j]);
		}
	}
	cout << dp[0] << '\n'; // minimum deletions for the whole array
}

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}