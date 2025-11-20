#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7
#define EPS (double)1e-9
#define aj "Ajisai"
#define ma "Mai"
#define ti "Tie"

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n; cin >> n; int maxi=0;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            maxi = max(maxi, a[i]);
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            maxi = max(maxi, b[i]);
        }
        int best = 20;
        for (;best>0;best--) {
            int odds=0, evens=0, last=0;
            for (int i = 0; i < n; i++) {
                // cout<<evens<<" "<<odds<<" "<<a[i]<<" "<<b[i]<<" "<<best<<endl;
                if ((a[i]>=((int)pow(2,best-1)))!=(b[i]>=((int)pow(2,best-1)))) {
                    last=i;
                    if (i%2==1) 
                        evens++;
                    else 
                        odds++;
                }
                if (a[i]>=((int)pow(2,best-1)))
                    a[i] -= ((int)pow(2,best-1));
                if (b[i]>=((int)pow(2,best-1)))
                    b[i] -= ((int)pow(2,best-1));
            }
            if ((evens+odds)%2) {
                if (last%2) {
                    cout<<ma<<endl;
                } else {
                    cout<<aj<<endl;
                }
                break;
            } 
        }
        if (best==0) {
            cout<<ti<<endl;
        }
    }
    return 0;
}