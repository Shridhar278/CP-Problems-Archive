#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// DID IT

// Question MISUNDERSTANDING
// "at any point EVEN = saaf"
// SO odd + odd anywhere happens ITS OVER its ZERO
// NOT zero at k ->ZERO just EVEN and its DONE its OVER mentality
// I'm FINE now...
// Okay FRESH MIND can do this !!!

void solve(int n, vector<int> coins) {
    vector<int> odds; vector<int> evens;
    for (int i=0;i<n;i++) {
        if (coins[i]%2) {
            odds.push_back(coins[i]);
        } else {
            evens.push_back(coins[i]);
        }
    }
    sort(odds.begin(), odds.end(), greater<int>());
    sort(evens.begin(), evens.end(), greater<int>());

    //evens as CUMMULATIVE SUM
    int m = evens.size();
    for (int i=1;i<m;i++) {
        evens[i]+=evens[i-1];
    }
    evens.insert(evens.begin(), 0);
    // the plan is done Odds will KILLthemselves so 
    // use them at the start until ONE remain..
    // other than the big ONE odds HAVE NO use
    for (int k=1;k<=n;k++) {
        if (m==n) {
            cout<<0<<" ";
            continue;
        }
        if (m==0) {
            if (k%2) {
                cout<<odds[0]<<" ";
            } else {
                cout<<0<<" ";
            }
            continue;
        }
        if (k<=m+1) {
            cout<<odds[0]+evens[k-1]<<" ";
        } else {
            if (odds.size()%2==0 && n==k) { // IF EVEN odds in the END its OVER no zig zag can help YOU
                cout<<0<<" ";
                continue;
            }
            int alpha = m - (k-m-1)%2; // smallest EVEN remove and add depending rem. odds
            if (alpha < 0) {
                alpha = 0;
            }
            cout<<odds[0]+evens[alpha]<<" ";
        }
    }
    cout<<endl;
}

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n; cin >> n;
        vector<int>coins(n);
        for (int i=0;i<n;i++) {
            cin >> coins[i];
        }
        solve(n, coins);
    }
    return 0;
}
