#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void common_sense(int n);

void find_max_3(vector<int> a, vector<int> b, vector<int> c, int stage, int choice[][]) {
    int ttl = choice[0][1] + choice[1][1] + choice[2][1];
    a.erase(a.begin()+choice[0][0]);
}

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n; cin >> n;
        vector<int> a(n), b(n), c(n);
        for (int i=0;i<n;i++) cin >> a[i];
        for (int i=0;i<n;i++) cin >> b[i];
        for (int i=0;i<n;i++) cin >> c[i];
        int max_a = max_element(a.begin(), a.end())-a.begin();
        int max_b = max_element(b.begin(), b.end())-b.begin();
        int max_c = max_element(c.begin(), c.end())-c.begin();
        for (int i=0;i<3;i++) {
            find_max_3(a, b, c, 0, [[max_a, 0], [0, 0], [0, 0]]);
        }
    }
    return 0;
}