#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n, res, ttl=0;
        cin >> n;
        while (n >= 3) {
            res = n % 3;
            ttl += n/3;
            n = n/3 + res;
        }
        cout << ttl << endl;
    }
    return 0;
}