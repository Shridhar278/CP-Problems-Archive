#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        char river[300001]; cin >> river;
        char c; int stage=0, pass=0, i=0, extra=0;
        int infinite=0;
        while ((c = river[i]) !='\0') {
            if (stage==0) {
                if (c=='*') {
                    stage = 1;
                } else if (c=='>') {
                    pass--;
                    stage = 2;
                }
                pass++;
            } else if (stage==1) {
                extra++;
                if (c=='<') {
                    infinite=-1;
                } else if (c=='*') {
                    infinite=-1;
                } else {
                    stage=2;
                }
            } else {
                if (c=='<') {
                    infinite=-1;
                } else if (c=='*') {
                    infinite=-1;
                }
            }
            i++;
        }
        if (infinite==-1) {
            cout<<infinite<<endl;
        } else {
            cout<<max(pass, i-pass+extra)<<endl;
        }
    }
    return 0;
}