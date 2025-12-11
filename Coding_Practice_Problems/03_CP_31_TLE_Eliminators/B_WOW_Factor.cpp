#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// First SUBMISSION does IT submitted once and submitted the PERFECTO CODE

int32_t main() {
    fast_io();
    char str[(int)1e6+1];
    int wow=0;
    cin >> str;
    int reset=0;
    int o = 0;
    int carry=0;
    int vv = 0, v=0;
    for (int i=0;i<strlen(str);i++) {
        if (reset) {
            if (str[i]=='v') {
                v++;
            } else {
                // for first element REDUNDANT since vv=0
                carry += vv*o;
                wow += v*carry;

                vv += v;
                v=0;
                reset=0;
                o=1;
            }
        } else {
            if (str[i]=='v') {
                reset=1;
            } else {
                o++;
                continue;
            }
        }
    }
    if (v!=0) {
        carry += vv*o;
        wow += v*carry;
    }
    cout<<wow<<endl;
    return 0;
}