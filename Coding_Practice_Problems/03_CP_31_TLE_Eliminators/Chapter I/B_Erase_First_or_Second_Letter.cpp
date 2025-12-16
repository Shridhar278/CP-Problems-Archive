#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// going from back as string of shape e'y GAP e'x e'x+1 e'x+2 ...... exist in that order
// logic would be go by string size of this e'x.... finding diff. elements as header e'y for them
// got it so 26(check each letter)*n(size) complexity

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n; cin >> n;
        char c;
        int alpha[26] = {0};
        vector<int> order;
        for (int i=0;i<n;i++) {
            cin >> c;
            alpha[c-97]++;
            order.push_back(c-97);
        }
        int ttl = 0; // the total head + size counts = ANSWER
        int alive;
        for (int i=n;i>0;i--) {
            if (i!=n) {
                alpha[order.back()]--;
                order.pop_back();
            }
            alive=0;
            for (int j=0;j<26;j++) {
                if (alpha[j] > 0) {
                    alive++;
                }
            }
            ttl+=alive;
        }
        cout<<ttl<<endl;
    }
    return 0;
}