#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// done SUB-CONCIOUSLY, let's SEE
// Happy New Year !

// just calculated that
// run through WITH profits
// immediately back OFF on LOSS (profits <= 0)
// else it INCREASES and increases.....

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    int total=0;
    for (int i=0;i<n;i++) {
        cin >> arr[i];
        total+=arr[i];
    }
    int p1 = 1, p2 = 1;
    int profits=0, best=0;
    int shift;
    while (p2 <= n) {
        shift = (p2-p1)*1+1*(p2+p1)-arr[p2-1];
        // cout<<"X"<<shift<<" "<<p1<<" "<<p2<<" "<<profits<<" "<<best<<endl;
        if (shift > 0) {
            profits+=shift;
            p2++;
        } else if (profits + shift > 0) {
            profits+=shift;
            p2++;
        } else if (profits + shift <= 0) {
            profits=0;
            p1=++p2;
        }
        // cout<<"Y"<<shift<<" "<<p1<<" "<<p2<<" "<<profits<<" "<<best<<endl;
        
        // p1 move by 1
        // p2 move by 1 BEST
        // p2 move by 1 NOT BEST
        if (best < profits) {
            best = profits;
        }
    }
    cout<<total+best<<endl;
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