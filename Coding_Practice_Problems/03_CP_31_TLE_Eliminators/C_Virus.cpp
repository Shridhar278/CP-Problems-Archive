#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// protecting INFECTED is REDUNDANT
// since, doesn't stop propagation since neighbours will already be infected.
// limit the ZONES of SAFENESS
// GO in order of incr. decr. SPACE to secure max, since, it works and
// 0 at right time is precious

// COMPLICATED think SLOWLY

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n, k; cin >> n >> k;
        int ele[n];
        vector<int> hope(n);
        for (int i = 0; i < n; i++) {
            cin >> ele[i];
        }
        sort(ele, ele + n);
        for (int i = 1; i < n; i++) {
            hope.push_back(ele[i] - ele[i-1] - 1);
        }
        hope.push_back(ele[0] + n - ele[n-1] - 1);
        sort(hope.begin(), hope.end());
        int saved = 0;
    }
    return 0;
}