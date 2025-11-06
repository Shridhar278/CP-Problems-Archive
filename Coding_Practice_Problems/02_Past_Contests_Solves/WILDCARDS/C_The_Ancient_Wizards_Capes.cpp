#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)676767677

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// ACTUALLY PART of Contest 1056

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n, k;
        cin>>n;
        vector<int> arr;
        vector<int> strt; strt.push_back(1); int ar=1;
        vector<int> stlt; stlt.push_back(-1); int al=1;
        for (int i=0;i<n;i++) {
            cin>>k;
            arr.push_back(k);
        }
        for (int i=1;i<n;i++) {
            // cout<<"$"<<i<<" "<<arr[i-1]<<" "<<arr[i]<<" "<<strt[i-1]<<" "<<stlt[i-1]<<endl;
            if (arr[i] == arr[i-1]) {
                strt.push_back(strt[i-1]*(-1));
                stlt.push_back(stlt[i-1]*(-1));
            } else if (arr[i] == arr[i-1]-1) {
                if (strt[i-1] != 1) {
                    ar=0;
                } strt.push_back(strt[i-1]);
                if (stlt[i-1] != 1) {
                    al=0;
                } stlt.push_back(stlt[i-1]);
            } else if (arr[i] == arr[i-1]+1) {
                if (strt[i-1] != -1) {
                    ar=0;
                } strt.push_back(strt[i-1]);
                if (stlt[i-1] != -1) {
                    al=0;
                } stlt.push_back(stlt[i-1]);
            } else {
                al=0; ar=0;
                break;
            }
        }
        // one final check if the stuff works
        // SATISFY ALL THAT still can have issues... CHECK THEM
        // since only counted difference
        // THERE CAN BE FLAWS like 3-2-2 example
        // BUT 100% rectified after this...

        // OPTIMIZE this check
        // got it ONLY initial i=0 check required afterwards easily managed via algo
        int i=0; int count;
        if (ar==1) {
            count=0;
            for (int j=0;j<n;j++) {
                if (i==j) {
                    count++;
                } else if (strt[j]==1) {
                    count++;
                }
            }
            if (count!=arr[i]) {
                ar = 0;
            }
        }
        if (al==1) {
            count=0;
            for (int j=0;j<n;j++) {
                if (i==j) {
                    count++;
                } else if (stlt[j]==1) {
                    count++;
                }
            }
            if (count!=arr[i]) {
                al = 0;
            }
        }
        cout<<al+ar<<endl;
    }
    return 0;
}