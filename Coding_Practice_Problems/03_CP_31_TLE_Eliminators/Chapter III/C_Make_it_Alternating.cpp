#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int second_modulo = 998244353;

int fact(int n) {
    if (n==0 || n==1) {
        return 1;
    } else {
        return (fact(n-1)*n)%second_modulo;
    }
}


void solve() {
    char str[200001];
    cin>>str;
    int chances=0, ways=1, guilt=0;
    char prev=str[0];
    for (char curr : str) {
        if (curr==0) {
            break;
        }
        // cout<<chances<<" "<<ways<<" "<<guilt<<" "<<prev<<" "<<curr<<endl;
        if (prev==curr) {
            guilt++;
        } else {
            if (guilt >= 2) {
                chances+=guilt-1;
                ways*=guilt;
                ways%=second_modulo;
            }
            guilt=1;
        }
        prev=curr;
    }
    if (guilt >= 2) {
        chances+=guilt-1;
        ways*=guilt;
        ways%=second_modulo;
    }
    ways*=fact(chances);
    ways%=second_modulo;
    cout<<chances<<" "<<ways<<endl;
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