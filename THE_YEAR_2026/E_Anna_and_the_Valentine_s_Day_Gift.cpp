#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int zero(int x) {
    if (x%10!=0) {
        return 0;
    } else {
        return 1 + zero(x/10);
    }
}

int digit(int x) {
    if (x==0) {
        return 0;
    } else {
        return 1+digit(x/10);
    }
}

void solve() {
    int n, m; cin >> n >> m;
    int num;
    vector<int> zeroes(n);
    int digits = 0;
    for (int i=0;i<n;i++) {
        cin >> num;
        zeroes[i] = zero(num);
        digits+=digit(num);
    }
    sort(zeroes.begin(), zeroes.end(), greater<int>());
    int optimal = digits;
    // only even-indexed is SWATTED : SAVE the BEST
    for (int i=0;i<n;i+=2) {
        optimal-=zeroes[i];
    }
    // cout<<optimal<<endl;
    if (optimal >= m+1) { // >= 10^m means m+1 digits :)
        cout<<"Sasha"<<endl;
    } else {
        cout<<"Anna"<<endl;
    }
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