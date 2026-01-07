#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    int front = k - 1, back = n - k;
    if (min(front, back) > 0) {
        int ans=0;
        if (max(front, back)*2-1<m) {
            ans+=max(front, back);
            int rem = max(front, back)-1;
            m-=max(front, back)*2-1;
            if (rem <= m) {
                ans+=rem; 
                m-=rem;
            } else {
                ans+=m;
                m=0;
                if (max(front, back)==min(front, back)) {
                    ans++;
                }
            }
            // ans += m/2+1;
            // if (m%2==0) {
            //     ans--;
            // }
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