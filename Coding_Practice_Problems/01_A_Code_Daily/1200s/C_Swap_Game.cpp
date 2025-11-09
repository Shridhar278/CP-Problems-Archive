#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    string bob="Bob";
    string alice="Alice";
    while (test--) {
        int n; cin>>n;
        // cout<<"*"<<n<<"*"<<endl;
        int num;
        int won=0;
        int low;
        for (int i=0;i<n;i++) {
            cin>>num;
            // cout<<"*"<<num<<"*"<<low<<endl;
            if (i==0) {
                low=num;
            }
            if (num < low) {
                // first is NOT the smallest
                // nice logic question
                // INDUCTIIVE and CONSTRUCTIVE both proofs present

                // CONSTRUCTIVE
                // Alice would make sure Bob always gets smallest element
                // by the virtue of choosing the smallest and -1
                // helping in case of mutiple smallests...
                
                // INDUCTIVE
                // Use WIN/LOSS states's analysis at each turn just like NIM.
                won=1;
                // INPUT IN BUFFER don't break
                // will mess with the structure
                // break;
            }
        }
        if (won) {
            cout<<alice<<endl;
        } else {
            cout<<bob<<endl;
        }
    }
    return 0;
}