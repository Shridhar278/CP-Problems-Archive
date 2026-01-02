#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// NOT OPTIMAL
// screw it REST for OFFICIAL codeforces ROUND

void solve() {
    int n, k; cin >> n >> k;
    vector<int>parts;
    int a=n;
    for (int i=0;a>0;i++) {
        if (a%2) {
            parts.push_back(1<<i);
        }
        a/=2;
    }
    int x = parts.size();
    if (k > n || x > k) {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    for (int i=0, j=0;j<k-x;) {
        // cout<<parts[i]<<" "<<j<<" "<<x<<endl;
        if (parts[i]%2==0) {
            parts.push_back(parts[i]/2);
            parts.push_back(parts[i]/2);
            parts.erase(parts.begin()+i);
            j++;
            continue;
        }
        i++;
    }
    sort(parts.begin(), parts.end());
    for (int i=0;i<parts.size();i++) {
        cout<<parts[i]<<" ";
    }
    cout<<endl;
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}