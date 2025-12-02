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
    int pos=50;
    int count=0;
    char input[10];
    int prev=50;
    while (true) {
        prev=pos;
        cin >> input;
        if (input[0]=='0') {
            break;
        }
        else if (input[0] == 'R') {
            pos += atoi(input+1);
        } else {
            pos -= atoi(input+1);
        }
        // repeats
        // Greatest Integer Function %100 basically
        int x = pos/100, y = prev/100;
        if (pos < 0 && pos%100!=0) {
            x -= 1;
        }
        if (prev < 0 && prev%100!=0) {
            y -= 1;
        }
        count+=abs(x-y);
        // exactly one is 0 mod 100
        // 50->0 case
        if ((pos%100==0) && (prev%100!=0) && (pos<=prev)) {
            count++;
        }
        // 0->-50 case
        if ((pos%100!=0) && (prev%100==0) && (pos<=prev)) {
            count--;
        }
        // cout<<pos<<"$"<<count<<endl;
    }
    cout<<count<<endl;
    return 0;
}