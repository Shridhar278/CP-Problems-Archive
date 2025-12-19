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
    int n, k; cin >> n >> k;
    vector<int> sols(k, 0);
    //  the process
    int digits = ilogb(n);
    int cycle = 0;
    int zeros = 0;
    if (k%2) {
        for (int i=0;i<k;i++) {
            cout<<n<<" ";
        }
        cout<<endl;
        return;
    }
    for (int digit=digits;digit>=0;digit--) {
        int curr = n/((int)pow(2, digit));
        // cout<<curr<<" "<<cycle<<" "<<zeros<<endl;
        n%=(int)pow(2, digit);
        if (cycle==k) {
            cycle=0;
        }
        for (int ele=0;ele<k;ele++) {
            // cout<<sols[ele]<<endl;
            sols[ele]*=2;
            if (curr==1) {
                if (cycle!=ele) {
                    sols[ele]++;
                }
            } else {
                if (ele < (zeros/2)*2) {
                    sols[ele]++;
                }
            }
        }
        if (curr==1) {
            cycle++;
            zeros++;
        }
    }
    for (int sol : sols) {
        cout<<sol<<" ";
    }
    cout<<endl;
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