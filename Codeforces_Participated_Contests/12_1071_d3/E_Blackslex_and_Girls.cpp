#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// ho gaya BEN STOKES
// still do NOT perfectly get WHY it works
// read EDITORIALs

// KIND of JUGAADU code

void solve() {
    int n, x, y; cin >> n >> x >> y;
    string s;
    cin >> s;
    vector<int> p(n);
    for (int i=0;i<n;i++) {
        cin >> p[i];
    }
    // doing the thing
    // ONE_WAY_EXCEPTION exists
    int one_way = 1;
    int sum_a=0, scope_a=0, sum_b=0, scope_b=0;
    for (int i=0;i<n;i++) {
        if (i!=0 && one_way) {
            if (s[i]!=s[i-1]) {
                one_way = 0;
            }
        }
        if (s[i]=='0') {
            sum_a+=p[i];
            sum_b+=0;
            if (p[i]%2) {
                scope_a+=p[i]/2;
            } else {
                scope_a+=(p[i]/2)-1;
            }
        } else {
            sum_b+=p[i];
            sum_a+=0;
            if (p[i]%2) {
                scope_b+=p[i]/2;
            } else {
                scope_b+=(p[i]/2)-1;
            }
        }
    }
    // more more = FAIL
    if (sum_a+sum_b>x+y) {
        cout<<"NO"<<endl;
        return;
    }
    // more less = SCOPE
    if (sum_a>x && sum_b<y) {
        if (sum_a-scope_a>x) {
            cout<<"NO"<<endl;
            return;
        }
        sum_b=sum_a-x;
        scope_a-=sum_a-x;
        sum_a=x;
    }
    if (sum_a<x && sum_b>y) {
        if (sum_b-scope_b>y) {
            cout<<"NO"<<endl;
            return;
        }
        sum_a=sum_b-x;
        scope_b-=sum_b-x;
        sum_b=x;
    }
    // less less PASS
    if (one_way==0) {
        cout<<"YES"<<endl;
        return;
    }
    // one_way edge case;
    int scope;
    if (s[0]=='0') { // A > B
        // int alpha = (x - sum_a) - (y - sum_b);
        // if (alpha>=0) {
        //     cout<<"YES"<<endl;
        //     return;
        // }
        // if (scope_a*2 >= -alpha) {
        //     cout<<"YES"<<endl;
        //     return;
        // }
        // cout<<"NO"<<endl;
        scope = x - y;
    } else { // A < B
        // int alpha = (y - sum_b) - (x - sum_a);
        // if (alpha>=0) {
        //     cout<<"YES"<<endl;
        //     return;
        // }
        // if (scope_b*2 >= -alpha) {
        //     cout<<"YES"<<endl;
        //     return;
        // }
        // cout<<"NO"<<endl;
        scope = y - x;
    }
    if (scope >= n) {
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
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