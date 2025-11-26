#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// THIS works if and only if POSSIBLE Scenarios are GIVEN
// if NOT, then preposterous answers
// but its perfect since appropraite element is traced iteratively
// and if discrepancy found, then existence of solution is impossible
// hence, a bijective mapping is formed MAKING the code PERFECT

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n; cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        int x, mx=1;
        vector<int> a; a.push_back(1);
        for (int i = 1; i < n; i++) {
            // cout << b[i] << " "<<a[a.size()-1]<<endl;
            x = b[i];
            x -= i+1; // min. rqr.
            x -= b[i-1]; // new element factor
            // now -x means how many times NO NEW MATCH happens (overlap)
            if (x == 0) {
                mx++;
                a.push_back(mx);
            } else {
                a.push_back(a[-x-1]); 
                // taking xth element means that many times NO NEW MATCH happened
            }
            // cout << x << " "<<a[a.size()-2]<<endl;
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}