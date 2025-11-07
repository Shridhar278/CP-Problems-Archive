#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// pre-tests passed : feels like the most efficient algorithm 
// in this case

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n, k; cin >> n;
        vector <int> arr;
        // vector <int> diff;
        for (int i=0;i<n;i++) {
            cin >> k; arr.push_back(k);
            // if (i) {
            //     diff.push_back(arr[i]-arr[i-1]);
            // }
        }
        // for (int i = 0; i<n; i++) {
        //     for (int j=i+1;j<n-1;j++) {
        //         if 
        //     }
        // }
        int done=0;
        for (int i=0;i<n-1;i++) {
            // int first = arr[i+1]%arr[i];
            // if (first%2==0) {
            //     done = 1;
            //     cout<<arr[i]<<" "<<arr[i+1]<<endl;
            // } else {
                
            // }
            for (int j=i+1;j<n;j++) {
                if ((arr[j]%arr[i])%2==0) {
                    cout<<arr[i]<<" "<<arr[j]<<endl;
                    done=1;
                    goto answer;
                }
            }
        }
        answer:
        if (!done) {
            cout<<-1<<endl;
        }
    }
    return 0;
}