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
        int n, k;
        cin >> n >> k;
        vector<char> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int count=0, sleep=0;
        for (int i=0;i<n;i++){
            if (a[i]=='1'){
                count=k;
                continue;
            }
            if(count==0){
                sleep++;
            }
            else{
                count--;
            }
        }
        cout<<sleep<<endl;
    }
    return 0;
}