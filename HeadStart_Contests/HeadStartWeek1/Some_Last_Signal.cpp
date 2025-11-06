#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// IT WORKS NOW, JUST use (int) in power 
// since returns a double might create issues

int32_t main() {
    fast_io();
    int n;
    cin >> n;
    int best=0;
    int ttl=0;
    n++;
    while (n > 0) {
        best = (int)log2(n);
        ttl += (int)(pow(2, best-1))*(best);
        n -= (int)pow(2, best);
        ttl += n;
    }
    cout << ttl;
    return 0;
}