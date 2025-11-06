#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// GO SIMPLE and check time complexity 
// before getting into BIG ALGO thought

void theOn3way(int n) {
    int arr[100][100];
    for (int i=0;i<n;i++) {
        arr[0][i] = i;
        cout<<i<<" ";
    } cout<<endl;
    int i=1, j=0;
    while (i!=n) {
        int a=0, b=0;
        int nums[10000]={0};
        while (a!=i || b!=j) {
            if (a==i) {
                nums[arr[a][b]] = 1;
                b++;
            } else {
                nums[arr[a][j]] = 1;
                a++;
            }
        }
        for (int k=0;k<i+j+1;k++) {
            if (nums[k]==0) {
                arr[i][j]=k;
                cout<<k<<" ";
                break;
            }
        }
        j++;
        if (j==n) {
            i++; j=0;
            cout<<endl;
        }
    }
    return;
}

void usingformula(int n) {
    return;
}

int32_t main() {
    fast_io();
    int n;
    cin >> n;
    theOn3way(n); // iterating
    // usingformula(n); //direct #experience
    return 0;
}