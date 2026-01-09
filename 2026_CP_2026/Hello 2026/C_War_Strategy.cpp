#include <bits/stdc++.h>
using namespace std;
#define int long long

#define MOD (int)(1e9+7)
#define EPS (double)(1e-9)

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// ACCEPT #DEFEAT
// WRONG LOGIC

void solve() {
    int n, m, k; cin >> n >> m >> k;
    int front = k - 1, back = n - k;
    if (min(front, back) > 0) {
        int ans=0;
        if (max(front, back)*2-1<m) {
            ans+=max(front, back);
            int rem = max(front, back)-1;
            m-=max(front, back)*2-1;
            // m - rem
            if (rem <= m) {
                // ---3 to --31
                // rem + 2x-1 <= m-1
                m--;
                ans++;
                if (ans!=n-1) {
                    int x = (m - rem)/2;
                    ans+=x+rem-1;
                }
            } else {
                ans+=m;
            }
        } else {
            ans+=m/2+1;
        }
        cout<<min(ans+1, n)<<endl;
    } else {
        if (m%2==0) {
            m--;
        }
        cout<<min(n, m/2+2)<<endl;
    }
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