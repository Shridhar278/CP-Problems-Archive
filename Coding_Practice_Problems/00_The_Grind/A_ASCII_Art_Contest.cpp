#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int32_t main() {
    fast_io();
    char c[] = "check again";
    char f[] = "final";
        int n[3];
        for (int i = 0; i < 3; i++) {
            cin >> n[i];
        }
        if ((*max_element(n, n+3) - *min_element(n, n+3)) >= 10) {
            cout<<c<<endl;
        } else {
            sort(n, n+3);
            cout<<f<<" "<<n[1]<<endl;
        }
    return 0;
}