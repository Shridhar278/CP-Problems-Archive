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
        int n, ne;
        cin>>n;
        int same=1, parity;
        vector<int>arr;
        while(n--) {
            cin>>ne;
            arr.push_back(ne);
            if (arr.size()==1) {
                parity = ne%2;
            } else {
                if (ne%2!=parity) {
                    same=0;
                }
            }
        }
        if (!same) {
            sort(arr.begin(), arr.end());
        }
        for (int i=0;i<arr.size();i++) {
            cout<<arr[i]<<" ";
        } cout<<endl;
    }
    return 0;
}