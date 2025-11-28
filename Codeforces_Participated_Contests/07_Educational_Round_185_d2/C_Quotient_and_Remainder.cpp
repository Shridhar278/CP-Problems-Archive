#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// i don't know...

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n, k; cin >> n >> k;
        vector<int>quo(n);
        vector<int>rem(n);
        for (int i=0;i<n;i++) {
            cin>>quo[i];
        }
        for (int i=0;i<n;i++) {
            cin>>rem[i];
        }
        sort(quo.begin(), quo.end());
        sort(rem.begin(), rem.end());
        int i=rem.size()-1;
        while(i>=0) {
            bool x=false;
            int j=quo.size()-1;
            while (j>=0) {
                // cout<<i<<" "<<j<<" "<<rem[i]<<" "<<quo[j]<<endl;
                if ((rem[i]+1)*quo[j]+rem[i]<=k) {
                    rem.erase(rem.begin()+i);
                    quo.erase(quo.begin()+j);
                    x=true;
                    i--;
                    break;
                } 
                j--;
            }
            if (!x) {
                i--;
            }
        }
        cout<<n-rem.size()<<endl;
    }
    return 0;
}