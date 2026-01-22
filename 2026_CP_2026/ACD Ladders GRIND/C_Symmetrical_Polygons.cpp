#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// ACCEPTED ben stokes

void solve() {
    int n; cin >> n;
    map<int, int> sides;
    int side;
    int the_best=0;
    int single=0;
    int count=0;
    vector<int> odds;
    for (int i=0;i<n;i++) {
        cin >> side;
        sides[side]++;
    }
    for (auto it: sides) {
        the_best+=it.first*((it.second/2)*2);
        count+=((it.second/2)*2);
        if (it.second%2) {
            odds.push_back(it.first);
        }
    }
    sort(odds.begin(), odds.end(), greater<>());
    // singular smaller check;
    if (count==0) {
        cout<<0<<endl;
        return;
    }
    for (int i=0;i<(int)odds.size();i++) {
        if ((double(odds[i]))/2<the_best/2) {
            single=odds[i];
            break;
        }
    }
    for (int i=1;i<(int)odds.size();i++) {
        if ((double(odds[i-1]-odds[i]))/2<the_best/2) {
            if (odds[i-1]+odds[i] >= single) {
                count++;
                the_best+=odds[i-1]+odds[i];
                break;
            } else {
                if (single) {
                    count++;
                    the_best+=single;
                }
                break;
            }
        }
    }
    if (count%2==0) {
        if (single) {
            count++;
            the_best+=single;
        }
    }
    if (count<3) {
        cout<<0<<endl;
        return;
    }
    cout<<the_best<<endl;
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