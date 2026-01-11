#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    vector<int> gcds={arr[0]};
    int st=0;
    int curr=arr[0];
    int high=curr, wide=1;
    int last_high=1, last_wide=1;
    int i=1;
    while (i!=n) {
        curr = __gcd(curr, arr[i]);
        // cout<<gcds.back()<<" "<<curr<<" "<<i<<" "<<high<<" "<<last_high<<" "<<wide<<" "<<last_wide<<endl;
        if (curr<gcds.back() or __gcd(arr[i-1], arr[i])>gcds.back()) {
            int x;
            if (__gcd(arr[i-1], arr[i])>gcds.back()) {
                x=__gcd(arr[i-1], arr[i]);
            } else {
                x=arr[i];
                x=curr;
            }
            int forward=i-1;
            int best=x;
            for (int j=0;j<(int)gcds.size();j++) {
                // cout<<best<<" "<<forward<<endl;
                if (__gcd(arr[j], x)<=best) {
                    best=curr;
                    forward=st+j;
                }
                if (__gcd(gcds[j], x)>best) {
                    best=__gcd(arr[j], x);
                    forward=st+j-1;
                } 
            }
            // cout<<best<<" "<<forward<<endl;
            st=forward+1;
            i=st;
            if (i==n) {
                break;
            }
            gcds.clear();
            curr=arr[st];
            if (curr>high) {
                wide=1;
                high=curr;
            }
        } else {
            if (curr==gcds.back()) {
                if (curr==high) {
                    wide++;
                    last_high=high;
                    last_wide=wide;
                }
            }
        }
        gcds.push_back(curr);
        i++;
    }
    if (last_wide==1) {
        cout<<1<<" "<<n<<endl;
        return;
    }
    cout<<last_high<<" "<<last_wide<<endl;
}

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}