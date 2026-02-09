#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int digits(int n) {
    int digit=0;
    while (n>0) {
        if (n%2==1) {
            digit++;
        }
        n/=2;
    }
    return digit;
}

// TIME LIMIT was 3 seconds
// BRUTE search WORKED at 546ms

void solve() {
    int n; cin >> n;
    int least=digits(n);
    // No-NonSENSE check
    int facts[14]={1};
    for (int i=1;i<14;i++) {
        facts[i]=facts[i-1]*(i+1);
    }
    int num=1;
    int curr=0;
    while(true) {
        // cout<<curr<<num<<least<<endl;
        curr=0;
        int temp=num;
        int count=0;
        for (int i=0;temp>0;i++) {
            // cout<<i<<facts[i]<<temp<<curr<<endl;
            curr+=(temp%2)*facts[i];
            count+=(temp%2);
            temp/=2;
        }
        if (curr>n) {
            break;
        }
        least = min(least, digits(n-curr)+count);
        num++;
    }
    cout<<least<<endl;

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