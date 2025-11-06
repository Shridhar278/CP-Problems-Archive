#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n, num;
        cin>>n;
        vector<int> arr;
        for (int i=0;i<n;i++) {
            cin>>num;
            arr.push_back(num);
        }
        sort(arr.begin(), arr.end());
        int i=2, j=0, k=0;
        if (arr[j]==1) {
            k=1;
            if (n==1) {
                cout<<2<<endl;
                continue;
            }
        }
        j=k;
        bool no=true;
        while (i!=1e18+1) {
            if (__gcd(arr[j], i)==1) {
                cout<<i<<endl;
                no=false;
                break;
            }
            j++;
            if (j==n) {
                i++; j=k;
            }
        }
        if (no) {
            cout<<-1<<endl;
        }
    }
    return 0;
}