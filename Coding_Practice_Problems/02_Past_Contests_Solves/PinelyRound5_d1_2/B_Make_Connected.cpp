#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// some ANALYSIS remainssss......
// # A LOT OF REASOING IS REMAINING, will think further LATER

// use GPT to REASON why this is true
// HYPOTHESIS:: Only 2 cases
// 1. already incorrect
// 2. #.# format

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    int xox[101][101];
    int xxx[101][101];
    int arr[100][100];
    while (test--) {
        int n; char c;
        cin>>n;
        for (int i=0; i<n;i++) {
            for (int j=0;j<n;j++) {
                cin>>c;
                if (c == '#') {
                    arr[i][j] = 1;
                } else {
                    arr[i][j] = 0;
                }
            }
        }
        for (int i=0; i<n;i++) {
            for (int j=0;j<n-2;j++) {
                int alive = 1;
                int xox=1, xo=1;
                // cout<<'$'<<i<<' '<<j<<' '<<endl;
                for (int k=j;k<j+3;k++) {
                    // cout<<"*"<<alive<<" "<<xo<<" "<<xox<<" "<<arr[i][k]<<endl;
                    if (arr[i][k]==0) {
                        alive=0;
                        if (xox) {
                            xo=0;
                        } else {
                            xox = 1;
                        }
                    } else {
                        if (xox) {
                            xox = 0;
                        } else {
                            xo = 0;
                        }
                    }
                }
                if (xo==1 || alive==1) {
                    goto answer;
                }
            }
        }
        for (int i=0; i<n;i++) {
            for (int j=0;j<n-2;j++) {
                int alive = 1;
                int xox=1, xo=1;
                // cout<<'$'<<j<<' '<<i<<' '<<endl;
                for (int k=j;k<j+3;k++) {
                    // cout<<"*"<<alive<<" "<<xo<<" "<<xox<<" "<<arr[k][i]<<endl;
                    if (arr[k][i]==0) {
                        alive=0;
                        if (xox) {
                            xo=0;
                        } else {
                            xox = 1;
                        }
                    } else {
                        if (xox) {
                            xox = 0;
                        } else {
                            xo = 0;
                        }
                    }
                }
                if (xo==1 || alive==1) {
                    goto answer;
                }
            }
        }
        cout<<"YES"<<endl;
        continue;
        answer: cout<<"NO"<<endl;
    } 
    return 0;
}