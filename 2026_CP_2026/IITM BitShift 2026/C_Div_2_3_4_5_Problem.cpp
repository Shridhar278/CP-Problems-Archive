#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// CRAZY question
// SOUNDS interesting but RAGEBAIT

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    int chances=0;
    int scope=0;
    for (int i=0;i<n;i++) {
        if (arr[i]%2==0) {
            chances++;
        }
        if (arr[i]%3==0) {
            chances++;
        }
        if (arr[i]%4==0) {
            while (arr[i]%4==0) {
                arr[i]/=4;
            }
            if (arr[i]%2==0) {
                scope++;
                chances--;
            }
        }
        if (arr[i]%5==0) {
            chances++;
        }
    }
    if (n%2==0) {
        cout<<"NO"<<endl;
        return;
    } else {
        if (scope%2==1) {
            cout<<"YES"<<endl;
            return;
        } else {
            // stalling
            chances+=scope;
        }
        if (chances%2==1) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
        return;
    }
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