#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Perfecto : O(n) BABY YEAH

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n, inte;
        vector<int> odds;
        vector<int> sms;
        cin >> n;
        for (int i=0;i<n;i++) {
            cin >> inte;
            if (i==0) {
                if (inte%2==0) {
                    odds.push_back(0);
                } else {
                    odds.push_back(1);
                }
                sms.push_back(inte);
            } else {
                sms.push_back(sms.back()+inte);
                if (inte%2==0) {
                    odds.push_back(odds.back());
                } else {
                    odds.push_back(odds.back()+1);
                }
            }
        }
        int count;
        for (int i=0; i<n; i++) {
            count=0;
            int x = odds[i]/3, y = odds[i]%3;
            count += x;
            if (i!=0) {
                if (y==1) {
                    count++;
                }
            }
            cout<<sms[i]-count<<" ";
        }
        cout<<endl;
    }
    return 0;
}