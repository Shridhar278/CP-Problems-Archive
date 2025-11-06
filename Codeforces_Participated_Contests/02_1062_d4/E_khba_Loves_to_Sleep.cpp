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
        int n, k, x, ele;
        cin>>n>>k>>x;
        vector<int> fnd;
        for (int i=0;i<n;i++) {
            cin >> ele; fnd.push_back(ele);
        }
        sort(fnd.begin(), fnd.end());
        if (n==1) {
            if ((x-fnd[0])>fnd[0]) {
                cout<<x<<endl;
            } else {
                cout<<0<<endl;
            }
            continue;
        }
        vector<int> diff;
        if (fnd[0]!=0) {
            diff.push_back(fnd[0]);
        } else {
            diff.push_back(fnd[0]-1);
        }
        for (int i=0;i<n-1;i++) {
            // cout<<fnd[i+1]-fnd[i]<<" ";
            diff.push_back(fnd[i+1]-fnd[i]-1);
        } diff.push_back(x-fnd[n-1]);
        while(k--) {
            int mx=diff[0], ind=0;
            for (int i=0;i<=n;i++){
                if (diff[i] > mx) {
                    mx = diff[i];
                    ind = i;
                }
            }
            // cout<<"*"<<ind<<" "<<diff[ind]<<" "<<k<<" "<<endl;
            if (ind==0) {
                cout<<fnd[0]-diff[ind]<<" ";
                diff[ind]--;
            } else if (ind==n) {
                cout<<fnd[n-1]+diff[ind]<<" ";
                diff[ind]--;
            } else {
                if (diff[ind]%2==1) {
                    cout<<fnd[ind-1]+diff[ind]/2+1<<" ";
                    diff[ind]--;
                    continue;
                }
                cout<<fnd[ind-1]+diff[ind]/2<<" ";
                if (diff[ind]==0) {
                    diff[ind]--;
                } else if (diff[ind]!=0) {
                    k--;
                    if (k==0) {
                        break;
                    }
                    cout<<fnd[ind]-diff[ind]/2<<" ";
                    diff[ind]-=2;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}