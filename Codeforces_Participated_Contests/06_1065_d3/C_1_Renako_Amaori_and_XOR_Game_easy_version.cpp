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
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        int odds=0, evens=0, last=0, neutral=0;
        for (int i = 0; i < n; i++) {
            if (a[i]!=b[i]) {
                last=i;
                if (i%2==1) 
                    evens++;
                else 
                    odds++;
            } else {
                neutral++;
            }
        }
        if ((evens+odds)%2) {
            if (last%2) {
                cout<<ma<<endl;
            } else {
                cout<<aj<<endl;
            }
        } else {
            cout<<ti<<endl;
        }
    }
    return 0;
}