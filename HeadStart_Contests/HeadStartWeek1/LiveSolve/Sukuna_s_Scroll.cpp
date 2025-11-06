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
    ll k;
    int power;
    while (test--) {
        cin >> k;
        power = 1;
        while (k>(pow(10, power)-pow(10, power-1))*power) {
            k-=(pow(10, power)-pow(10, power-1))*power;
            power++;
        }
        int num = (k+1) / power;
        int res = k % power;
        int ans = (int)(pow(10, power-1)-power+1+num);
        if (power==1) {
            ans-=2;
        }
        while ((int)log10(ans)<res) {
            // cout<<ans<<endl;
            ans/=10;
        }
        ans = ans%10;
        cout<<ans<<endl;
    }
    return 0;
}