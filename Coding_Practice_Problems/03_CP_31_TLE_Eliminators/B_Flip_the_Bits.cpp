#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// STRATEGIC POINTS CAPITALIZE if not CAN'T

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n; cin >> n;
        vector <char> a(n);
        vector <char> b(n);
        vector <int> count0(n, 0);
        for (int i=0;i<n;i++) {
            cin >> a[i];
            if (i==0) {
                if (a[i]=='0') {
                    count0[i]++;
                }
            } else {
                if (a[i]=='0') {
                    count0[i]=count0[i-1]+1;
                } else {
                    count0[i]=count0[i-1];
                }
            }
        }
        for (int i=0;i<n;i++) {
            cin >> b[i];
        }
        int factor = 0, fail=0; // factor = 1 - factor PER SWITCH
        // iterate from back;
        for (int i=n-1;i>=0;i--) {
            if (abs(a[i]-b[i]) != factor) {
                if (i%2==1 && count0[i]*2-1==i) { // for n0 = n1 => ALLOWED to INVERSE
                    // be happy for now
                } else {
                    cout<<"NO"<<endl;
                    fail=1;
                    break;
                }
                factor = 1 - factor;
            }
        }
        if (!fail) {
            cout<<"YES"<<endl;
        }
    }
    return 0;
}