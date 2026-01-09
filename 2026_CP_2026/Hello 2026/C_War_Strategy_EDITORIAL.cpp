#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// SATISFACTION

int solve(int n, int m, int k) {
    int a = k-1, b = n-k;
    a = (a >= b) ? a : b;
    b = n-1-a;
    int best_b=(m+1)/3, best_a=(m+2)/3;
    if (best_b>b) {
        best_b=b;
        best_a=min((m+1-best_b)/2, a);
    }
    if (best_a>a) {
        best_a=a;
        best_b=min(m+1-2*best_a, b);
    }
    return best_a+best_b+1;
}

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n, m, k; cin >> n >> m >> k;
        cout<<solve(n, m, k)<<endl;
    }
    return 0;
}