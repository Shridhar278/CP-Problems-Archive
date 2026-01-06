#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// EXTREME edge-case RAGE QUESTION
// FATAL logic ERROR
// Understand Tutorial


// O(n)
// sometimes OVER generalizing IS A FLAW

void solve() {
    int n, a; cin >> n >> a;
    vector<int> marbles(n);
    // OBSOLETE approach
    // i tried O(1)
    // auto it = upper_bound(marbles.begin(), marbles.end(), a);
    // if (it==marbles.end()) {
    //     cout<<marbles[n-1]<<endl;
    //     return;
    // } else if (it==marbles.begin()) {
    //     cout<<marbles[0]<<endl;
    //     return;
    // }
    // if (n%2) {
    //     if (*(it-1)==a) {
    //         if (it-marbles.begin()<=n/2) {
    //             cout<<*(it-1)+1<<endl;
    //         } else {
    //             cout<<*(it-1)-1<<endl;
    //         }
    //     } else {
    //         if (it-marbles.begin()<=n/2) {
    //             cout<<*it<<endl;
    //         } else {
    //             cout<<*(it-1)<<endl;
    //         }
    //     }
    // } else {
    //     if (*(it-1)==a) {
    //         if (it-marbles.begin()<=n/2) {
    //             cout<<*(it-1)+1<<endl;
    //         } else {
    //             cout<<*(it-1)-1<<endl;
    //         }
    //     } else {
    //         if (it-marbles.begin()<=n/2) {
    //             cout<<*it<<endl;
    //         } else {
    //             cout<<*(it-1)<<endl;
    //         }
    //     }
    // }
    // // parity DOESN't MATTER apparently..
    
    // New Approach NOW ...postEditorial
    // O(n)....don't OVERburnout on this s***
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        cin >> marbles[i];
        if (marbles[i] < a) l++; 
        // ignore marbles[i]==a as don't even think bout it
        if (marbles[i] > a) r++;
    }
    //minimalistic
    cout << (l > r ? a - 1 : a + 1) << endl;
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