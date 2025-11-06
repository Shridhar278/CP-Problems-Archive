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
    int n, min=0;
    cin>>n;
    int arr[100][100];
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (i==0) {
                arr[i][j] = j;
            } else {
                min=0;
                for (int a=0;a<j;a++) {
                    if (arr[i][a] < min) {
                        min=arr[i][a];
                    }
                }
                for (int b=0;b<i;b++) {
                    if (arr[b][j] == min) {
                        min++;
                    }
                }
                arr[i][j]=min;
            }
            
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}