#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// cutting THE CRAP post EDITORIAL
// PS: its very optimized byee

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    for (int i=0;i<n;i++) {
        cin >> b[i];
    }
    for (int i=0;i<n;i++) {
        cin >> c[i];
    }
    int chances1=0, chances2=0;
    for (int i=0;i<n;i++) { // the shift in a
        int fail=0;
        for (int j=0;j<n;j++) {
            if (a[(j+i)%n]>=b[j]) {
                fail=1;
                break;
            }
        }
        if (!fail) {
            chances1++;
        }
    }
    for (int i=0;i<n;i++) { // the shift in c
        int fail=0;
        for (int j=0;j<n;j++) {
            if (c[(j+i)%n]<=b[j]) {
                fail=1;
                break;
            }
        }
        if (!fail) {
            chances2++;
        }
    }
    cout<<chances1*chances2*n<<endl;
    // times no. of elements in b cuz YEAH same but repeat as i, j, k differ
    // ex. for n=3:
    // 1 2 1
    // 2 3 2
    // 3 0 3
    // cycles of 3

    //post EDITORIAL
    // vector<int> a(n);
    // vector<int> b(n);
    // vector<int> c(n);
    // for (int i=0;i<n;i++) cin >> a[i];
    // for (int i=0;i<n;i++) cin >> b[i];
    // for (int i=0;i<n;i++) cin >> c[i];
    // kinda looks neat
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