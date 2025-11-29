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
        int n; cin >> n;
        vector<int> arr(2*n);
        for (int i=0;i<2*n;i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        int odds=0, even_4k2=0, even_4k0=0;
        int count=1, last=arr[0];
        int diff=1, breaks4k0=0, breaks4k2=0;
        for (int i=1;i<2*n;i++) {
            // cout<<arr[i]<<" "<<count<<" "<<last<<" "<<breaks4k0<<" "<<breaks4k2<<" "<<diff<<endl;
            if (arr[i]==last) {
                count++;
            } else {
                if (count%2==1) {
                    odds+=count;
                } else if (count%4==0) {
                    even_4k0+=count;
                    breaks4k0++;
                } else {
                    even_4k2+=count;
                    breaks4k2++;
                }
                diff++;
                count=1;
                last = arr[i];
            }
        }
        // cout<<arr[2*n-1]<<" "<<count<<" "<<last<<" "<<breaks4k0<<" "<<breaks4k2<<" "<<diff<<endl;
        if (count%2==1) {
            odds+=count;
        } else if (count%4==0) {
            even_4k0+=count;
            breaks4k0++;
        } else {
            even_4k2+=count;
            breaks4k2++;
        }
        // cout<<arr[2*n-1]<<" "<<count<<" "<<last<<" "<<breaks4k0<<" "<<breaks4k2<<" "<<diff<<endl;
        if (breaks4k0%2==0) {
            cout<<diff+breaks4k0+breaks4k2<<endl;
        } else {
            if (odds>=2) {
                cout<<diff+breaks4k0+breaks4k2<<endl;
            } else {
                cout<<diff+breaks4k0+breaks4k2-2<<endl;
            }
        }
    }
    return 0;
}