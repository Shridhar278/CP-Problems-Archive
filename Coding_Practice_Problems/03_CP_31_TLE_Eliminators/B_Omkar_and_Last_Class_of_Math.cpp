#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// O(n) is too much here
// need to optimize hard
// direct search factors...

// solved in O(root n)

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n; cin >> n;
        // better time complexity reqr.
        // int best=1;
        // for (int i=n/2; i>=2; i--) {
        //     if (n%i==0) {
        //         best = i;
        //         break;
        //     }
        // }
        // cout<<best<<" "<<n-best<<endl;
        
        // NEED prime factorization of n
        // we want first prime factor THAT does it
        // O(rootn) time complexity
        int prime = 2, done = 0;
        while (prime <= (int)sqrt(n)) {
            if (n%prime==0) {
                done = 1;
                break;
            }
            prime++;
        }
        if (!done) {
            prime = n;
        }
        cout << n/prime << " " << n - n/prime << endl;
    }
    return 0;
}