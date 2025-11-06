#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF (int)1e9+7

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        ll a, b;
        cin >> a >> b;
        int big = (int)log2(a);
        int bs = (int)log2(b);
        if (a==b) {
            cout<<0<<endl;
            continue;
        } else if (bs > big) {
            cout<<-1<<endl;
            continue;
        }
        vector<ll>sols;
        for (int i=0;i<=big;i++) {
            if (a%2 != b%2) {
                if (b%2==0) {
                    sols.push_back(pow(2, i));
                } else {
                    sols.push_back(pow(2, i));
                }
            }
            a /= 2; b /= 2;
        }
        cout<<sols.size()<<endl;
        for (int i=0;i<sols.size();i++) {
            cout<<sols[i]<<endl;
        }
    }
    return 0;
}