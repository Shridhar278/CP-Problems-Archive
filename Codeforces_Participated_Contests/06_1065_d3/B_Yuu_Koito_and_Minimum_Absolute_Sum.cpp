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
    while (test--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (a[0] == -1 && a[n-1]==-1) {
            cout<<0<<endl;
            cout<<0<<" ";
            for (int i = 1; i < n-1; i++) {
                if (a[i] == -1) 
                    cout<<0<<" ";
                else
                    cout<<a[i]<<" ";
            }
            cout<<0<<endl;
            continue;
        }
        if (a[0] == -1) {
            cout<<0<<endl;
            cout<<a[n-1]<<" ";
            for (int i = 1; i < n; i++) {
                if (a[i] == -1) 
                    cout<<0<<" ";
                else
                    cout<<a[i]<<" ";
            }
            cout<<endl;
            continue;
        }
        if (a[n-1] == -1) {
            cout<<0<<endl;
            for (int i = 0; i < n-1; i++) {
                if (a[i] == -1) 
                    cout<<0<<" ";
                else
                    cout<<a[i]<<" ";
            }
            cout<<a[0]<<endl;
            continue;
        }
        cout<<abs(a[0]-a[n-1])<<endl;
        for (int i = 0; i < n; i++) {
            if (a[i] == -1) 
                cout<<0<<" ";
            else
                cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}