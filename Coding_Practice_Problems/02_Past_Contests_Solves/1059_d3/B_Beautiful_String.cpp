#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF (int)1e9+7

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fast_io();
    int test, n;
    char num[11];
    cin >> test;
    while (test--) {
        cin >> n;
        cin >> num;
        int zero = 0;
        vector<int> arr;
        for (int i=0;i<n;i++) {
            if (num[i]=='0') {
                arr.push_back(i+1);
                zero++;
            }
        }
        if (zero>0) {
            cout<<zero<<endl;
            for (int k=0;k<zero;k++) {
                cout<<arr[k]<<" ";
            }
            cout<<endl;
        } else {
            cout<<0<<endl<<endl;
        }
    }
    return 0;
}