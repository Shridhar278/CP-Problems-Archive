#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double

#define mod9 998244353

ld calc(ld n, ld r) {
    return (n*(n+1)/2 - r*(r+1)/2)/(n-r);
}

void solve() {
    int n; cin >> n;
    vector<ld> a(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    vector<ld> ans(n, (ld)0);
    ans[n-1]=calc(a[n-1], 0);
    for (int i=n-2;i>=0;i--) {
        ld x = floor(ans[i+1]);
        if (x<a[i]) {
            ans[i]+=((ld)1 -(x/a[i]))*calc(a[i], x);
            ans[i]+=(x/a[i])*ans[i+1];
        } else {
            ans[i]=ans[i+1];
        }
    }
    cout<<fixed<<setprecision(10)<<ans[0]<<endl;
}

int32_t main() {
    solve();
    return 0;
}