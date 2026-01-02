#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// i think I CAN

// targetting O(rootN)
void solve() {
    int n; cin >> n;
    // simple check on factors FOR LCM(x,n/x) iS NAIVE CAN go SMARTER let's SEE

    //NAIVE
    int best=1;
    for (int i=1;i<=floor(sqrt(n));i++) {
        if (n%i==0) {
            if (__gcd(n/i, i)==1) {
                best=i;
            }
        }
    }
    cout<<best<<" "<<n/best<<endl;
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}