#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// think bout it

int func(int n, char c) {
        if (c=='A') {
            return n+1;
        } else {
            return n*2;
        }
}



int main() {
    ll t;
    cin >> t;
    while (t--)
    {
        int n, k;
        ll query[10000];
        ll res[10000];
        cin >> n >> k;
        char str[21];

        cin >> str;
        for (int i = 0; i < n; i++) {
            cin >> query[i];
        }
        ll maxi = *max_element(query, query+k);
        ll a; int rem=k;
        for (int j=0;j<n;j++) {
            if (rem==0) {
                break;
            }
            a = 1; int md = j; ll count=1;
            while (a<=maxi) {
                a = func(a, str[md]);
                for (int o=0;o<k;o++) {
                    if (query[o] == a) {
                        rem--;
                        res[o] = count;
                    }
                }
                md--;
                if (md == -1) {
                    md = n-1;
                }
                count++;
            }
        }
        for (int i=0;i<k;i++) {
            cout << res[i] << endl;
        }
    }
    return 0;
}