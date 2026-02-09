#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// ACCEPTED

void solve() {
    int n; cin >> n;
    vector<int> monsters(n);
    for (int i=0;i<n;i++) {
        cin >> monsters[i];
    }
    sort(monsters.begin(), monsters.end());
    int i=0,j=n-1;
    int count=0;
    int combo=0;
    while(i<j) {
        // cout<<combo<<count<<monsters[i]<<monsters[j]<<endl;
        combo+=monsters[i];
        count+=monsters[i];
        if (combo >= monsters[j]) {
            count++;
            count-=(combo-monsters[j]);
            monsters[i]=combo-monsters[j];
            combo=0;
            j--;
            i--;
        }
        i++;
    }
    // cout<<combo<<count<<monsters[i]<<monsters[j]<<endl;
    if (monsters[i]>1) {
        int y=(monsters[i]-combo)/2;
        count+=y+1;
        count+=(monsters[i]-combo)%2;
    } else {
        count+=monsters[i];
    }
    cout<<count<<endl;
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