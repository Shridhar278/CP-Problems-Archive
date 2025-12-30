#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n; cin >> n;
    int n1=1, n2=1;
    int temp=0;
    vector<int>rest;
    int prod = n;
    for (int i=2;i<=sqrt(n);) {
        if (n%i==0) {
            n/=i;
            temp++;
        } else {
            rest.push_back((int)pow(i, temp));
            temp=0;
            i++;
        }
    }
    sort(rest.begin(), rest.end());
    int closest=1, curr;
    for (int i=0;i<(1<<rest.size());i++) {
        curr = 1;
        if ()
    }
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}