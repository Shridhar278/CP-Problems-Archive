#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// using f-ing sort directly in c++

int main() {
    int test;
    cin >> test;
    while (test--) {
        int n, num=0;
        cin >> n;
        ll news, sum=0;
        ll odds[n];
        for (int i = 0; i < n; i++) {
            cin >> news;
            if (news % 2 == 0) {
                sum += news;
            } else {
                odds[num] = news;
                num++;
            }
        }
        if (num == 0) {
            cout << 0 << endl;
            continue;
        }
        sort(odds, odds + num, greater<ll>());
        if (num % 2 == 1) {
            num++;
        }
        for (int i = 0; i < num/2; i++) {
            sum += odds[i];
        }
        cout<< sum << endl;
    }
}