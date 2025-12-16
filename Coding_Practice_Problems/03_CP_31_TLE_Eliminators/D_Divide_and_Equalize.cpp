#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve(int n, vector<int>arr) {
    map<int, int> facts;
    int temp, i;
    for (int x : arr) {
        temp=x; i=2;
        while(temp!=1) {
            // cout<<temp<<" "<<i<<endl;
            if (i > sqrt(temp)) {
                // cout<<"&";
                facts[temp]++;
                break;
            }
            if (temp%i==0) {
                temp/=i;
                facts[i]++;
                i--;
            }
            i++;
        }
    }
    for (auto it = facts.begin(); it != facts.end(); ++it) {
        // cout << it->first << " -> " << it->second << '\n';
        if ((it->second)%n!=0) {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (int i=0;i<n;i++) {
            cin>>arr[i];
        }
        solve(n, arr);
    }
    return 0;
}