#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7

// much lesser time complexity code possible #acknowledged
// SLIDING window TECHNIQUE can be used here of k

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void first_On2() {
    int n, k;
    cin>>n>>k;
    vector<int> arr;
    char c;
    for (int i=0;i<n;i++) {
        cin>>c;
        arr.push_back(c-'0');
    }
    int back, save, count=0;
    for (int i=0; i<n; i++) {
        save=1;
        back=i-k+1;
        if (i<k-1) {
            back=0;
        }
        if (arr[i]==1) {
            for (int j=back; j<i; j++) {
                if (arr[j]==1) {
                    save=0;
                    break;
                }
            }
            if (save) {
                count++;
            }
        }
    }
    cout<<count<<endl;
}

void faster() {
    int n, k;
    cin>>n>>k;
    int has1=0; char c[1000], st;
    int protect=0;
    for (int i=0;i<n;i++) {
        cin>>c[i];
        if (!i) {
            st=c[i];
        }
        if (i>k-1) {
            if (st=='1') {
                has1--;
            }
            st = c[i-k+1];
        }
        if (c[i]-'0') {
            if (has1==0) {
                protect++;
            }
            has1++;
        }
    }
    cout<<protect<<endl;
}

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        // first_On2();
        faster();
    }
    return 0;
}