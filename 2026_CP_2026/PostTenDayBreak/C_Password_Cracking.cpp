#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// ACCEPTED : Shridhar278

void solve() {
    int n; cin >> n;
    int ans;
    cout<<"? 0"<<flush<<endl;
    cin>>ans;
    if (ans==0) {
        cout<<"! ";
        for (int i=0;i<n;i++) {
            cout<<"1";
        }
        cout<<flush<<endl;
        return;
    }
    string t="0";
    int curr=1, count=0, stage=0, x=1;
    while(curr<n) {
        if (stage==0) {
            if (count) {
                t.back()='1';
            } else {
                t+='0';
            }
        } else {
            if (count) {
                t.front()='1';
            } else {
                t='0'+t;
            }
        }
        if (x==2*n) {
            break;
        }
        cout<<"? "<<t<<flush<<endl;
        cin>>ans;
        x++;
        if (ans==1) {
            count=0;
            curr++;
            continue;
        }
        count++;
        if (count==2) {
            stage=1;
            count=0;
            t.pop_back();
        }
    }
    cout<<"! "<<t<<flush<<endl;
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